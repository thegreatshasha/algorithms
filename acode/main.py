from sys import stdin
ma = {}

hasha = {}
for c in xrange(ord('a'), ord('z')+1):
  hasha[c] = 1

def raw_inputa():
  return stdin.readline()

def feasible(num):
  num = int(num)
  if num >= 1 and num <= 26:
    return 1
  else:
    return 0

cache = {}

def decode(S, i):
  if i>=len(S)-1:
    return 1
  else:
    last = (feasible(S[i:i+2]) and decode(S,i+2))
    if S[i] == '0':
      return 0
    return decode(S, i+1) + last

outputs = []
digit = int(raw_inputa())
while digit:
  outputs.append(str(decode(str(digit), 0)))
  digit = int(raw_inputa())  
print '\n'.join(outputs)
