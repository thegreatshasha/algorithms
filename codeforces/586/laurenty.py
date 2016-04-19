n = input()
a_0 = map(int, raw_input().split(' '))
a_1 = map(int, raw_input().split(' '))
b = map(int, raw_input().split(' '))

top = 0
left = b[0]
# Single pass

for i in range(1, len(b)):
  top = top + a_0[i-1]
  top_path = top + b[i]
  
  if type(left) is list:
    left = [item + a_1[i-1] for item in left]
    left = sorted(left+[top_path])[:2]
    print left
  else:
    add_right = left + a_1[i-1]
    left = [add_right, top_path]

print left[0] + left[1]
