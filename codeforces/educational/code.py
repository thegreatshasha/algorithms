from math import gcd

n = int(input())
arr = list(map(int, input().split(' ')))
arr2 = []

for i in range(len(arr)-1):
  if not gcd(arr[i], arr[i+1]) == 1:
    #print (arr[i], arr[i+1], gcd(arr[i], arr[i+1]))
    arr2.append(str(arr[i]))
    arr2.append(str(1))
  else:
    arr2.append(str(arr[i]))

arr2.append(str(arr[-1]))

print(len(arr2)-len(arr))
print(' '.join(arr2))
