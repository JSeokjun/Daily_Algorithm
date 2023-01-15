import sys
input = sys.stdin.readline
print = sys.stdout.write

N = int(input())
L = list(map(int, input().strip().split()))

L3 = []
for i in range(N):
    L3.append([L[i],i," "])

L3.sort(key=lambda x:x[0])

cnt = 0
for i in range(N):
    if i==0:
        L3[i][2] = cnt
        cnt+=1
        continue

    if L3[i][0] == L3[i-1][0]:
        L3[i][2] = L3[i-1][2]        
    else:
        L3[i][2] = cnt
        cnt+=1

L3.sort(key=lambda x:x[1])

for i in L3:
    print(str(i[2])+" ")