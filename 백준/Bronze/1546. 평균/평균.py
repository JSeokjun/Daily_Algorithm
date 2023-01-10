N = int(input())
S = list(map(int, input().split()))
M = max(S)

sum = 0
for i in S:
    sum += i/M*100

print(sum/N)