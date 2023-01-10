M, N = map(int, input().split())
primes = [False,False] + [True]*(N-1)
for i in range(2,N+1):
    if primes[i]==True:
        for j in range(2*i,N+1,i):
            primes[j] = False
for i in range(M,N+1):
    if primes[i]==True:
        print(i)