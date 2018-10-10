/*
   Code : Prim's Algorithm

   Given an undirected, connected and weighted graph G(V, E) with V number of vertices
   (which are numbered from 0 to V-1) and E number of edges.
   Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
   For printing MST follow the steps -
   1. In one line, print an edge which is part of MST in the format -
   v1 v2 w
   where, v1 and v2 are the vertices of the edge which is included in MST and whose
   weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
   2. Print V-1 edges in above format in different lines.
   Note : Order of different edges doesn't matter.

   Input Format :
   Line 1: Two Integers V and E (separated by space)
   Next E lines : Three integers ei, ej and wi, denoting that there exists an edge
   between vertex ei and vertex ej with weight wi (separated by space)

   Output Format :
   MST

   Constraints :
   2 <= V, E <= 10^5

   Sample Input 1 :
   4 4
   0 1 3
   0 3 5
   1 2 1
   2 3 8

   Sample Output 1 :
   1 2 1
   0 1 3
   0 3 5
 */

#include <iostream>
using namespace std;

#include <climits>

int findMinVertex(int* weights, bool* visited, int v){              // O(v)
	int minVertexIndex = -1;
	for(int i = 0; i < v; i++) {
		if(!visited[i] && (minVertexIndex == -1 || weights[i] < weights[minVertexIndex])) {     // Initially minVertexIndex is -1 and will check minVertexIndex == -1, since || is used
			minVertexIndex = i;                                                             // it will not execute rest statement. It will simply return true. This will avoid weights[-1].
		}
	}
	return minVertexIndex;
}

void prims(int** edges, int v){
	bool* visited = new bool[v];
	int* parent = new int[v];
	int* weights = new int[v];

	for(int i = 0; i < v; i++) {
		visited[i] = false;		// Initially all vertices are unvisited
		weights[i] = INT_MAX;
	}
	parent[0] = -1;		// 0 has no parent (source) (-1 to indicate no parent)
	weights[0] = 0;		// 0 has minimum weight initially

	for(int i = 0; i < v - 1; i++) {        // n - 1
		// Find min vertex
		int minVertexIndex = findMinVertex(weights, visited, v);        // n * (n - 1)
		visited[minVertexIndex] = true;
		// Explore un-visited neighbours
		for(int j = 0; j < v; j++) {                   // n * (n - 1) - Can be optimized using adjacency list in place of adjacency matrix.
			if(edges[minVertexIndex][j] && !visited[j]) {      // adjacency list is better cause its sparse graph (vertex has few no of neighbours)
				if(edges[minVertexIndex][j] < weights[j]) {
					weights[j] = edges[minVertexIndex][j];
					parent[j] = minVertexIndex;
				}
			}
		}
	}

	for(int i = 1; i < v; i++) {
		if(parent[i] < i) {
			cout << parent[i] << " " << i << " " << weights[i] << endl;
		} else {
			cout << i << " " << parent[i] << " " << weights[i] << endl;
		}
	}
}

int main(){
	int v, e;
	cin >> v >> e;

	int** edges = new int*[v];
	for(int i = 0; i < v; i++) {
		edges[i] = new int[v];
		for(int j = 0; j < v; j++) {
			edges[i][j] = 0;
		}
	}

	for(int i = 0; i < e; i++) {
		int s, d, w;
		cin >> s >> d >> w;
		edges[s][d] = w;
		edges[d][s] = w;
	}

	cout << endl;
	prims(edges, v);

	for(int i = 0; i < v; i++) {
		delete [] edges[i];
	}
	delete [] edges;
}

/*
   5 7
   0 1 4
   0 2 8
   1 3 6
   1 2 2
   2 3 3
   2 4 9
   3 4 5

   0 1 4
   1 2 2
   2 3 3
   3 4 5
 */

/*
   Time Complexity : O(n^2)
 */

/*
   Extracting min will take O(v) times, if we use priority queue it would be O(logv).
   We will be able to improve Time Complexity from O(v^2) to O(e + v) log v if we use
   both adjacency list and priority queue.
 */

/*
ALGORITHM

(i)   0 has min weight initially and it has no parent ie (-1).
(ii)  We will visited 0 first as it has min weight. Will mark it as visited.
(iii) We will explore 0's neighbours, and update their weight if it's previous
	  weight is greater than edge weight between 0 and to that particular neighbour.
	  We will always look for better choice. We will update parent accordingly.
(iv)  After updating neighbours weight, out of all unvisited nodes we will pick
      the vertex with minimum weight. And then make that vertex visited. And do
	  the same thing as we done previously ie visit its neighbours (unvisited) and
	  update their weight and parent depending on condition.
(v)	  Then we can make MST by using parent, vertex (for edge) and weight (for edge weight).

*/
