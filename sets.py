import sys

def cp(A, B):
    prod = []
    for x in A:
        for y in B:
            prod.append([x, y])
    return prod
    

def dif(A, B):
    diff = []
    for x in A:
        if x not in B: diff.append(x)
    return diff
    

def un(A, B):
    uni = []
    for i in A:
        if i not in uni: uni.append(i)
    for i in B:
        if i not in uni: uni.append(i)
    return uni


def ins(A, B):
    ins = []
    for i in A:
        if i in B: ins.append(i)
    return ins


def parse_set(x):
    clean_str = ''
    for c in x:
        if not(c == ' ' or c == '{' or c == '}'):
            clean_str += c
    return clean_str.split(',')


def prints(s, nm="S"):
    print('{} = {{'.format(nm), end='')
    for i in s:
        print('{}{}'.format(i, ', ' if i != s[-1] else ''), end='')
    print(' }')


U = [i for i in range(1, 11)]
A = [i for i in U if i % 2 != 0 or i == U[-1]]
C = [8, 9, 10]
B = dif(U, A)
prints(A, 'A')
prints(B, 'B')
prints(C, 'C')
prints(U, 'U')
print('\n'*3)
prints(un(dif(A, B), dif(B, A)), "(A-B)U(B-A)")
print('\n'*3)
prints(cp(A, un(B, C)), 'A×(B U C)')
print('\n'*3)
prints(cp(B, ins(A, C)), 'B×(A n C)')
print('\n'*3)
prints(dif(A, un(B, C)), 'A - (B U C)')
print('\n'*3)
