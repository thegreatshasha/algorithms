from collections import defaultdict
import random

def read_input(filename, adj_list):
	lines = open(filename).readlines()

	for line in lines:
		nodearray = line.strip().split('\t')
		node1 = int(nodearray[0])
		nodes_rest = nodearray[1:]

		for node2 in nodes_rest:
			adj_list[node1][int(node2)] += 1

def print_graph(adj_list):
	for key in adj_list:
		print(key, dict(adj_list[key]))

def karger(adj_list):
	#print_graph(adj_list)

	while(len(adj_list.keys()) > 2):
		node1 = random.choice(adj_list.keys())
		node2 = random.choice(adj_list[node1].keys())
		newnode = str(node1) + ',' + str(node2)
		#print("Merging", node1, node2, "into", newnode)
		
		for neighbour1 in adj_list[node1]:
			if(neighbour1 != node2):
				#print("before", newnode, neighbour1, adj_list[newnode][neighbour1])
				adj_list[newnode][neighbour1] += adj_list[node1][neighbour1]
				#print("after", newnode, neighbour1, adj_list[newnode][neighbour1])
				
				#print("before", neighbour1, newnode, adj_list[neighbour1][newnode])
				adj_list[neighbour1][newnode] += adj_list[node1][neighbour1]
				#print("after", neighbour1, newnode, adj_list[neighbour1][newnode])

				adj_list[neighbour1].pop(node1)

		for neighbour2 in adj_list[node2]:
			if(neighbour2 != node1):
				#print("before", newnode, neighbour2, adj_list[newnode][neighbour2])
				adj_list[newnode][neighbour2] += adj_list[node2][neighbour2]
				#print("after", newnode, neighbour2, adj_list[newnode][neighbour2])
				
				#print("before", neighbour2, newnode, adj_list[neighbour2][newnode])
				adj_list[neighbour2][newnode] += adj_list[neighbour2][node2]
				#print("after", neighbour2, newnode, adj_list[neighbour2][newnode])

				adj_list[neighbour2].pop(node2)

		adj_list.pop(node1)
		adj_list.pop(node2)

		#print_graph(adj_list)

#def main():
globalmin = 1000

for i in range(1, 400000):
	adj_list = defaultdict(lambda: defaultdict(lambda: 0))
	read_input('input.txt', adj_list)
	print('\n')
	karger(adj_list)
	min1 = adj_list[adj_list.keys()[0]][adj_list.keys()[1]]
	if(min1<globalmin):
		globalmin = min1

	print('min:', min1, 'globalmin:', globalmin)
	#print(globalmin)
	#print(adj_list)
#if __name__ == '__main__':
#	main()
#print('final min is', globalmin)