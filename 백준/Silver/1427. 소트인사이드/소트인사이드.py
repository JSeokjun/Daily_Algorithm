N = input()
L = []
for i in N:
    L.append(i)
L = sorted(L)
for i in range(len(N)-1,-1,-1):
    print(L[i],end="")