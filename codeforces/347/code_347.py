import operator
from fractions import gcd
import cProfile

# def gcd(a,b):
#   rem = b%a
#   if rem==0:
#     return a
#   else:
#     return gcd(a, rem)


def inp():
    a, b = map(int, input().split(' '))
    return a,b

def main():

    a, b = inp()

    rez = a

    left = a+1

    while left<=b:
        left += 1
        rez = gcd(rez, left)

    print(rez)

if __name__ == "__main__":
    cProfile.run(main())
