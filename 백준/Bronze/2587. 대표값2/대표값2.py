L = []
for _ in range(5):
    L.append(int(input()))
for i in range(1,5):
    for j in range(i,0,-1):
        if L[j-1]>L[j]:
            tmp=L[j]
            L[j]=L[j-1]
            L[j-1]=tmp 
print(sum(L)//5)
print(L[2])