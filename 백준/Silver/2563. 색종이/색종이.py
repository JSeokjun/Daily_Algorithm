paper = [[True]*100 for _ in range(100)]
n = int(input())
for _ in range(n):
    row, col = map(int, input().split())  
    for i in range(row, row+10):
        for j in range(col, col+10):
            if paper[i][j] == True:
                paper[i][j] = False
size=0
for i in range(100):
        for j in range(100):
            if paper[i][j] == False:
                size+=1
print(size)