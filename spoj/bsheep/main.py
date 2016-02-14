import numpy as np
from hull import get_convex_hull

def read_float_points(file):
    points = []
    points_file = open(file)
    for l in points_file:
        row = l.split()
        points.append([float(row[0]), float(row[1])])
    return np.array(points)

points = read_float_points('points.txt')
#hull = read_float_points('hull.txt')

convex_hull = get_convex_hull(points)
print convex_hull
