n = int(input())
res = [[1]]

for i in range(n - 1):
    v = [1]

    for i in range(len(res[-1]) - 1):
        v.append(res[-1][i] + res[-1][i + 1])
    v.append(1)

    res.append(v)

print(res)