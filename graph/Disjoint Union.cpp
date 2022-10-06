// https://www.learning.algozenith.com/problems/Disjoint-Union-39

/*

Description

Write a program that manipulates a disjoint set S = S1, S2, ..., Sk.

First of all, the program should read an integer n, then make a disjoint set where each element consists of 0, 1, ..., n-1 respectively.

Next, the program should read an integer q and manipulate the set of q queries. There are two kinds of queries for different operations:

unite(x, y): unite sets that contain x and y, say Sx and Sy, into a new set.
same(x, y): determine whether x and y are in the same set.

Input Format

The first line contains two space-separated integers n and q, (1 ≤ n ≤ 104, 1 ≤ q ≤ 105).
Then, q queries are given in the form com x y, where com represents the type of queries. '0' denotes unite and '1' denotes same operation (x != y).


Output Format

For each same operation, print 1 if x and y are in the same set, otherwise 0, in a line.


Sample Input 1

5 12
0 1 4
0 2 3
1 1 2
1 3 4
1 1 4
1 3 2
0 1 3
1 2 4
1 3 0
0 0 4
1 0 2
1 3 0
 


Sample Output 1

0
0
1
1
1
0
1
1
 
 
 */


#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

class wunionfind {
  public:
    int *id, *sz;
    wunionfind(int n = N) {
        id = new int[n + 1];
        sz = new int[n + 1];
        for(int i = 0; i <= n; i++) {
            id[i] = i;
            sz[i] = 1;
        }
    }
    int root(int idx) {
        int x = idx;
        while(x != id[x]) {
            id[x] = id[id[x]];
            x = id[x];
        }
        return x;
    }
    bool uni(int a, int b) {
        int x = root(a), y = root(b);
        if(sz[x] < sz[y]) {
            swap(x, y);
        }
        if (x != y) {
            id[y] = x;
            sz[x] += sz[y];
            sz[y] = 0;
            return false;
        }
        return true;
    }
    bool check(int a, int b) {
        return (root(a) == root(b));
    }
};

signed main()
{
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;
    wunionfind W(n);

    for(int i = 0; i < q; i++) {
        int com, x, y;
        cin >> com >> x >> y;
        if(!com) W.uni(x, y);
        else cout << W.check(x, y) << "\n";
    }

    return 0;
}
