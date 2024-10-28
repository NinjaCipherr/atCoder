import requests
import os
import subprocess
from bs4 import BeautifulSoup
from time import sleep

# Đường dẫn API
api_path = "https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions?user={user_id}&from_second={unix_second}"

# Nhập userID và thời gian bắt đầu
userID = "pvThein"
from_second = 0  # Thay đổi giá trị này nếu cần


# Hàm lấy dữ liệu submissions của người dùng
def getSubmissionData(userID, from_second):
    api_url = api_path.format(user_id=userID, unix_second=from_second)
    response = requests.get(api_url)

    # Kiểm tra mã trạng thái của phản hồi
    if response.status_code != 200:
        print(
            f"Error fetching submission data for user '{userID}': {response.status_code} - {response.text}"
        )
        return []

    try:
        jsonData = response.json()
        if not jsonData:  # Nếu không có dữ liệu
            print(f"No submissions found for user '{userID}'.")
    except ValueError as e:
        print("JSON Decode Error:", e)
        return []

    return jsonData


# Lấy submissions
submissions = getSubmissionData(userID, from_second)


# Hàm để lấy mã nguồn từ submission
def get_submission_code(submission_id):
    # Tạo URL cho submission cụ thể
    sub_url = f"https://atcoder.jp/contests/abc377/submissions/{submission_id}"

    # Gửi yêu cầu GET để lấy trang submission
    response = requests.get(sub_url)

    if response.status_code != 200:
        print(
            f"Error fetching submission code for ID {submission_id}: {response.status_code}"
        )
        return None

    # Phân tích trang HTML
    soup = BeautifulSoup(response.text, "html.parser")

    # Tìm phần tử chứa mã nguồn
    code_element = soup.find("pre")  # Có thể điều chỉnh nếu cấu trúc HTML khác

    if code_element:
        code_text = code_element.get_text()
        return code_text
    else:
        print(f"Code not found in submission ID {submission_id}.")
        return None


# Hàm để lưu mã nguồn vào tệp
def save_submission_code(submissions):
    root = "submissions/"
    add_cnt = 0  # Đếm số tệp đã thêm

    for sub in submissions:
        submission_id = sub["id"]
        code = get_submission_code(submission_id)

        if code is None:
            continue  # Bỏ qua nếu không lấy được mã nguồn

        # Lấy thông tin từ submission
        problem_num = sub["problem_id"][-1]
        if problem_num.isdigit():
            problem_num = chr(int(problem_num) + ord("a") - 1)

        path = os.path.join(root, sub["contest_id"], problem_num)
        if "C++" in sub["language"]:
            path += ".cpp"
        elif "Python" in sub["language"]:
            path += ".py"

        # Nếu tệp đã tồn tại thì bỏ qua
        if os.path.isfile(path):
            print(f"File {path} already exists. Skipping.")
            continue

        # Tạo thư mục nếu chưa tồn tại
        os.makedirs(os.path.dirname(path), exist_ok=True)

        # Ghi mã nguồn vào tệp
        with open(path, "w") as f:
            f.write(code)

        # Nếu là C++, định dạng lại mã nguồn
        if "C++" in sub["language"]:
            subprocess.call(["clang-format", "-i", "-style=file", path])

        add_cnt += 1
        sleep(3)  # Nghỉ 3 giây giữa các yêu cầu

    return add_cnt


# Lưu mã nguồn
add_cnt = save_submission_code(submissions)

# Kiểm tra số tệp đã thêm
if add_cnt > 0:
    print(f"Finished process, added {add_cnt} files")
else:
    print("No new submissions to add.")
