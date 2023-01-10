N = int(input())
result = 0
for i in range(N):
    word = input()
    L = []
    tmp = ""
    cnt = 1
    for j in word:
        if j == tmp:
            continue
        if j in L:
            cnt = 0
            break
        tmp = j
        L.append(j)
    result += cnt
print(result)
