W = list(input())
nW = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"
for i in range(1, len(W) - 1):
    for j in range(i + 1, len(W)):
        w1 = W[:i]
        w2 = W[i:j]
        w3 = W[j:]
        w1.reverse()
        w2.reverse()
        w3.reverse()
        oW = w1 + w2 + w3
        oW = "".join(s for s in oW)
        if nW > oW:
            nW = oW
print(nW)