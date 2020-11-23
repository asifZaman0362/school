import sys

def cartesian_product(A, B):
    prod = []
    for x in A:
        for y in B:
            prod.append([x, y])
            
    return prod
    
def parse_set(x):
    clean_str = ''
    for c in x:
        if not(c == ' ' or c == '{' or c == '}'):
            clean_str += c
    return clean_str.split(',')


A = parse_set(sys.argv[1])
B = parse_set(sys.argv[2])
AxB = cartesian_product(A, B)
print('{ ', end='')
for i in AxB:
    print('({},{}){}'.format(i[0], i[1], ', ' if i != AxB[-1] else ''), end='')
print(' }')