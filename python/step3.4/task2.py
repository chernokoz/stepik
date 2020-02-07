def most_popular_word(line):
    d = dict()
    arr = line.split()
    ans = None
    for word in arr:
        d[word.upper()] = 0
    for word in arr:
        d[word.upper()] += 1
    max_count = 0
    for key, value in d.items():
        if value > max_count:
            max_count = value
            ans = key
        elif value == max_count and key < ans:
            ans = key
    return ans + " " + str(max_count)

if __name__ == "__main__":
    with open('in.txt') as inp, open('out.txt', 'w') as out:
        line = inp.readline()
        tmp = ""
        for line in inp:
            tmp += line
            tmp += " "
        out.write(most_popular_word(tmp))
