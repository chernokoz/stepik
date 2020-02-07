if __name__ == "__main__":
    x = y = 0
    n = int(input())
    for _ in range(n):
        command = input().split()
        direction = command[0]
        delta = int(command[1])
        if direction == "север":
            y += delta
        if direction == "юг":
            y -= delta
        if direction == "восток":
            x += delta
        if direction == "запад":
            x -= delta
    print(x, y)
