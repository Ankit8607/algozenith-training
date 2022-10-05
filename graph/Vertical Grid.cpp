// https://www.learning.algozenith.com/problems/Vertical-Grid-389

/*

Description

You have been given a vertical grid of size N x 10, and a number K. Since it's vertical, gravity shows its effect on it. Each cell in the grid contains a ball which has some colour. Colour values can vary between 1 to 9.
Each cell in the grid is represented by a number, cij for cell (i, j). If cij = 0, then the cell (i, j) is empty. Otherwise, it contains a ball with colour cij. Each cell is either empty (indicated by a 0), or a ball in one of nine different colours (indicated by characters 1..9). Gravity causes balls to fall downward, so there is never a 0 cell below a ball.
Two cells belong to the same connected region if they are directly adjacent either horizontally or vertically, and they have the same non-zero colour. Any time a connected region exists with at least K cells, its balls all disappear, turning into zeros. If multiple such connected regions exist at the same time, they all disappear simultaneously. Afterwards, gravity might cause balls to fall downward to fill some of the resulting cells that became zeros. In the resulting configuration, there may again be connected regions of size at least K cells. If so, they also disappear (simultaneously, if there are multiple such regions), then gravity pulls the remaining balls downward, and the process repeats until no connected regions of size at least K exist.
Given the initial vertical grid, your task is to output a final picture of the grid after these operations have occurred.


Input Format

The first line of input contains N and K. The remaining N lines specify the initial state of the vertical grid.


Output Format

Please output N lines, describing a picture of the final vertical grid.


Constraints

1 ≤ N ≤ 100
1 ≤ K ≤ 10N


Sample Input 1

6 3
0000000000
0000000300
0054000300
1054502230
2211122220
1111111223

Sample Output 1

0000000000
0000000000
0000000000
0000000000
1054000000
2254500000

Note

In the example above, if K = 3, then there is a connected region of size at least K with colour 1 and also one with colour 2. Once these are simultaneously removed, the grid temporarily looks like this:

0000000000
0000000300
0054000300
1054500030
2200000000
0000000003
Then, gravity takes effect and the balls drop to this configuration:

0000000000
0000000000
0000000000
0000000000
1054000300
2254500333
Again, there is a region of size at least K (with colour 3). Removing it yields the final grid configuration:

0000000000
0000000000
0000000000
0000000000
1054000000
2254500000

*/


#include <iostream>
#include <fstream>
using namespace std;

int N, K, board[100][10], region[100][10], regsizes[1001];

void gravity(void)
{
    for (int j=0; j<10; j++) {
        int top = N-1, bottom = N-1;
        while (top >= 0) {
            while (top >= 0 && board[top][j] == 0) top--;
            if (top >= 0)
                board[bottom--][j] = board[top--][j];
        }
        while (bottom >= 0) board[bottom--][j] = 0;
    }
}

void visit(int i, int j, int r, int c)
{
    if (i<0 || i>=N || j<0 || j>9 || board[i][j]!=c || region[i][j]!=0) return;
    region[i][j] = r;
    regsizes[r]++;
    visit(i-1,j,r,c);
    visit(i+1,j,r,c);
    visit(i,j-1,r,c);
    visit(i,j+1,r,c);
}

bool iterate(void)
{
    int r = 1;
    for (int i=0; i<N; i++)
        for (int j=0; j<10; j++)
            region[i][j] = 0;
    for (int i=0; i<N; i++)
        for (int j=0; j<10; j++)
            if (board[i][j] && !region[i][j]) visit(i,j,r++,board[i][j]);
    bool progress = false;
    for (int i=0; i<N; i++)
        for (int j=0; j<10; j++)
            if (board[i][j] && regsizes[region[i][j]]>=K) {
                board[i][j] = 0;
                progress = true;
            }
    gravity();
    while (r) regsizes[r--] = 0;
    return progress;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    string s;

    for (int i=0; i<N; i++) {
        cin >> s;
        for (int j=0; j<10; j++) board[i][j] = s[j]-'0';
    }

    while (iterate());

    for (int i=0; i<N; i++) {
        for (int j=0; j<10; j++) cout << board[i][j];
        cout << "\n";
    }
    return 0;
}
