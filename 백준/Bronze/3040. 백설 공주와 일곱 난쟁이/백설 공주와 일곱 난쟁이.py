n = []
for i in range(9):
    n.append(int(input()))

for i in range(0, 8):
    for j in range(i+1, 9):
        sum = 0
        for k in range(0, 9):
            if(k==i or k==j):
                a = i
                b = j
                continue
            sum+=n[k]
        if sum == 100:
            break
    if sum == 100:
        break
for i in range(0, 9):
    if(i==a or i==b):
        continue
    print(n[i])