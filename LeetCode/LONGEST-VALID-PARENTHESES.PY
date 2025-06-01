s = input()
n = len(s)
a = [0] * n
st = []

for i in range(n):
    if s[i] == '(':
        st.append(i)
    
    elif s[i] == ')' and len(st) > 0:
        a[st[-1]] = a[i] = 1
        st.pop()
        
res, cur = 0, 0
for x in a:
    if x:
        cur+=1
    else:
        res = max(res, cur)
        cur = 0
        
print(max(res, cur))
