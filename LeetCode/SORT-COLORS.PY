n = int(input())
a = []

for i in range(n):
    a.append(int(input()))

c0, c1, c2 = 0, 0 ,0
for x in a:
    if x == 0:
        c0 += 1
    elif x == 1:
        c1 += 1
    else:
        c2 += 1

for i in range(c0):
    a[i] = 0
for i in range(c0, c0 + c1):
    a[i] = 1
for i in range(c0 + c1, c0 + c1 + c2):
    a[i] = 2

print(a)