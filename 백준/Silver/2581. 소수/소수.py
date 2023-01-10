M = int(input())
N = int(input())
primeN = []

for i in range(M,N+1):
    isPrimeN = True
    if i == 1:
        continue
    for j in range(2,i):
        if i % j == 0:
            isPrimeN = False
            break
    if isPrimeN == True:
        primeN.append(i)
        
if len(primeN) == 0:
    print(-1)
else:
    print(sum(primeN))
    print(min(primeN))