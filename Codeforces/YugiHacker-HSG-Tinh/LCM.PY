import sys
import math
sys.set_int_max_str_digits(10**7) 

MOD = int(1e9 + 7)
maxn = int(1e6 + 5)
spf = list(range(maxn))
cntp = [0] * maxn

def sieve():
    for i in range(2, int(math.sqrt(maxn)) + 1):
        if spf[i] == i:
            for j in range(i * i, maxn, i):
                spf[j] = i

def calc_p(x):
    while x > 1:
        cntp[spf[x]] += 1
        x //= spf[x]

def sol(a, b):
    for i in range(a, b + 1):
        calc_p(i)
    
    res = 1
    for i in range(2, maxn):
        if cntp[i]:
            res = res * (2 * cntp[i] % MOD + 1) % MOD
    return res

def main():
    with open("LCM.inp", "r") as f:
        a, b = map(int, f.read().split())
    sieve()

    for i in range(a, b+1):
        calc_p(i)

    res = 1
    for i in range(2, maxn):
        if cntp[i]:
            res *= (2 * cntp[i] + 1)

    with open("LCM.out", "w") as f:
        f.write(str(res))

if __name__ == "__main__":
    main()