N = int(input())
H = 0
if N < 100:
    H=N
else:
    H=99
    for i in range(100,N+1):
        i=str(i)
        a = int(i[0])
        b = int(i[1])
        c = int(i[2])
        if b-a == c-b:
            H+=1
print(H) 
