import requests
from bs4 import BeautifulSoup as bs

# Data Format given here : https://stackoverflow.com/a/56610178/21152769
def scrapper(titleSlug : str):
    data = {
    "operationName":"questionData",
    "variables":{"titleSlug":titleSlug},
    "query":"query questionData($titleSlug: String!) \
            {\n  question(titleSlug: $titleSlug)     \
                {\n questionId\n questionFrontendId\n boundTopicId\n title\n titleSlug\n content\n translatedTitle\n translatedContent\n isPaidOnly\n difficulty\n likes\n dislikes\n isLiked\n similarQuestions\n contributors {\n   username\n   profileUrl\n   avatarUrl\n   __typename\n }  \
                 \n langToValidPlayground\n topicTags {\n   name\n   slug\n   translatedName\n   __typename\n }\n companyTagStats\n codeSnippets {\n   lang\n   langSlug\n   code\n   __typename\n }\n stats\n hints\n solution {\n   id\n   canSeeDetail\n   __typename\n }  \
                 \n status\n sampleTestCase\n metaData\n judgerAvailable\n judgeType\n mysqlSchemas\n enableRunCode\n enableTestMode\n envInfo\n libraryUrl\n __typename\n  }  \
            \n}\n"
    }

    r = requests.post("https://leetcode.com/graphql", json=data).json()
    soup = bs(r["data"]["question"]["content"], "html.parser")

    return r, soup

def scrape_data(link: str):
    titleSlug = link.split("/")[-3]

    r, soup = scrapper(titleSlug)

    questionId = r["data"]["question"]["questionId"]
    title = r["data"]["question"]["title"]
    content = soup.get_text().replace(u'\xa0', u' ')
    difficulty = r["data"]["question"]["difficulty"]

    exampleIndex = content.index("Example 1:")
    constraintIndex = content.index("Constraints:")

    question = content[:exampleIndex]
    example = content[exampleIndex:constraintIndex]
    constraint = content[constraintIndex:]

    return questionId, title, question, difficulty, example, constraint
