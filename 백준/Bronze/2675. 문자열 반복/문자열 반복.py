T = int(input())
for i in range(T):
    R, P = input().split()
    R = int(R)
    P = list(P)
    NP = ""
    for i in range(len(P)):
        NP += P[i]*R
    print(NP)
