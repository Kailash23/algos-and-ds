/*
   Largest Piece

   Its Gary's birthday today and he has ordered his favourite square cake
   consisting of '0's and '1's . But Gary wants the biggest piece of '1's
   and no '0's . A piece of cake is defined as a part which consist of only
   '1's, and all '1's share an edge with eachother on the cake. Given the size
   of cake N and the cake , can you find the size of the biggest piece of '1's
   for Gary ?
 */

#include <iostream>
using namespace std;

#define NMAX 55
int visited[NMAX][NMAX];
char A[NMAX][NMAX];

int cx[] = {0, 0, -1, 1}; // Change in x while taking four move
int cy[] = {1, -1, 0, 0}; // Change in y while taking four move
// top -> bottom -> left -> right

int dfs(int x, int y, int n, char **cake) {
    if (visited[x][y]) {
        return 0;
    }
    visited[x][y] = 1;
    int count = 1;
    for (int i = 0; i < 4; i++) { // 4 for 4 directions
        int dx = x + cx[i];
        int dy = y + cy[i];
        if (dx >= 0 && dx < n && dy >= 0 && dy < n && cake[dx][dy] == '1') {
            count = count + dfs(dx, dy, n, cake);
        }
    }
    return count;
}

int solve(int n, char **cake) {
    int maxsize = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cake[i][j] == '1' && visited[i][j] == 0) {
                maxsize = max(maxsize, dfs(i, j, n, cake));
            }
        }
    }
    return maxsize;
}

int main() {
    int n;
    cin >> n;
    char **cake = new char *[n];
    for (int i = 0; i < n; i++) {
        cake[i] = new char[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cake[i][j];
        }
    }
    cout << solve(n, cake);
}

/*
   4
   1111
   0110
   1001
   1111
   6
 */
