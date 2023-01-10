X = int(input())
start = 1
num = 1
plus = 2
while True:
    if X<=start:
        if num%2!=0:
            print(str(1+start-X)+"/"+str(num-(start-X)))
        else:
            print(str(num-(start-X))+"/"+str(1+start-X))
        break

    start+=plus
    plus+=1
    num+=1
    