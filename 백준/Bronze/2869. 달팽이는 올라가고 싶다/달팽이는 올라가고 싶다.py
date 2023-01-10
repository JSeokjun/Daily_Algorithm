A, B ,V = map(int, input().split())
if A >= V:
    print(1)
elif (int)((V-A)/(A-B)) == 0:
    print(2)
elif (V-A)%(A-B) == 0:
    print((int)((V-A)/(A-B))+1)
else:
    print((int)((V-A)/(A-B))+2) 