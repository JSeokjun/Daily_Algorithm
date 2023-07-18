from queue import PriorityQueue
import sys

input = sys.stdin.readline
print = sys.stdout.write

pq = PriorityQueue()
T = int(input().rstrip())

for i in range(T):
    N = int(input().rstrip())
    result = 1
    while not (pq.empty()):
        pq.get()

    if N == 1:
        a = int(input().rstrip())
        print("1\n")
        continue
    else:
        L = list(map(int, input().split()))
        for j in L:
            pq.put(j)

    while pq.qsize() != 1:
        sum = 0
        sum += pq.get()
        sum *= pq.get()
        pq.put(sum)
        result *= sum

    print(str(result % 1000000007) + "\n")
