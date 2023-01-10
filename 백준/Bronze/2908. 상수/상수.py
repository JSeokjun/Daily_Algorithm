a, b = input().split()
A = ""
B = ""
for i in range(len(a)-1, -1, -1):
    A+=a[i]
for i in range(len(b)-1, -1, -1):
    B+=b[i]
A=int(A)
B=int(B)
if A>B:
    print(A)
else:
    print(B)
