/*
   Code : DFS Traversal

   Given an undirected and disconnected graph G(n, e), print its DFS traversal.
   n is the number of vertices present in graph G and vertices are numbered from 0
   to n-1.
   e is the number of edges present in graph G.

   Input Format :
   Line 1: Two Integers n and e (separated by space)
   Next 'e' lines, each have two space-separated integers, 'a' and 'b', denoting
   that there exists an edge between Vertex 'a' and Vertex 'b'.

   Output Format :
   DFS Traversal (separated by space)
 */

#include <iostream>
using namespace std;

void print(int **edges, int n, int sv, bool *visited) {
    cout << sv << " ";
    visited[sv] = true;
    for (int i = 0; i < n; i++) {
        if (i == sv) {
            continue;
        }
        if (edges[sv][i] == 1) {
            if (visited[i]) {
                continue;
            }
            print(edges, n, i, visited);
        }
    }
}

void BFS(int **edges, int n) {
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            print(edges, n, i, visited);
        }
    }
    delete[] visited;
}

int main() {
    int n; // Vertices
    int e; // Edges
    cin >> n >> e;
    int **edges = new int *[n]; // Adjacency matrix of n X n (where n is the no of vertices)
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++) {
            edges[i][j] = 0; // Initially all set to 0
        }
    }
    for (int i = 0; i < e; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    cout << endl;

    BFS(edges, n); // Initially taking starting vertex as 0
    for (int i = 0; i < n; i++) {
        delete[] edges[i];
    }
    delete[] edges;
}

/*
	9 8
	0 1
	1 2
	0 2
	3 4
	5 6
	5 7
	6 8
	7 8

    0 1 2 3 4 5 6 8 7
 */

/*
		   0					3				  5
		/      \				  \			   /	 \
	  1    _	2					4		 6		   7
	  										   \	 /
											   	  8
*/

/*
   BFS and DFS - O(E) - O(n^2)
 */
