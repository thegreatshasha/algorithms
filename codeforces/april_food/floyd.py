from collections import defaultdict

def costs_of_shortest_paths(g):
    """
    Find the cost of the shortest path between every pair of vertices in a
    weighted graph.

    Uses the Floyd-Warshall algorithm.

    :param g: An adjacency matrix.

    >>> inf = float('inf')
    >>> g = {0: {0: 0,   1: 1,   2: 4},
    ...      1: {0: inf, 1: 0,   2: 2},
    ...      2: {0: inf, 1: inf, 2: 0}}
    >>> fw(g) # doctest: +NORMALIZE_WHITESPACE
    {0: {0: 0,   1: 1,   2: 3},
     1: {0: inf, 1: 0,   2: 2},
     2: {0: inf, 1: inf, 2: 0}}
    >>> h = {1: {2: 3, 3: 8, 5: -4},
    ...      2: {4: 1, 5: 7},
    ...      3: {2: 4},
    ...      4: {1: 2, 3: -5},
    ...      5: {4: 6}}
    >>> fw(adj(h)) # doctest: +NORMALIZE_WHITESPACE
    {1: {1: 0, 2: 1, 3: -3, 4: 2, 5: -4},
     2: {1: 3, 2: 0, 3: -4, 4: 1, 5: -1},
     3: {1: 7, 2: 4, 3: 0, 4: 5, 5: 3},
     4: {1: 2, 2: -1, 3: -5, 4: 0, 5: -2},
     5: {1: 8, 2: 5, 3: 1, 4: 6, 5: 0}}
    """
    vertices = g.keys()

    d = g
    for v2 in vertices:
        d = {v1: {v3: min(d[v1][v3], d[v1][v2] + d[v2][v3])
                 for v3 in vertices}
             for v1 in vertices}
    return d


if __name__ == "__main__":
    n = input()
    distances = defaultdict(lambda: defaultdict(int))
    for row in range(n):
        lis = map(int, raw_input().split())
        for column in range(len(lis)):
            distances[row][column] = lis[column]

    dist2 = costs_of_shortest_paths(distances)
    #print dist2

    max_s = 0

    for col in dist2.values():
        for point in col.values():
            max_s = max(max_s, point)

    print max_s
