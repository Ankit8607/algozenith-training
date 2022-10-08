// https://www.learning.algozenith.com/problems/Two-Kingdoms-38

/*

Description

In a Board of Dimensions N x M, each cell is colored with color Cij. Now, You need to select a Connected set of cells from the board such that the Number of Distinct colored cells in the set is at most 2.

Two cells are called Connected if they share an edge. A pair of cells in the Connected set should either be Connected Directly or indirectly via some connected path.

Find out the size of the Maximum Connected Set of Cells that you can create.


Input Format

The first line contains the Dimensions of the board, N and M. 

The next N line contains the M integers each. jth integer on ith Line denoting the colours of the cell Cij .


Output Format

Single integer, denoting the size of maximum number of cells in a connected Set.


Constraints

1 <= N , M <= 1000

1 <= Cij <= 1000000


Sample Input 1

3 3
1 2 5
1 4 4
3 6 4

Sample Output 1

5

*/


#include <bits/stdc++.h>
using namespace std;

const int px[] = {0, 0, -1, 1};
const int py[] = {-1, 1, 0, 0};
const int nn = 2008;

int n, m;
int sz;
pair<int, int> q[nn * nn];
bool ed[nn][nn][4];
int a[nn][nn];
int trv[nn][nn];
int id;

bool inside(int x, int y) {
    return x > 0 && x <= n && y > 0 && y <= m;
}

int bfs(int u, int v, int c1, int c2) {
    id++;
    trv[u][v] = id;
    int l, r;
    l = r = 0;
    q[0] = {u, v};
    sz = 0;
    int res = 0;
    while (l <= r) {
        u = q[l].first;
        v = q[l].second;
        l++;
        for (int i = 0; i < 4; i++) {
            int x = u + px[i];
            int y = v + py[i];
            if (inside(x, y) && (a[x][y] == c1 || a[x][y] == c2) && trv[x][y] != id) {
                trv[x][y] = id;
                q[++r] = {x, y};
            }
        }
    }
    for (int i = 0; i <= r; i++) {
        for (int j = 0; j < 4; j++) {
            int x = q[i].first + px[j];
            int y = q[i].second + py[j];
            if (inside(x, y) && trv[x][y] == id) {
                ed[q[i].first][q[i].second][j] = true;
            }
        }
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int res = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < 4; k++) {
                int x = i + px[k];
                int y = j + py[k];
                if (inside(x, y) && !ed[i][j][k]) {
                    res = max(res, bfs(i, j, a[i][j], a[x][y]));
                }
            }
        }
    }
    cout << res;
}
