path = input()

a = path.split('/')
a = list(filter(lambda sub: sub.strip(), a))
dots = ['..', '.']
res = []
n = len(a)

for i in range(n):
    if a[i] == ".." and res:  
        res.pop() 
    elif a[i] not in dots:
        res.append(a[i])

print('/' + '/'.join(res))