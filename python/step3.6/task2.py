import requests

if __name__ == "__main__":
    tmp = requests.get('https://stepic.org/media/attachments/course67/3.6.3/987573.txt')
    i = 1
    while tmp.text[0:2] != "We":
        print(i, tmp.text)
        i += 1
        link = 'https://stepic.org/media/attachments/course67/3.6.3/' + str(tmp.text)
        tmp = requests.get(link)
    print(tmp.text)
