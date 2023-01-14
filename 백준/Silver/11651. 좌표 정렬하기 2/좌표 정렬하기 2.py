N = int(input())
L = []
for _ in range(N):
    l = list(map(int,input().split()))
    l.reverse()
    L.append(l)
L.sort()
for i in range(N):
    print(L[i][1], L[i][0])