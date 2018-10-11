/*
   Code : Is Connected ?

   Given an undirected graph G(V,E), check if the graph G is connected graph or not.
   V is the number of vertices present in graph G and vertices are numbered from 0
   to V-1.
   E is the number of edges present in graph G.

   Input Format :
   Line 1: Two Integers V and E (separated by space)
   Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that
   there exists an edge between Vertex 'a' and Vertex 'b'.

   Output Format :
   "true" or "false"
 */

#include <iostream>
using namespace std;

#include <queue>

void printBFS(int** edges, int V, int sv, bool* visited){
	visited[sv] = true;
	queue<int> bfsQ;
	bfsQ.push(sv);
	while(!bfsQ.empty()) {
		int front = bfsQ.front();
		bfsQ.pop();
		for(int i = 0; i < V; i++) {
			if(front == i) {
				continue;
			}
			if(edges[front][i] && !visited[i]) {
				bfsQ.push(i);
				visited[i] = true;
			}
		}
	}
}

int main(){
	int V, E;
	cin >> V >> E;

	int** edges = new int*[V];
	for(int i = 0; i < V; i++) {
		edges[i] = new int[V];
	}

	for(int i = 0; i < E; i++) {
		int f, s;
		cin >> f >> s;
		edges[s][f] = 1;
		edges[f][s] = 1;
	}

	bool* visited = new bool[V];
	for(int i = 0; i < V; i++) {
		visited[i] = false;
	}

	int startVertex = 0;
	printBFS(edges, V, startVertex, visited);

	bool ans = visited[0];
	for(int i = 1; i < V; i++) {
		ans = ans && visited[i];
	}

	if(ans) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}

	for(int i = 0; i < V; i++) {
		delete [] edges[i];
	}
	delete [] edges;
	delete [] visited;
}

/*
   4 4
   0 1
   0 3
   1 2
   2 3
   true
 */
