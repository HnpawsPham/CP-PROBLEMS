n = int(input())

lvl = [50, 100, 100, 150, 150]  
w = [1700, 1950, 2130, 2320, 2520, 2780]  

cost = 0
for i in range(5):
    if n > lvl[i]:
        cost += lvl[i] * w[i]
        n -= lvl[i]
    else:
        cost += n * w[i]
        n = 0
        break

if n > 0:
    cost += n * w[5]

cost = cost * 115 // 100
print(cost)
