N = int(input())
L = []
for _ in range(N):
    L.append(int(input()))
tmp = 0
for i in range(N-1):
    for j in range(0,N-i-1):
        if L[j]>L[j+1]:
            tmp=L[j]
            L[j]=L[j+1]
            L[j+1]=tmp
for i in range(N):
    print(L[i]) 