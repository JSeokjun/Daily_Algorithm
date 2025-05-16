N = input()

cnt_dic = {'0': 0, '1': 0, '2': 0, '3': 0, '4': 0, '5': 0, '6': 0, '7': 0, '8': 0, '9': 0}

for num in N:
    cnt_dic[num] += 1

max_cnt = 0

for i in range(9):
    n = str(i)
    if cnt_dic[n] > max_cnt and n != '6' and n != '9':
        max_cnt = cnt_dic[n]

sum = cnt_dic['6']+cnt_dic['9']

print(max(max_cnt, sum//2 + sum%2))