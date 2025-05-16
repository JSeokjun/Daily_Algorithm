import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().strip().split())

miro = [[] for _ in range(N)]
visited = [[] for _ in range(N)]
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

for i in range(N):
    state = input()
    for s in state:
        miro[i].append(s)
        visited[i].append(False)

Q = deque()

Q.append([0, 0, 1])
visited[0][0] = True

min_cnt = 10000

while len(Q):
    x_y_z = Q.popleft()

    if x_y_z[0] == N-1 and x_y_z[1] == M-1 and x_y_z[2] < min_cnt:
        min_cnt = x_y_z[2]

    for i in range(4):
        next_x = x_y_z[0] + dx[i]
        next_y = x_y_z[1] + dy[i]

        if next_x >= 0 and next_x < N and next_y >= 0 and next_y < M:
            if not visited[next_x][next_y] and miro[next_x][next_y] == '1':
                Q.append([next_x, next_y, x_y_z[2] + 1])
                visited[next_x][next_y] = True

print(min_cnt)