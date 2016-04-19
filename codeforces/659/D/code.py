n = input()
x_l = [int(x) for x in raw_input().split(' ')]
y_l = [int(y) for y in raw_input().split(' ')]

x_bit = 0
y_bit = 0

for i in range(len(x_l)):
  x_bit = x_bit|x_l[i]
  y_bit = y_bit|y_l[i]

print x_bit + y_bit
