import sys

input = sys.stdin.readline
N, M = map(int, input().rstrip().split())
L = []
for _ in range(0, N):
    L.append(input().rstrip())
for _ in range(0, M):
    Q = input().rstrip()
    if Q >= "AA":
        print(L.index(Q) + 1)
    else:
        Q = int(Q)
        print(L[Q - 1])