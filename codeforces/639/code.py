import math

def manhattan(p1, p2):
  return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

def normal(p1, p2):
  return math.sqrt((p1[0]-p2[0])**2 + (p1[1]-p2[1])**2)

def main():
  n = input()
  points = []
  count = 0

  for i in range(n):
    point = tuple([int(c) for c in raw_input().split(' ')])

    # implement caching
    for p_point in points:
      if manhattan(point, p_point) == normal(point, p_point):
        count += 1
  
    points.append(point)
  print count

if __name__ == "__main__":
  main()
