A = list(input().upper())
l = ""
for i in range(65, 91):
    l += chr(i)
N = []
for i in l:
    N.append(0)
    for j in A:
        if i == j:
            N[l.index(i)]+=1
cnt = 0
for i in range(N.index(max(N))+1, len(N)):
    if N[i] == max(N):
        cnt+=1
if cnt == 0:
    print(l[N.index(max(N))])
else:
    print("?")
