if __name__ == "__main__":
    alphabet1 = list(input())
    alphabet2 = list(input())
    dict_to_encode = dict(zip(alphabet1, alphabet2))
    dict_to_decode = dict(zip(alphabet2, alphabet1))
    str1 = list(input())
    str2 = list(input())
    ans1 = ans2 = ""
    for char in str1:
        ans1 += dict_to_encode[char]
    for char in str2:
        ans2 += dict_to_decode[char]
    print(ans1)
    print(ans2)
