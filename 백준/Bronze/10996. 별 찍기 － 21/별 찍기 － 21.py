n = int(input())
for i in range(0, 2*n):
    if i%2==0:
        for j in range(0, n):
            if j%2==0:
                print("*", end="")
            else:
                print(" ", end="")
    else:
        for j in range(0, n):
            if j%2==0:
                print(" ", end="")
            else:
                print("*", end="")
    print('')