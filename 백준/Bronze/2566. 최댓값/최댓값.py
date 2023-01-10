l = []
m = 0
i1 = 1
i2 = 1
for j in range(9):
    l.append(list(map(int,input().split())))
    if m < max(l[j]):
        m = max(l[j])
        i1 = j+1
        i2 = int(l[j].index(m))+1 
print(m)
print(i1, i2)