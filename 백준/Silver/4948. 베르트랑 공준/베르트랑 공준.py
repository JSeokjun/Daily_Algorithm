while True:
    n = int(input())
    if n == 0:
        break
    primeL = []
    for i in range(n+1, 2*n+1):
        if i==1 or (i!=2 and i%2==0):
            continue
        isPrime = True
        for j in range(2, int(i**(1/2)+1)):
            if i%j==0:
                isPrime = False
                break
        if isPrime == True:
            primeL.append(i)
    print(len(primeL))