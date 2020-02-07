import requests

if __name__ == "__main__":
    tmp = requests.get('https://stepic.org/media/attachments/course67/3.6.2/672.txt')
    print(len(tmp.content.splitlines()))
