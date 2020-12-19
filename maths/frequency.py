import math


class Table:
    
    def __init__(self, name):
        self.name = name
        self.data = list()
        self.frequency = dict()
        self.count = 0
        self.unique = list()


def append(x, table):
    table.count += 1
    if x in table.data: table.frequency[x] += 1
    else: table.frequency[x] = 1
    table.data.append(x)
    if x not in table.unique:
        table.unique.append(x)
        table.unique.sort()


def printTable(table):
    print('\n\n')
    print('----------------------')
    for i in table.unique:
        print(i, '\t: ', table.frequency[i])
    print('----------------------')
    print('TOTAL\t: ', table.count)


table = Table('Marks')

while True:
    x = input('-> ')
    if x == 'q': break
    else: append(x, table)

printTable(table)
