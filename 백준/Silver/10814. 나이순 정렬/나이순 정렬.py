import sys
input = sys.stdin.readline
print = sys.stdout.write

L = []
N = int(input())
for _ in range(N):
    age, name = input().strip().split()
    L.append([int(age), name])
L.sort(key=lambda x:x[0])

for i in L:
    print(str(i[0]) + " " + i[1] + "\n")