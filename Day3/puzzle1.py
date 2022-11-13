with open("input.txt", "r") as file:
    linelen = 12
    gamma_rate = [0] * linelen
    epsilon_rate = [0] * linelen

    lineCount = 0

    for line in file:
        line = line.strip()
        for i in range(len(line)):
            try:
                gamma_rate[i] += int(line[i].strip())
            except:
                pass

        lineCount += 1

    for i in range(linelen):
        print(gamma_rate[i])
        gamma_rate[i] = (lineCount - gamma_rate[i]) < (lineCount // 2)
        epsilon_rate[i] = not gamma_rate[i]
        gamma_rate[i] = int(gamma_rate[i])
        epsilon_rate[i] = int(epsilon_rate[i])

    gamma_string = "".join([str(int) for int in gamma_rate])
    epsilon_string = "".join([str(int) for int in epsilon_rate])

    ans = int(gamma_string, 2) * int(epsilon_string, 2)

    print(ans)
