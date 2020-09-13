/*
   Code : Has Path

   Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
   V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
   E is the number of edges present in graph G.

   Input Format :
   Line 1: Two Integers V and E (separated by space)
   Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
   Line (E+2) : Two integers v1 and v2 (separated by space)

   Output Format :
   true or false
 */

#include <iostream>
using namespace std;

void hasPathHelper(int **edges, int V, int v1, int v2, bool *visited) {
    visited[v1] = true;
    if (v1 == v2) {
        return;
    }
    for (int i = 0; i < V; i++) {
        if (i == v1) {
            continue;
        }
        if (edges[v1][i] == 1 && !visited[i]) {
            hasPathHelper(edges, V, i, v2, visited);
        }
    }
}

void hasPath(int **edges, int V, int v1, int v2) {
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    hasPathHelper(edges, V, v1, v2, visited);

    if (visited[v2]) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    delete[] visited;
}

int main() {
    int V, E;
    cin >> V >> E;

    int **edges = new int *[V];
    for (int i = 0; i < V; i++) {
        edges[i] = new int[V];
        for (int j = 0; j < V; j++) {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < E; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    int v1, v2;
    cin >> v1 >> v2;
    hasPath(edges, V, v1, v2);

    for (int i = 0; i < V; i++) {
        delete[] edges[i];
    }
    delete[] edges;
}

/*
   4 4
   0 1
   0 3
   1 2
   2 3
   1 3
   true
 */
