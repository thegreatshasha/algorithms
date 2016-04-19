n, m, k = map(int, raw_input().split(' '))

matrix = [[0 for x in range(m)] for y in range(n)]
#print np.array(matrix).shape
#print matrix

for i in range(k):
  op, index, color = map(int, raw_input().split())
  if op == 1:
    for z in range(m):
      matrix[index-1][z] = color
  else:
    for z in range(n):
      matrix[z][index-1] = color

print('\n'.join([' '.join([str(item) for item in row]) for row in matrix]))
