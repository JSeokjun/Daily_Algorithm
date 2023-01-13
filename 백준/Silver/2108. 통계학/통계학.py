N = int(input())
L = []
F = [0]*8001
for _ in range(N):
    n = int(input())
    L.append(n)
    F[n+4000]+=1

L = sorted(L)
print(round(sum(L)/N))
print(L[N//2])

M = max(F)
I = F.index(max(F))
F.remove(M)
if max(F)==M:
    print(F.index(max(F))-3999)
else:
    print(I-4000)
print(L[N-1]-L[0])