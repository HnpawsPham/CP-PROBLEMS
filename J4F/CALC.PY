MOD = 10**9 + 7

def mod_pow(a, b, mod):
    result = 1
    a = a % mod
    while b > 0:
        if b % 2 == 1:
            result = result * a % mod
        a = a * a % mod
        b //= 2
    return result

def mod_inv(a, mod):
    return mod_pow(a, mod - 2, mod)

with open('CALC.INP', 'r') as f:
    p, n = map(int, f.readline().split())

if p == 1:
    total = (n + 1) % MOD
else:
    numerator = (mod_pow(p, n + 1, MOD) - 1 + MOD) % MOD
    denominator_inv = mod_inv(p - 1, MOD)
    total = numerator * denominator_inv % MOD

with open('CALC.OUT', 'w') as f:
    f.write(str(total))
