n = []
for i in range(0,10):
    n.append(int(input())%42)

result = []
for v in n:
    if v not in result:
        result.append(v)

print(len(result))