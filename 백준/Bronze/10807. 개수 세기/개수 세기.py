N = int(input())
cnt = 0
n = (input().split())
v = input()
for i in range(0, N):
    if n[i] == v:
        cnt+=1
print(cnt)