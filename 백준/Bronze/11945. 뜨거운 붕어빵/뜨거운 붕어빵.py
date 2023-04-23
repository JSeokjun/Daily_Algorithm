a, b = map(int, input().split())
n = []
for i in range(a):
    n.append(list(input()))
for i in range(a):
    for j in range(b-1, -1, -1):
        print(n[i][j], end="")
    print()