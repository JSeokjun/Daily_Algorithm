T = int(input())
for _ in range(T):
    k = int(input())
    n = int(input())
    L = []
    for i in range(1,n+1):
        L.append(i)
    for _ in range(k):
        sum = 1
        for i in range(1,n):
            sum+=L[i]
            L[i] = sum
    print(sum)