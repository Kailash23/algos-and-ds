/*
   Code : Kruskal's Algorithm

   Given an undirected, connected and weighted graph G(V, E) with V number of
   vertices (which are numbered from 0 to V-1) and E number of edges.
   Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
   For printing MST follow the steps -

   1. In one line, print an edge which is part of MST in the format -
   v1 v2 w
   where, v1 and v2 are the vertices of the edge which is included in MST and
   whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while
   printing an edge.
   2. Print V-1 edges in above format in different lines.
   Note : Order of different edges doesn't matter.

   Input Format :
   Line 1: Two Integers V and E (separated by space)
   Next E lines : Three integers ei, ej and wi, denoting that there exists an
   edge between vertex ei and vertex ej with weight wi (separated by space)

   Output Format :
   MST

   Constraints :
   2 <= V, E <= 10^5

   Sample Input:
   4 4
   0 1 3
   0 3 5
   1 2 1
   2 3 8

   Sample Output:
   1 2 1
   0 1 3
   0 3 5
 */

#include <iostream>
using namespace std;

#include <algorithm>

class Edge {
	public:
	  int source;
	  int dest;
	  int weight;
};

bool compare(Edge e1, Edge e2){     // Descending Order
	return e1.weight < e2.weight;
}

int findParent(int v, int* parent){     // for finding parent of the vertex
	if(v == parent[v]) {
		return v;
	}
	findParent(parent[v], parent);
}

void Kruskals(Edge *input, int v, int e){
	// sort the input array on the basis of weights
	sort(input, input + e, compare);
	Edge *output = new Edge[v - 1];     // output array to store MST (Minimum Spanning Tree)
	int* parent = new int[v];
	for(int i = 0; i < v; i++) {
		parent[i] = i;		// Initially each vertex is parent of itself.
	}
	int count = 0;      // For counting no of edges in MST
	int i = 0;
	while(count != v - 1) {      // No of edges present in MST is equal to (vertice's count - 1)
		Edge currentEdge = input[i];
		// Check if we can add currentEdge to MST or not.
		int sourceParent = findParent(currentEdge.source, parent);
		int destParent = findParent(currentEdge.dest, parent);

		if(sourceParent != destParent) {     // Union find method for cycle detection.
			output[count] = currentEdge;	 // Vailid path if source and destination have different parent.
			parent[sourceParent] = destParent;		// Making vertex under same parent.
			count++;		// Track MST output array index
		}
		i++;
	}

	for(int i = 0; i < v - 1; i++) {     // v -1 edges in MST (v - total vertice's count)
		if(output[i].source < output[i].dest) {
			cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
		} else {
			cout << output[i].dest << " " << output[i].source << " " << output[i].weight << endl;
		}
	}
}

int main(){
	int v, e;       // v - total no of vertex  , e - total number of edge
	cin >> v >> e;
	Edge* input = new Edge[e];      // Size - no of edges.
	for(int i = 0; i < e; i++) {
		int s, d, w;
		cin >> s >> d >> w;
		input[i].source = s;
		input[i].dest = d;
		input[i].weight = w;
	}
	cout << endl;
	Kruskals(input, v, e);
}

/*
   6 11
   0 1 2
   1 3 1
   0 2 4
   2 4 9
   4 5 5
   3 5 7
   4 3 11
   2 5 10
   0 3 3
   2 1 8
   2 3 6

   1 3 1
   0 1 2
   0 2 4
   4 5 5
   3 5 7
 */

/*
   1. Take Input - size = E
   2. Sorting input array - O(Elog(E))
   3. Pick n - 1 edges and put in MST -> Perform cycle detection O(EV)
    	In worst case E = V^2

				O(EV + ElogE)

   4. (i)  Union Find Method. O(EV)
   	  (ii) Union by rank and path compression. O(ElogV)
 */

/*
   Kruskal's Algorithm is a greedy algorithm.
   Greedy Algorithm - If I have multiple options, i will pick the one which seems
   best to me.
 */
