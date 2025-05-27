n, m = int(map, input().split())

sum, sum1 = 0, 0

for i in range(1, n + 1):
    if i % m == 0 :
        sum += i
    else:
        sum1 += i

print(sum1 - sum)