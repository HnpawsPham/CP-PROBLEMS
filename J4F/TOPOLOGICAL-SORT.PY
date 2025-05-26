n = int(input())

# e k biet khai bao graph=))))
a = [] 
topo = []
check = []

for i in range(n):
    check.append(0)


def dfs(u):
    check[u] = 1

    for v in a[u]:
        if not check[v]:
            dfs(v)
    
    topo.append(u)

dfs(1)
topo = topo.reverse()