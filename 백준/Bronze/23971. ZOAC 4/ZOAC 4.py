H, W, N, M = map(int, input().split(" "))

w_cnt = 0
pos = 0
idx = 1

while pos < W:
    if idx % 2 == 1:
        w_cnt += 1
        pos += 1
    else:
        pos += M

    idx += 1

h_cnt = 0
pos = 0
idx = 1

while pos < H:
    if idx % 2 == 1:
        h_cnt += 1
        pos += 1
    else:
        pos += N

    idx += 1

print(w_cnt * h_cnt)