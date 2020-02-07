if __name__ == "__main__":
    count = [0] * 11
    together_height = [0.0] * 11
    with open('in.txt') as inp, open('out.txt', 'w') as out:
        for line in inp:
            cls, last_name, height = line.split()
            together_height[int(cls) - 1] += int(height)
            count[int(cls) - 1] += 1
    for i in range(11):
        print(i + 1, "-" if count[i] == 0 else together_height[i] / count[i])
