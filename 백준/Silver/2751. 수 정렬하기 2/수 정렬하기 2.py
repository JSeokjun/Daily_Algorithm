N = int(input())
L = []
for _ in range(N):
    L.append(int(input()))
L = sorted(L)
for i in L:
    print(i)