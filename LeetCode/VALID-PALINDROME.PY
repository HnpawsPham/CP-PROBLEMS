s = input()

s = s.lower()
s = ''.join(ch for ch in s if ch.isalpha())
s_rev = s[::-1]

print(s == s_rev)