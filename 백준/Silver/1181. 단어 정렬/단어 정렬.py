import sys
input = sys.stdin.readline
print = sys.stdout.write

N = int(input())
L = []
for i in range(N):
    L.append(input().strip())

L = list(set(L))
L.sort(key=lambda x:(len(x),x))

for i in L:
    print(i+"\n")