D = [["A","B","C"], ["D","E","F"], ["G","H","I"], 
    ["J","K","L"], ["M","N","O"], ["P","Q","R","S"], 
    ["T","U","V"], ["W","X","Y","Z"]]

A = input()
T = 0
for i in range(len(A)):
    for j in range(len(D)):
        if A[i] in D[j]:
            T+=D.index(D[j])+3
print(T)


