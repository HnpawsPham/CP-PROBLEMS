n = int(input())
a = []
b = []
res = []

for i in range(n):
    a.append(input())

for i in range(n):
    b.append(int(input()))

res.append(a[0])
last = b[0]

for i in range(n):
    if b[i] != last:
        last = b[i] 
        res.append(a[i])

for x in res:
    print(x, end = " ")   