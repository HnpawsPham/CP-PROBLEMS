import os, math
os.system("cls")

fi = open(".\\txt\\BTVN.INP", "r")
t = int(fi.readline())

MAXN = 205
ngto = [True] * MAXN

def sieve():
    ngto[0] = ngto[1] = False

    for i in range(2, int(math.sqrt(MAXN))):
        if ngto[i]:
            for j in range(i + i, MAXN, i): ngto[j] = False

def countPi(x, n):
    res = 0
    i = 1

    while True:
        p = x ** i
        if(p > n): return max(res, 1)
        res += (n // p)
        i+=1

def solve(n):
    res = 1

    for i in range(1, n + 1):
        if ngto[i]:
            pi = countPi(i, n)
            res *= ((i**(pi + 1) - 1) // (i - 1));
    print(res)

sieve()

for i in range(t):
    n = int(fi.readline())
    solve(n)