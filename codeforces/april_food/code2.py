from fractions import gcd

n = input()
m = map(int, raw_input().split())
r = map(int, raw_input().split())

sum = 0
hasha = {}

for i in range(len(m)):
  left = m[i]
  right = r[i]
  if not right == 0:
    gc = gcd(left, right)
    left = left/gc
    right = right/gc
  if not (left, right) in hasha:
    hasha[(left, right)] = True
    sum = sum + 1.0/(left+right)

print sum
