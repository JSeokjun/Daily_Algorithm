n = int(input())

arr = []
for _ in range(n):
    arr.append(list(input()))

k = int(input())

if k == 1:
    for i in range(n):
        for j in range(n):
            print(arr[i][j], end="")
        print()
elif k == 2:
    for i in range(n):
        for j in range(n-1, -1, -1):
            print(arr[i][j], end="")
        print()
else:
    for i in range(n-1, -1, -1):
        for j in range(n):
            print(arr[i][j], end="")
        print()