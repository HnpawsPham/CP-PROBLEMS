n = int(input())

def sol(n):
    if n == 1:
        return "1"

    s = sol(n - 1)
    cnt = 1
    res = ""

    for i in range(len(s)):
        if(i + 1 < len(s) and s[i] == s[i + 1]):
            cnt += 1
        else:
            res = res + str(cnt) + s[i]
            cnt = 1
    return res

print(sol(n))
