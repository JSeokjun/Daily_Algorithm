N = int(input())
L = []
for _ in range(N):
    L.append(list(map(int,input().split())))
L.sort()
for i in range(N):
    print(L[i][0], L[i][1])