def getFactorial(n):
    if n == 0:
        return 1
    return n * getFactorial(n-1)

N = int(input())
print(getFactorial(N))