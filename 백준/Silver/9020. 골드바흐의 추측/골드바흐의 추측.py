T = int(input())
for _ in range(T):
    n = int(input())
    a = [True] * n
    primes = []
    for i in range(2, int(n**0.5) + 1):
        if a[i] == True:
            for j in range(i+i, n, i):
                a[j] = False
    for i in range(2, n):
         if a[i] == True:
            primes.append(i)

    a = n//2
    b = n - a
    while True:
        if a in primes and b in primes:
            print(a, b)
            break
        else:
            a-=1
            b+=1