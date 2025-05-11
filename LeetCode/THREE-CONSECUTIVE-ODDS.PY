a = []
n = int(input())

for i in range(n):
    a.append(int(input()))

def sol():
    cnt = 0
    for x in a:
        if x % 2 == 1: 
            cnt+=1
        else: 
            cnt = 0

        if cnt >= 3: 
            return True
    return False

print(sol())