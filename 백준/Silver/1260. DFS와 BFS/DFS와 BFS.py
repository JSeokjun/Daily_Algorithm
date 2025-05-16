import sys
from collections import deque 

input = sys.stdin.readline

N, M, V = map(int, input().strip().split())

G = [[]]
visited = [False]
for _ in range(N):
    G.append([])
    visited.append(False)
for _ in range(M):
    x, y = map(int, input().strip().split())
    G[x].append(y)
    G[y].append(x)
for i in range(1, N+1):
    G[i].sort()

dfs_result = []

def dfs(n):
    dfs_result.append(n)

    for next_n in G[n]:
        if not visited[next_n]:
            visited[next_n] = True
            dfs(next_n)

visited[V] = True
dfs(V)

for i in range(N+1):
    visited[i] = False

bfs_result = []
Q = deque()
visited[V] = True
Q.append(V)

while len(Q):
    n = Q.popleft()
    bfs_result.append(n)

    for next_n in G[n]:
        if not visited[next_n]:
            visited[next_n] = True
            Q.append(next_n)

print(*dfs_result)
print(*bfs_result)