n = int(input())
m = int(input())

sum = 0
i = 1
for j in range(0, m, 2):
    sum = sum + i + n - (i - 1)
    i += 1
if m % 2 == 1:
    sum -= n - (i - 2)
print(sum)