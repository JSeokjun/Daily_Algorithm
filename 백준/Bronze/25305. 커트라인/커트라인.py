N, k = map(int, input().split())
score = list(map(int,input().split()))
tmp = 0
for i in range(N-1):
    max = score[i]
    for j in range(i+1,N):
        if score[j]>max:
            max=score[j]
            tmp = j
    if max == score[i]:
        continue
    else:
        score[tmp]=score[i]
        score[i]=max
print(score[k-1])