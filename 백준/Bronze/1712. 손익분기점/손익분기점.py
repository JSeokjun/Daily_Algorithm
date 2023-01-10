A, B, C = map(int, input().split())

if B >= C:
    P = -1
else:
    P = A / (C - B) + 1
    
print(int(P))  