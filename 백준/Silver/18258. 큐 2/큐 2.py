from collections import deque
import sys

input = sys.stdin.readline

N = int(input())
Q = deque()

for _ in range(N):
    command = list(map(str, input().strip().split()))

    if command[0] == 'push':
        Q.append(command[1])

    elif command[0] == 'pop':
        if len(Q) == 0:
            print(-1)
        else:
            x = Q.popleft()
            print(x)

    elif command[0] == 'size':
        print(len(Q))

    elif command[0] == 'empty':
        if len(Q):
            print(0)
        else:
            print(1)

    elif command[0] == 'front':
        if len(Q) == 0:
            print(-1)
        else:
            print(Q[0])

    elif command[0] == 'back':
        if len(Q) == 0:
            print(-1)
        else:
            print(Q[-1])

    else:
        print(-1)