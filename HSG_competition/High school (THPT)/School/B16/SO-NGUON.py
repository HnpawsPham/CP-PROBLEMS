import os
os.system("cls")

fi = open(".\\txt\\SO-NGUON.INP", "r")
n = int(fi.read())

if n < 10:
    print(-1)
    exit()

res = -1
for i in reversed(range(n - 900, n)):
    t = i
    sum = i
    while(i > 0):
        sum += i % 10
        i //= 10
    
    if sum == n:
        res = t


print(res)