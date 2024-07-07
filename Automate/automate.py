from data_scrapper import scrapper, scrape_data

import re
import os


def extract_from_input(content: str):
    urlPattern = r"https://leetcode.com/problems/[\w-]+/description/"
    commentPattern = r"/\*([^*]|[\r\n]|(\*([^/]|[\r\n])))*\*/"

    urlMatch = re.search(urlPattern, content, re.MULTILINE)
    url = urlMatch.group(0) if urlMatch else None

    commentMatch = re.search(commentPattern, content, re.MULTILINE)
    comment = commentMatch.group(0) if commentMatch else None

    index = commentMatch.end() if commentMatch else 0
    code = content[index:].rstrip()

    return url, comment, code


with open("input.txt", "r") as f:
    content = f.read()

url, comment, code = extract_from_input(content)
questionId, title, question, difficulty, example, constraint = scrape_data(url)

# Ask a prompt to the user to confirm the scraped questionId and title of the question. If the user press <enter> then proceed else exit the program
print(f"Question ID: {questionId}\nTitle: {title}")
if input("Do you want to proceed? (y/n): ") != "y":
    if input("Do you want to change the question ID? (y/n): ") == "y":
        questionId = input("Enter the question ID: ")
    else:
        exit()
        
fileName = f"../Solutions_CPP/{questionId}_{title.replace(' ', '_')}.cpp"

with open(fileName, "w") as f:
    f.write(f"// {questionId} : {title}\n\n")
    f.write(f"/*\n{question}\n*/\n\n")
    f.write(f"/*\n{example}\n*/\n\n")
    f.write(f"/*\n{constraint}\n*/\n\n")
    f.write(comment)
    f.write(code)


def update_readme(questionId, title, url, fileName):
    readme_path = "../README.md"

    if not os.path.exists(readme_path):
        with open(readme_path, "w") as f:
            f.write("# LeetCode\n\n")
            f.write("| # | Title | Solution |\n")
            f.write("|---| ----- | -------- |\n")

    with open(readme_path, "r") as f:
        lines = f.readlines()

    table_start = lines.index("| # | Title | Solution |\n")
    insert_index = table_start + 2
    while (
        insert_index < len(lines)
        and lines[insert_index].split("|")[1] < f"{int(questionId):04d}"
    ):
        insert_index += 1

    new_entry = (
        f"|{int(questionId):04d}|[{title}]({url})|[cpp](Solutions_CPP/{fileName})|\n"
    )
    lines.insert(insert_index, new_entry)

    with open(readme_path, "w") as f:
        f.writelines(lines)

    print(f"Updated {readme_path}")


update_readme(questionId, title, url, fileName)
