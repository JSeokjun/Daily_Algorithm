n = []
for i in range(0,9):
    n.append(int(input()))

max = 0
loc = 0
for j in range(0,9):
    if(int(n[j]) > max):
        max = int(n[j])
        loc = j+1

print(max)
print(loc)
