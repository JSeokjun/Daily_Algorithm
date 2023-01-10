N = int(input())
L = list(map(int, input().split()))
cnt = 0
for i in range(N):
    cnt +=1
    if L[i] == 1:
        cnt-=1
    elif L[i] == 2:
        continue
    for j in range(2,L[i]):
        if L[i] % j == 0:
            cnt -= 1
            break
print(cnt)