def get_index_alphabet(a):
    if a == 'a' or a == 'A':
        return 0
    elif a == 'b' or a == 'B':
        return 1
    elif a == 'c' or a == 'C':
        return 2
    elif a == 'd' or a == 'D':
        return 3
    elif a == 'e' or a == 'E':
        return 4
    elif a == 'f' or a == 'F':
        return 5
    elif a == 'g' or a == 'G':
        return 6
    elif a == 'h' or a == 'H':
        return 7
    elif a == 'i' or a == 'I':
        return 8
    elif a == 'j' or a == 'J':
        return 9
    elif a == 'k' or a == 'K':
        return 10
    elif a == 'l' or a == 'L':
        return 11
    elif a == 'm' or a == 'M':
        return 12
    elif a == 'n' or a == 'N':
        return 13
    elif a == 'o' or a == 'O':
        return 14
    elif a == 'p' or a == 'P':
        return 15
    elif a == 'q' or a == 'Q':
        return 16
    elif a == 'r' or a == 'R':
        return 17
    elif a == 's' or a == 'S':
        return 18
    elif a == 't' or a == 'T':
        return 19
    elif a == 'u' or a == 'U':
        return 20
    elif a == 'v' or a == 'V':
        return 21
    elif a == 'w' or a == 'W':
        return 22
    elif a == 'x' or a == 'X':
        return 23
    elif a == 'y' or a == 'Y':
        return 24
    elif a == 'z' or a == 'Z':
        return 25
    else:
        return -1
    
def get_alphabet_index(i):
    if i == 0:
        return 'A'
    elif i == 1:
        return 'B'
    elif i == 2:
        return 'C'
    elif i == 3:
        return 'D'
    elif i == 4:
        return 'E'
    elif i == 5:
        return 'F'
    elif i == 6:
        return 'G'
    elif i == 7:
        return 'H'
    elif i == 8:
        return 'I'
    elif i == 9:
        return 'J'
    elif i == 10:
        return 'K'
    elif i == 11:
        return 'L'
    elif i == 12:
        return 'M'
    elif i == 13:
        return 'N'
    elif i == 14:
        return 'O'
    elif i == 15:
        return 'P'
    elif i == 16:
        return 'Q'
    elif i == 17:
        return 'R'
    elif i == 18:
        return 'S'
    elif i == 19:
        return 'T'
    elif i == 20:
        return 'U'
    elif i == 21:
        return 'V'
    elif i == 22:
        return 'W'
    elif i == 23:
        return 'X'
    elif i == 24:
        return 'Y'
    elif i == 25:
        return 'Z'
    else:
        return -1

str = input()

cnt_alphabet = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

for a in str:
    cnt_alphabet[get_index_alphabet(a)] += 1

max_cnt = 0
max_index = 0
dup_cnt = 0

for i in range(26):
    if cnt_alphabet[i] > max_cnt:
        max_cnt = cnt_alphabet[i]
        max_index = i
        dup_cnt = 0
    elif cnt_alphabet[i] == max_cnt:
        dup_cnt += 1

if dup_cnt > 0:
    print('?')
else:
    print(get_alphabet_index(max_index))