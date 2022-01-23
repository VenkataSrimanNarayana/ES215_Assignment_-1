from random import random
from time import time
n = 512
# Populating the lists
a = [[random() for i in range(n)] for j in range(n)]
b = [[random() for i in range(n)] for j in range(n)]
c = [[float(0) for i in range(n)] for j in range(n)]

t1 = time()
# Perfroming the addition operations
for i in range(n):
    for j in range(n):
        for x in range(n):
            c[i][j] += a[i][x] * b[x][j]
t2 = time()

# Printing the values
for i in range(n):
    for j in range(n):
        print(a[i][j], end=" ")
    print('\n')

for i in range(n):
    for j in range(n):
        print(b[i][j], end=" ")
    print('\n')


for i in range(n):
    for j in range(n):
        print(c[i][j], end=" ")
    print('\n')

print(abs(t2 - t1))