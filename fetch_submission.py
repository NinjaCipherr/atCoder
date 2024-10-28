import requests
import os
import subprocess
from bs4 import BeautifulSoup
from time import sleep
import html
import datetime
import git  # Thêm thư viện git để thực hiện các thao tác Git

# Đường dẫn API
api_path = "https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions?user={user_id}&from_second={unix_second}"

# Nhập userID và thời gian bắt đầu
userID = "pvThein"
from_second = 0  # Thay đổi giá trị này nếu cần


# Hàm lấy dữ liệu submissions của người dùng
def getSubmissionData(userID, from_second):
    api_url = api_path.format(user_id=userID, unix_second=from_second)
    response = requests.get(api_url)

    if response.status_code != 200:
        print(
            f"Error fetching submission data for user '{userID}': {response.status_code} - {response.text}"
        )
        return []

    try:
        jsonData = response.json()
        if not jsonData:
            print(f"No submissions found for user '{userID}'.")
    except ValueError as e:
        print("JSON Decode Error:", e)
        return []

    return jsonData


# Lấy submissions
submissions = getSubmissionData(userID, from_second)


# Hàm thu thập các submission "AC" mới nhất theo contest
def collectNewestAcceptedSubmissions(submissions):
    sortedData = sorted(submissions, key=lambda x: x["id"])  # Sắp xếp theo ID
    submits = {}  # Tạo dictionary để lưu submission mới nhất cho từng problem

    for data in sortedData:
        if data["result"] != "AC":  # Chỉ lấy submission có kết quả "AC"
            continue

        problem_id = data["problem_id"]
        # Nếu chưa có submission nào cho problem này hoặc submission này mới hơn
        if problem_id not in submits or submits[problem_id]["id"] < data["id"]:
            submits[problem_id] = data  # Cập nhật submission mới nhất cho problem

    result = {}  # Tạo dictionary để nhóm theo contest
    for sub in submits.values():
        contest_id = sub["contest_id"]
        if contest_id not in result:
            result[contest_id] = []  # Tạo danh sách mới nếu contest chưa tồn tại
        result[contest_id].append(sub)  # Thêm submission vào danh sách của contest

    return result


# Gọi hàm để lấy các submission mới nhất với kết quả "AC"
newestSubmits = collectNewestAcceptedSubmissions(submissions)


# Hàm để lấy mã nguồn từ submission
def get_submission_code(submission_id, contest_id):
    sub_url = f"https://atcoder.jp/contests/{contest_id}/submissions/{submission_id}"

    response = requests.get(sub_url)

    if response.status_code != 200:
        print(
            f"Error fetching submission code for ID {submission_id}: {response.status_code}"
        )
        return None

    soup = BeautifulSoup(response.text, "html.parser")

    code_element = soup.find("pre", id="submission-code")

    if code_element:
        code_text = html.unescape(code_element.get_text())
        return code_text
    else:
        print(
            f"Code not found in submission ID {submission_id}. Page content:\n{soup.prettify()}"
        )
        return None


# Hàm để lưu mã nguồn vào tệp
def save_submission_code(newestSubmits):
    root = "submissions/"
    add_cnt = 0

    for contest_id, submissions in newestSubmits.items():
        for sub in submissions:
            submission_id = sub["id"]
            code = get_submission_code(submission_id, contest_id)

            if code is None:
                continue

            problem_num = sub["problem_id"][-1]
            if problem_num.isdigit():
                problem_num = chr(int(problem_num) + ord("a") - 1)

            path = os.path.join(root, contest_id, problem_num)
            if "C++" in sub["language"]:
                path += ".cpp"
            elif "Python" in sub["language"]:
                path += ".py"

            if os.path.isfile(path):
                print(f"File {path} already exists. Skipping.")
                continue

            os.makedirs(os.path.dirname(path), exist_ok=True)

            with open(path, "w") as f:
                f.write(code)

            if "C++" in sub["language"]:
                subprocess.call(["clang-format", "-i", "-style=file", path])

            add_cnt += 1
            sleep(3)

    return add_cnt


# Lưu mã nguồn
add_cnt = save_submission_code(newestSubmits)

# Kiểm tra số tệp đã thêm và upload lên GitHub
if add_cnt > 0:
    print(f"Finished process, added {add_cnt} files")

    # Tự động upload lên GitHub
    dt_now = datetime.datetime.now()
    repo_path = (
        "/home/green-code/atcoder_submissions"  # Đường dẫn đến thư mục chứa repo local
    )

    try:
        # Khởi tạo repo từ đường dẫn local, không phải URL
        repo = git.Repo(repo_path)
        repo.git.add("submissions/*")
        repo.git.commit(
            message="add submission: " + dt_now.strftime("%Y/%m/%d %H:%M:%S")
        )
        repo.git.push("origin", "main")
        print("Successfully pushed to GitHub.")
    except Exception as e:
        print(f"Error during Git operations: {e}")
else:
    print("No new submissions to add.")
