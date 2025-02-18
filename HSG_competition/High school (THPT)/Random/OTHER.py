n = int(input())

res = 1
for i in range(2, n + 1): res *= i

while(res % 10 == 0):
    res //= 10

print(res % 10)