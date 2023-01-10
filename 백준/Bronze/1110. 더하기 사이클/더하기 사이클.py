N = input()
N = int(N)
L = 0

if(N<10):
    if(N!=0):
        N = str(N)
        N+=N
    else:
        L+=1
else:
    N = str(N)
if(N!=0):
    N2=N
    N=N[1]+str((int(N[0])+int(N[1]))%10)
    L+=1
else:
    N2=N
while N!=N2:
    N=N[1]+str((int(N[0])+int(N[1]))%10)
    L+=1

print(L)
