t = int(input())

for i in range(1, t + 1):
    n = input()
    if n[0] == "P":
        print("skipped")
    else:
        a, b = map(int, n.split("+"))
        print(a + b)