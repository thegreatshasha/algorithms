import pdb
#n, m = map(int, raw_input().split(' '))
#t = [tuple([int(z.split('-')[0]), z.split('-')[1]]) for z in raw_input().split(' ')]
#s = [tuple([int(z.split('-')[0]), z.split('-')[1]]) for z in raw_input().split(' ')]
n = 5
m = 3
t=[(3, 'a'), (2, 'b'), (4, 'c'), (3, 'a'), (2, 'c')]
s=[(2, 'a'), (2, 'b'), (1, 'c')]
print t
print s

# Brute force ago without hash optimization
count = 0

for i in range(len(t) - len(s) + 1):
  if not(t[i][1] == s[0][1] or t[i][0] >= s[0][0]):
    continue

  for j in range(1, len(s)-1):
    if not (t[i+j][0] == s[j][0] or t[i+j][1] == s[j][1]):
      continue

  if t[i+j+1][0] >= s[-1][0] and t[i+j+1][1] == s[-1][1]:
    import pdb; pdb.set_trace()
    count += 1

print count

