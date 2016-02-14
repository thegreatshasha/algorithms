import numpy as np

def unit_vector(vector):
    """ Returns the unit vector of the vector.  """
    magnitude = np.linalg.norm(vector)
    if magnitude:
        return vector / np.linalg.norm(vector)
    else:
        return vector

points = np.array([
[-3,-4],
[2,-3],
[4, 3],
[-4,2],
[0,5],
[2,-3],
[-1,4]
]);

npoints = len(points)

slopes = np.zeros((npoints, npoints))
# initialization
reference_vector = [1,0]
tail_point_index = points.max(axis=0)[0]
tail_point = points[tail_point_index]
convex_points = []
fighton = True

# repeat
while fighton:
    # save previous point to convex points and remove the tail point from searchable points
    if len(convex_points):
        points = np.delete(points, tail_point_index, axis=0)
    convex_points.append(tail_point)

    # calculate all unit vectors starting from tail point
    tail_point_vectors = points - tail_point
    tail_point_unit_vectors = np.apply_along_axis(unit_vector, 1, tail_point_vectors) #O(n) complexity

    # find vector with maximum angle
    products = np.dot(tail_point_unit_vectors, reference_vector) #O(n) complexity

    head_index = np.argmax((products))
    head_point = points[head_index]

    # set this vector as reference_vector
    reference_vector = tail_point_vectors[head_index]

    # update points array
    tail_point_index = head_index
    # set head as the new tail point and search again
    tail_point = head_point
    # termination condition or hasta la vista baby?
    import pdb; pdb.set_trace()
    if (convex_points[0] == head_point).all():
        fighton = False

print convex_points
