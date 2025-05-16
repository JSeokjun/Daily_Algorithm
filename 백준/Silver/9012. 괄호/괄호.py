T = int(input())

stack = []

while T:
    ps = input()

    for p in ps:
        if p == '(':
            stack.append('(')
        elif p == ')':
            if len(stack):
                if stack[-1] == '(':
                    stack.pop()
                else:
                    stack.append(')')
            else:
                stack.append(')')

    if len(stack):
        print('NO')
    else:
        print('YES')
    
    stack.clear()
    T -= 1