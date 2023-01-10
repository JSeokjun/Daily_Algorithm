d = []
for i in range(1,10000):
    n = i
    while True:
        if n < 10:
            n+=n
        elif n < 100:
            n = str(n)
            a = int(n[0])
            b = int(n[1])
            n = int(n)
            n = n+a+b
        elif n < 1000:
            n = str(n)
            a = int(n[0])
            b = int(n[1])
            c = int(n[2])
            n = int(n)
            n = n+a+b+c
        else:
            n = str(n)
            a = int(n[0])
            b = int(n[1])
            c = int(n[2])
            e = int(n[3])
            n = int(n)
            n = n+a+b+c+e
        if n > 10000:
            break
        d.append(n)

n = list(set(d))
arr = list(range(1,10001))
for i in arr:
    if i not in n:
        print(i)