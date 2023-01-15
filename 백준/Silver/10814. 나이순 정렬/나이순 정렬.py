import sys
input = sys.stdin.readline
print = sys.stdout.write

L = []
N = int(input())
for _ in range(N):
    L.append(list(input().strip().split()))
for i in L:
    i[0] = int(i[0])
L.sort(key=lambda x:x[0])

for i in L:
    print(str(i[0]) + " ")
    print(i[1] + "\n")