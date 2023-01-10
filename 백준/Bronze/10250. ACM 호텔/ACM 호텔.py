T = int(input())
for _ in range(T):
    H, W, N = map(int, input().split())
    Y = 0
    X = 1
    for _ in range(N):
        Y+=1
        if Y > H:
            Y = 1
            X+=1
    if X<10:
        print(str(Y)+"0"+str(X))
    else:
        print(str(Y)+str(X))