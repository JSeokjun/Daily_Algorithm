C = int(input())
for _ in range(0,C):
    S = list(map(int, input().split()))
    N = S.pop(0)
    A = sum(S)/len(S)
    cnt = 0
    for i in S:
        if i > A:
            cnt+=1

    print(format(round(cnt/N*100, 3), ".3f"),end="")
    print("%")