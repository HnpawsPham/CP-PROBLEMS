a = []
n = int(input())

for i in range(n):
    t = []
    for j in range(i + 1):
        t.append(int(input()))
    a.append(t)

oo = int(1e8)
dp = [[oo for _ in range(n)] for _ in range(n)]
dp[0][0] = a[0][0]

for i in range(1, n):
    for j in range(i + 1):
        if j > 0:
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + a[i][j])
        if j < i:
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i][j])

res = min(dp[n - 1][:n])
print(res)
