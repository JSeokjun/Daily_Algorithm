N = int(input())
L = []

for i in range(N):
    n, k, e, m = input().split(" ")
    L.append([n, int(k), int(e), int(m)])

L.sort(key=lambda x: (-x[1], x[2], -x[3], x[0]))

for i in range(N):
    print(L[i][0])