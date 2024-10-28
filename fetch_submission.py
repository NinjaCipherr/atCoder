#!/usr/bin/env python
# coding: utf-8

import requests
import json
import os
import re
import html
from selenium import webdriver
from time import sleep
import subprocess
import git
import datetime

# Thông tin người dùng và đường dẫn API
userID = "pvThein"
api_path = "https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions?user="
from_second = 0  # Thời điểm bắt đầu lấy bài nộp (0 = từ đầu)


# Hàm lấy dữ liệu bài nộp từ API v3
def getSubmissionData(userID, from_second):
    api_url = f"{api_path}{userID}&from_second={from_second}"
    headers = {"User-Agent": "Mozilla/5.0"}
    response = requests.get(api_url, headers=headers)

    # Kiểm tra mã trạng thái và nội dung phản hồi
    print("Status Code:", response.status_code)
    print("Response Text:", response.text[:500])  # In một phần nội dung để kiểm tra

    # Xử lý phản hồi nếu yêu cầu thành công
    if response.status_code == 200:
        try:
            jsonData = response.json()
            return jsonData
        except ValueError as e:
            print("JSON Decode Error:", e)
            return []
    else:
        print(f"Error: Unable to fetch data. Status code: {response.status_code}")
        return []


# Lấy dữ liệu bài nộp
submissions = getSubmissionData(userID, from_second)

# Kiểm tra nếu không có dữ liệu
if not submissions:
    print("No submissions found or error fetching data.")
    exit()


# Hàm xử lý các bài nộp thành công mới nhất
def collectNewestAcceptedSubmissions(submissions):
    sortedData = sorted(submissions, key=lambda x: x["id"])
    submits = {}  # Lưu bài nộp thành công mới nhất cho từng bài toán
    for data in sortedData:
        if data["result"] != "AC":  # Chỉ lấy các bài nộp đạt AC
            continue
        submits[data["problem_id"]] = data

    # Gom nhóm bài nộp theo từng cuộc thi
    result = {}
    for sub in submits.values():
        if sub["contest_id"] not in result:
            result[sub["contest_id"]] = []
        result[sub["contest_id"]].append(sub)
    return result


# Thu thập bài nộp mới nhất đã được chấp nhận
newestSubmits = collectNewestAcceptedSubmissions(submissions)

# Tạo thư mục lưu trữ các bài nộp theo từng cuộc thi và bài toán
root = "submissions/"
for contestName in newestSubmits:
    path = root + contestName
    os.makedirs(path, exist_ok=True)

# Cài đặt trình duyệt để lấy mã nguồn bài nộp
driver = webdriver.Chrome()
add_cnt = 0

# Lấy và lưu mã nguồn của từng bài nộp
for submissions in newestSubmits.values():
    for sub in submissions:
        problem_num = sub["problem_id"][-1]
        if problem_num.isdigit():
            problem_num = chr(int(problem_num) + ord("a") - 1)

        path = root + sub["contest_id"] + "/" + problem_num
        if "C++" in sub["language"]:
            path += ".cpp"
        elif "Python" in sub["language"]:
            path += ".py"

        if os.path.isfile(path):  # Bỏ qua nếu file đã tồn tại
            continue

        sub_url = (
            "https://atcoder.jp/contests/"
            + sub["contest_id"]
            + "/submissions/"
            + str(sub["id"])
        )
        driver.get(sub_url)

        # Lấy mã nguồn từ phần tử HTML
        code = driver.find_element("id", "submission-code")
        inner_html = code.get_attribute("innerHTML")
        list_items = re.findall(r"<li[^>]*>.*?</li>", inner_html)
        lines = []
        for li in list_items:
            line1 = re.sub(r"<[^>]+>", "", li)
            line2 = re.sub(r"&nbsp;", "", line1)
            line3 = html.unescape(line2)
            lines.append(line3 + "\n")
        code_text = "".join(lines)

        # Lưu mã nguồn vào file
        with open(path, "w") as f:
            f.write(code_text)

        if "C++" in sub["language"]:
            subprocess.call(["clang-format", "-i", "-style=file", path])

        add_cnt += 1
        sleep(3)  # Tạm dừng 3 giây giữa các lần truy cập

driver.quit()

# Đẩy mã nguồn lên GitHub nếu có thay đổi
if add_cnt == 0:
    print("No added submissions, end process")
else:
    dt_now = datetime.datetime.now()
    repo_path = os.getcwd()

    # Kiểm tra nếu đây là thư mục Git repository hợp lệ
    if not os.path.isdir(os.path.join(repo_path, ".git")):
        print("Error: Không tìm thấy Git repository tại đường dẫn đã chỉ định.")
    else:
        repo = git.Repo(repo_path)
        repo.git.add("submissions/*")
        repo.git.commit(
            message="add submission: " + dt_now.strftime("%Y/%m/%d %H:%M:%S")
        )
        repo.git.push("origin", "main")
        print(f"Finished process, added {add_cnt} files")
