MOD = 1000000007

def fact(x):
    res = 1
    for i in range(2, x + 1):
        res = (res * i) % MOD
    return res

def ppow(a, b):
    if b == 0: 
        return 1
    half = ppow(a, b // 2) % MOD

    if b % 2:
        return (half * half * a) % MOD
    return (half * half) % MOD

with open("BAI3.INP", "r") as inp, open("BAI3.OUT", "w") as out:
    n, k = map(int, inp.readline().split())

    if k == 1:
        out.write(n)
    elif n == k:
        out.write(1)
    elif k > n:
        out.write(0)

    else:
        m = (fact(k) * fact(n - k)) % MOD
        res = (fact(n) * ppow(m, MOD - 2)) % MOD

        out.write(res)