import random
import math

def validate(a, b):
    for i in a:
        if i not in b: return False
    return True

def merge(a, b):
    c = []
    i = 0
    j = 0

    for x in range(len(a)+len(b)):
        if i >= len(a):
            c.append(b[j])
            j += 1
        elif j >= len(b):
            c.append(a[i])
            i += 1
        elif a[i] < b[j]:
            c.append(a[i])
            i += 1
        else:
            c.append(b[j])
            j += 1

    return c

def split(a):
    n = math.floor(len(a)/2)
    return a[:n], a[n:]

def merge_sort(l):
    if len(l) <= 1:
        return l
    a, b = split(l)
    a = merge_sort(a)
    b = merge_sort(b)
    return merge(a, b)

lst = [random.randint(5, 100) for i in range(10)]
sort = merge_sort(lst)

assert validate(lst, sort)
print('Orig: ', lst)
print('Sort: ', sort)

