/*
   Code : BFS Traversal

   Given an undirected and connected graph G(V, E), print its BFS traversal.
   V is the number of vertices present in graph G and vertices are numbered from 0
   to V-1.
   E is the number of edges present in graph G.

   Input Format :
   Line 1: Two Integers V and E (separated by space)
   Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting
   that there exists an edge between Vertex 'a' and Vertex 'b'.

   Output Format :
   BFS Traversal (separated by space)
 */

#include <iostream>
using namespace std;

#include <queue>

void print(int** edges, int V, int sv){
	bool* visited = new bool[V];
	for(int i = 0; i < V; i++) {
		visited[i] = false;
	}

	queue<int> pendingVertices;
	pendingVertices.push(sv);
	visited[sv] = true;

	while(pendingVertices.size() != 0) {
		int currentVertex = pendingVertices.front();
		pendingVertices.pop();
		cout << currentVertex << " ";
		for(int i = 0; i < V; i++) {
			if(i == currentVertex) {
				continue;
			}
			if(edges[currentVertex][i] == 1 && !visited[i]) {
				pendingVertices.push(i);
				visited[i] = true;
			}
		}
	}
	delete [] visited;
}

int main(){
	int V, E;
	cin >> V >> E;
	int** edges = new int*[V];
	for(int i = 0; i < V; i++) {
		edges[i] = new int[V];
		for(int j = 0; j < V; j++) {
			edges[i][j] = 0;
		}
	}

	for(int i = 0; i < E; i++) {
		int f, s;
		cin >> f >> s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}

	int startVertex = 0;
	cout << endl;
	print(edges, V, startVertex);

	for(int i = 0; i < V; i++) {
		delete [] edges[i];
	}
	delete [] edges;
}

/*
  Quick Input

7
8
0 1
0 2
1 3
1 4
2 6
3 5
4 5
6 5

 */

/*
   Output

   5 8
   0 1
   0 4
   1 2
   2 0
   2 4
   3 0
   3 2
   4 3

   0 1 2 3 4
 */

/*
   BFS and DFS - O(E) - O(n^2)
 */
