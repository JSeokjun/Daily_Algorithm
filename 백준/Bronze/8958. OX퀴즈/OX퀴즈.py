n = int(input())
for i in range(0,n):
    result = 0
    cnt = 1
    t = input()
    for j in range(0,len(t)):
        if t[j] == "O":
            result += cnt
            cnt += 1
        else:
            cnt = 1
    print(result)
