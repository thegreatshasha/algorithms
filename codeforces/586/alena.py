n = input()
pairs = map(int, raw_input().split(' '))

head = 0
tail = len(pairs)-1
count = 0

# 1 Increase head
while pairs[head] == 0 and head<tail:
  head = head + 1

# 2 Decrement tail
while pairs[tail] == 0 and tail>head:
  tail = tail - 1

# 3 Move mid pointer
mid = head
while mid < tail:
  if pairs[mid] == 0 and pairs[mid+1] == 0:
    while pairs[mid] == 0 and mid<tail:
      mid += 1
  else:
    count += 1
    mid += 1

# 4 Add tail
if pairs[tail] == 1:
  count+=1

print count
