N = int(input())

if N < 5:
    quo = 0
else:
    quo = (int)(N/5)

while True:
    if quo == -1:
        print(-1)
        break

    if (N-quo*5)%3==0:
        print(quo + (int)((N-quo*5)/3))
        break
    else:
        quo-=1