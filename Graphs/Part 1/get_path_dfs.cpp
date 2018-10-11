/*
   Code : Get Path - BFS

   Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find
   and print the path from v1 to v2 (if exists). Print nothing if there is no path
   between v1 and v2.
   Find the path using BFS and print the shortest path available.
   V is the number of vertices present in graph G and vertices are numbered from 0 to
   V-1.
   E is the number of edges present in graph G.
   Print the path in reverse order. That is, print v2 first, then intermediate vertices
   and v1 at last.
   Note : Save the input graph in Adjacency Matrix.

   Input Format :
   Line 1: Two Integers V and E (separated by space)
   Next E lines : Two integers a and b, denoting that there exists an edge between
   vertex a and vertex b (separated by space)
   Line (E+2) : Two integers v1 and v2 (separated by space)

   Output Format :
   Path from v1 to v2 in reverse order (separated by space)
 */

#include <iostream>
using namespace std;

#include <vector>

vector<int>* getPathHelper(int** edges, int V, int sv, int ev, bool* visited){
	if(sv == ev) {
		vector<int>* output = new vector<int>();
		output->push_back(ev);
		return output;
	}
	visited[sv] = true;
	for(int i = 0; i < V; i++) {
		if(edges[sv][i] == 1 && !visited[i]) {
			vector<int>* smallOutput = getPathHelper(edges, V, i, ev, visited);
			if(smallOutput != NULL) {
				smallOutput->push_back(sv);
				return smallOutput;
			}
		}
	}
	return NULL;
}

vector<int>* getPath(int** edges, int V, int sv, int ev){
	bool* visited = new bool[V];
	for(int i = 0; i < V; i++) {
		visited[i] = false;
	}
	vector<int>* output = getPathHelper(edges, V, sv, ev, visited);
	delete [] visited;
	return output;
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

	int sv, ev;
	cin >> sv >> ev;

	vector<int>* output = getPath(edges, V, sv, ev);
	if(output != NULL) {
		cout << "Path (dfs)" << endl;
		for(int i = 0; i < output->size(); i++) {
			cout << output->at(i) << " ";
		}
		delete output;
	} else {
		cout << "Path not found!" << endl;
	}

	for(int i = 0; i < V; i++) {
		delete [] edges[i];
	}
	delete [] edges;
}

/*
   5 8
   0 1
   0 4
   1 2
   2 0
   2 4
   3 0
   3 2
   4 3
   4 1
   Path (dfs)
   1 0 4
 */


/*
   For any possible path, DFS would be enough. But, BFS gives you the shortest
   path between the two vertices.
 */
