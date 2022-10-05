// https://www.learning.algozenith.com/problems/Order-of-Heights-382

/*

Description

There are N persons standing in the queue. They are numbered from 1 to N. Hi is the height of the person i. Pi is the number of persons who are taller than i and standing in front of i. 
Given these two arrays H and P, your task is to find the actual order of the queue. 
It is guaranteed that the height of each person will be unique.


Input Format

The first line of input contains N - the number of persons.
The second line of input contains N space-separated numbers H1, H2, …, HN.
The third line of input contains N space-separated numbers P1, P2, …, PN.
It is guaranteed that the answer will always exist.


Output Format

Print N space-separated integers p1, p2, …, pN - representing the actual order of the queue, where pi is the person number standing at the ith position in the queue.


Constraints

1 ≤ N ≤ 105
1 ≤ Hi ≤ 109
0 ≤ Pi ≤ N


Sample Input 1

6
5 3 2 6 1 4
0 1 2 0 3 2

Sample Output 1

1 2 3 5 4 6

*/


#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

int tree[4 * N];

void build(int node, int start, int end) {
    if(start == end) {
        tree[node] = 1;
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
    return;
}

void update(int node, int start, int end, int idx, int val) {
    if(start == end) {
        tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    if(idx <= mid) update(2 * node, start, mid, idx, val);
    else update(2 * node + 1, mid + 1, end, idx, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
    return;
}

int query(int node, int start, int end, int x) {
    if(start == end) {
        assert(tree[node] == x);
        return start;
    }
    int mid = (start + end) / 2;
    if(tree[2 * node] >= x) return query(2 * node, start, mid, x);
    return query(2 * node + 1, mid + 1, end, x - tree[2 * node]);
}

signed main()
{
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;

    pair <int,int> p[n];
    for(int i = 0; i < n; i++) {
        cin >> p[i].first;
        p[i].second = i;
    }

    int P[n];
    for(int i = 0; i < n; i++) {
        cin >> P[i];
    }

    sort(p, p + n);

    build(1, 0, n - 1);

    int ans[n];

    for(int i = 0; i < n; i++) {
        int h = p[i].first;
        int j = p[i].second;

        int pos = query(1, 0, n - 1, P[j] + 1);

        ans[pos] = j;
        update(1, 0, n - 1, pos, 0);
    }

    for(int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " ";
    }
    cout << "\n";

    return 0;
}
