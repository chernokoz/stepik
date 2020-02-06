def unzip_line(line):
    ans = ""
    for i in range(len(line)):
        if not line[i].isdigit():
            ans += read_int(line, i + 1) * line[i]
    return ans

def read_int(line, i):
    if line[i].isdigit():
        ans = line[i]
    else:
        return None
    i += 1
    while i < len(line) and line[i].isdigit():
        ans += line[i]
        i += 1
    return int(ans)


if __name__ == "__main__":
    print(unzip_line("a3b4c2e10b1"))
    with open('in.txt') as inp, open('out.txt', 'w') as out:
        line = inp.readline()
        out.write(unzip_line(line))
