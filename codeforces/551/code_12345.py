n = input()
l = map(int, raw_input().split(' '))

ha = {}

mad_min = 100000000
nless = 0
l_s = l[:]
l_s.sort(reverse=True)

#print l_s

for i, num in enumerate(l_s):
    if num<mad_min:
        mad_min = num
        nless = 1+i
    ha[num] = nless

l2 = [str(ha[n]) for n in l]
#print l2
print " ".join(l2)

#print ha
