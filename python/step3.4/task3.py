def marks_func(st_list):
    # print(student_list)
    ans = ""
    for record in student_list:
        ans += str((int(record[1]) + int(record[2]) + int(record[3])) / 3) + "\n"
    ans += str(sum([int(first) for name, first, second, third in student_list]) / len(student_list))
    ans += " "
    ans += str(sum([int(second) for name, first, second, third in student_list]) / len(student_list))
    ans += " "
    ans += str(sum([int(third) for name, first, second, third in student_list]) / len(student_list))
    return ans


if __name__ == "__main__":
    with open('in.txt') as inp, open('out.txt', 'w') as out:
        student_list = []
        for line in inp:
            record = line.split("\n")[0].split(";")
            student_list.append(record)
        out.write(marks_func(student_list))
        print(marks_func(student_list))

