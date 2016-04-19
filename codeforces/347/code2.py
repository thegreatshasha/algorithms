stri = raw_input()

c_plus = 1
c_minus = 0

for i in stri:
    if i == "+":
        c_plus += 1
    elif i=="-":
        c_minus += 1

n = int(stri.split(' ')[-1])

right_eq = (n <= n*c_plus - c_minus)
left_eq = (n >= c_plus - n*c_minus)

if left_eq and right_eq:
    print "Possible"
else:
    print "Impossible"

#print n, c_plus, c_minus
