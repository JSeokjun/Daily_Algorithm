N = int(input())
sum = 1
cnt = 1
d = 6
while True:
    if sum >= N:
        print(cnt)
        break
    sum += d
    cnt+=1
    d+=6