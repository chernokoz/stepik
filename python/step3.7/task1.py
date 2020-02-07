if __name__ == "__main__":
    n = int(input())
    records = []
    results = dict()
    for _ in range(n):
        record = input().split(';')
        # print(record)
        team1, team2 = record[0], record[2]
        results[team1] = [0, 0, 0, 0, 0] if team1 not in results else results[team1]
        results[team2] = [0, 0, 0, 0, 0] if team2 not in results else results[team2]
        results[team1][0] += 1
        results[team2][0] += 1
        if record[1] != record[3]:
            win_team = record[0] if record[1] > record[3] else record[2]
            losing_team = record[2] if record[1] > record[3] else record[0]
            results[win_team][1] += 1
            results[losing_team][3] += 1
            results[win_team][4] += 3
        else:
            results[team1][2] += 1
            results[team1][4] += 1
            results[team2][2] += 1
            results[team2][4] += 1
    for team_name, team in results.items():
        print(team_name + ":" + str(team[0]), team[1], team[2], team[3], team[4])
