A, B = map(int, input().split())
C = int(input())

H = C//60
M = C%60

if(B+M>=60):
    B=B+M-60
    H+=1
else:
    B+=M

if(A+H>=24):
    A=A+H-24
else:
    A+=H

print(A, B)
