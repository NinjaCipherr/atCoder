import requests
import os
import subprocess
from time import sleep

# Đường dẫn API
api_path = "https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions?user="

# Nhập userID và thời gian bắt đầu
userID = "pvThein"
from_second = 0  # Thay đổi giá trị này nếu cần


# Hàm lấy dữ liệu submissions của người dùng
def getSubmissionData(userID, from_second):
    api_url = f"{api_path}{userID}&from_second={from_second}"
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


# Chức năng để lấy mã nguồn và lưu vào tệp
def save_submission_code(submissions):
    root = "submissions/"
    add_cnt = 0  # Đếm số tệp đã thêm

    for sub in submissions:
        # Lấy thông tin từ submission
        problem_num = sub["problem_id"][-1]
        if problem_num.isdigit():
            problem_num = chr(int(problem_num) + ord("a") - 1)

        path = root + sub["contest_id"] + "/" + problem_num
        if "C++" in sub["language"]:
            path += ".cpp"
        elif "Python" in sub["language"]:
            path += ".py"

        # Nếu tệp đã tồn tại thì bỏ qua
        if os.path.isfile(path):
            continue

        # Tạo thư mục nếu chưa tồn tại
        os.makedirs(os.path.dirname(path), exist_ok=True)

        # Truy cập trang submission
        sub_url = (
            "https://atcoder.jp/contests/"
            + sub["contest_id"]
            + "/submissions/"
            + str(sub["id"])
        )
        code_response = requests.get(sub_url)

        # Lấy mã nguồn từ trang
        # (Phần này có thể cần được điều chỉnh tùy thuộc vào cấu trúc HTML của trang)
        # Giả sử mã nguồn nằm trong một phần tử cụ thể
        code_text = "Mã nguồn ở đây"  # Thay thế bằng phương pháp lấy mã nguồn thực tế

        # Ghi mã nguồn vào tệp
        with open(path, "w") as f:
            f.write(code_text)

        # Nếu là C++, định dạng lại mã nguồn
        if "C++" in sub["language"]:
            subprocess.call(["clang-format", "-i", "-style=file", path])

        add_cnt += 1
        sleep(3)  # Nghỉ 3 giây giữa các yêu cầu

    return add_cnt


# Lưu mã nguồn
add_cnt = save_submission_code(submissions)

# Kiểm tra số tệp đã thêm và đẩy lên GitHub
if add_cnt > 0:
    print(f"Finished process, added {add_cnt} files")
    # Đưa mã lên GitHub (thực hiện các lệnh git tương tự như trước)
else:
    print("No new submissions to add.")
