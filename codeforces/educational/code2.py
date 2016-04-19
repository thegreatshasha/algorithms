n, m = list(map(int, input().split(' ')))
m_c = m

matrix = [[0 for x in range(4)] for x in range(n)]

def fillM(matrix, left):
    right = 3 - left
    row = 0
    count = 0
    global m_c
    global m
    global n

    while m_c > 0 and row<n:
        #print(row, left)
        matrix[row][left] = m - m_c + 1
        m_c = m_c - 1

        if m_c <= 0:
            return 0

        #print(row, right)
        matrix[row][right] = m - m_c + 1
        m_c = m_c - 1
        row += 1

fillM(matrix, 0)
fillM(matrix, 1)

arr3 = []

for row in range(n):
    if not(matrix[row][1]==0):
        arr3.append(str(matrix[row][1]))
    if not(matrix[row][0]==0):
        arr3.append(str(matrix[row][0]))
    if not(matrix[row][2]==0):
        arr3.append(str(matrix[row][2]))
    if not(matrix[row][3]==0):
        arr3.append(str(matrix[row][3]))

#import numpy as np
#print(np.array(matrix))

print(' '.join(arr3))
