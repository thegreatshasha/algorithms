import math

def main():
  n = input()
  ccount = {'x': {}, 'y': {}}
  common_point_count = 0

  count = 0

  for i in range(n):
    x, y = [int(c) for c in raw_input().split(' ')]

    if x in ccount['x'] and x in ccount['y']:
      
  print count

if __name__ == "__main__":
  main()
