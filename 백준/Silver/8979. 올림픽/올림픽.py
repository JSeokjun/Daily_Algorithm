N, K = (map(int, input().split()))
L = []

for i in range(N):
    L.insert(i, list(map(int, input().split())))

for i in range(N):
    for j in range(N-1, i, -1):
        for k in range(1, 4):
            if L[j][k] > L[j-1][k]:
                tmp = L[j]
                L[j] = L[j-1]
                L[j-1] = tmp
                break
            elif L[j][k] < L[j-1][k]:
                break

rank = 1
equal_cnt = 0

for i in range(N-1):
    if L[i][0] == K:
        print(rank)
        break

    if L[i][1] == L[i+1][1] and L[i][2] == L[i+1][2] and L[i][3] == L[i+1][3]:
        equal_cnt += 1
    else :
        rank += (1 + equal_cnt)
        equal_cnt = 0