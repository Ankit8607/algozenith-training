// https://www.learning.algozenith.com/problems/Little-Tougher-Queries-383

/*

Description

You've given an array A of length N. You've to answer Q queries. In each query, you'll be given three numbers l, r, k. Your task is to find the kth smallest elements in the subarray Al, Al+1, …, Ar.
It is guaranteed that all elements in the array A will be distinct.


Input Format

The first line of input contains two space-separated integers N, Q - the number of elements and queries.
The second line contains N space-separated numbers A1, A2, …, AN.
Each of the next Q lines contains a pair of integers. The i-th line contains integers li, ri, ki — the description of the i-th query.


Output Format

For each query, print the answer on a new line.


Constraints

1 ≤ N ≤ 105
1 ≤ Ai ≤ 109
1 ≤ Q ≤ 5 x 104
1 ≤ li ≤ ri ≤ N
1 ≤ ki ≤ ri - li + 1


Sample Input 1

7 3
1 5 2 6 3 7 4
2 5 3
4 4 1
1 7 3

Sample Output 1

5
6
3

*/


#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

vector<int> tree[4 * N];
int A[N];

void build(int node, int start, int end) {
    for(int i = start; i <= end; i++) tree[node].push_back(A[i]);
    sort(tree[node].begin(), tree[node].end());
    if(start == end) return;
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
}

int binary(vector<int> &a, int x) {
    int L = 0, R = (int)a.size() - 1;
    int ans = -1;
    while(L <= R) {
        int mid = (L + R) / 2;
        if(a[mid] <= x) {
            ans = mid;
            L = mid + 1;
        }
        else R = mid - 1;
    }
    return ans + 1;
}

int query(int node, int start, int end, int l, int r, int x) {
    if(start > r || end < l) return 0;
    if(start >= l && end <= r) return binary(tree[node], x);
    int mid = (start + end) / 2;
    return query(2 * node, start, mid, l, r, x) + query(2 * node + 1, mid + 1, end, l, r, x);
}

signed main()
{
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;

    for(int i = 0; i < n; i++) cin >> A[i];

    build(1, 0, n - 1);

    while(q--) {
        int l, r, k;
        cin >> l >> r >> k;
        l--; r--;
        int L = 0, R = 1e9;
        int ans = -1;
        while(L <= R) {
            int mid = (L + R) / 2;
            if(query(1, 0, n - 1, l, r, mid) >= k) {
                ans = mid;
                R = mid - 1;
            }
            else L = mid + 1;
        }
        assert(ans != -1);
        cout << ans << "\n";
    }

    return 0;
}
