if __name__ == "__main__":
    words = list()
    d = int(input())
    for _ in range(d):
        words.append(input().lower())
    l = int(input())
    errors = []
    for _ in range(l):
        line_words = input().lower().split()
        for word in line_words:
            if word not in words and word not in errors:
                errors.append(word)
    print("\n".join(errors))
