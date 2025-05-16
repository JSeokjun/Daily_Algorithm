N = int(input())

record = set()
for _ in range(N):
    name, state = input().split()
    
    if state == 'enter':
        record.add(name)
    elif state == 'leave':
        record.remove(name)

name_list = []
for n in record:
    name_list.append(n)

name_list = sorted(name_list, reverse=True)

for n in name_list:
    print(n)