L = list(input())
i = 0
while 1:
    if len(L) <= i + 2:
        for i in L:
            print(i, end="")
        break
    if (
        (L[i] == "a" or L[i] == "e" or L[i] == "i" or L[i] == "o" or L[i] == "u")
        and L[i + 1] == "p"
        and L[i + 2] == L[i]
    ):
        del L[i + 1 : i + 3]
    i += 1
