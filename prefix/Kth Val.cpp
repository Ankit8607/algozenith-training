// https://www.learning.algozenith.com/problems/Kth-Val-33

/*

Description

You have been given an array A of N integers and M ranges. ith range is defined by the two integers li and ri, li≤ri.

Initially, array S is empty. For range i, add elements A[li],A[li+1]…..A[ri] in the array S. After adding all the elements in each of the range, sort the elements of S in ascending order.

You need to answer Q queries. Each query consists of a number K > 0. You have to find the Kth smallest element in S, i.e., the element at Kth position in sorted S.

It may be possible that the same element presents multiple times in S.


Input Format

The first line of the input contains a single integer T - the number of test cases(1 ≤ T ≤ 10). Then T test cases follow.

The first line of each test case contains three integers N, M, and Q, (1 ≤ N, M, Q ≤ 10^5).

The second line contains N space-separated integers A1, A2,….,AN, the elements of the array A, (1≤Ai≤10^9).

Next M lines contain two space-separated integers li and ri - ith range, (1 ≤ li ≤ ri ≤ N).

The last line of a test case contains Q space-separated integers K1, K2,….,KQ, where Ki denotes the ith query. (1 ≤ Ki ≤1 0^18).


Output Format

For each test case, print Q space-separated integers, where ith number denotes the answer of ith query. If the Kth value doesn't exist for a particular query, print -1.


Sample Input 1

2
3 3 4
1 3 2
1 3
2 3
1 1
1 2 5 8
4 2 3
1 5 4 3
1 4
1 3
1 5 7

Sample Output 1

1 1 3 -1
1 4 5

Note

Test Case 1: Initially array S is empty.

Add the 1st range -> S = {1,3,2}.

Add the 2nd range -> S = {1,3,2,3,2}

Add the 3rd range -> S = {1,3,2,3,2,1}

After sorting the array, S = {1,1,2,2,3,3}

For K = 8, the 8th element doesn't exist in the atta S. So the answer of the 4th query is -1.

Test Case 2: Initially array S is empty.

Add the 1st range -> S = {1,5,4,3}.

Add the 2nd range -> S = {1,5,4,3,1,5,4}.

After sorting the array, S = {1,1,3,4,4,5,5}.

*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

signed main()
{
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int _; cin >> _;
    while(_--) {
        int n, m, q;
        cin >> n >> m >> q;
        pair<int,int> A[n];
        for(int i = 0; i < n; i++) {
            cin >> A[i].first;
            A[i].second = 0;
        }
        for(int i = 0; i < m; i++) {
            int l, r; cin >> l >> r;
            l--; r--;
            A[l].second++;
            if(r + 1 < n) A[r + 1].second--;
        }
        for(int i = 1; i < n; i++)
            A[i].second += A[i - 1].second;

        sort(A, A + n);

        int ans[q];
        pair<ll,int> Q[q];
        for(int i = 0; i < q; i++) {
            cin >> Q[i].first;
            Q[i].second = i;
        }

        sort(Q, Q + q);

        int ptr = 0;
        ll sum = 0;

        for(int i = 0; i < q; i++) {
            ll x = Q[i].first;
            while(ptr < n && sum + A[ptr].second < x) {
                sum += A[ptr].second;
                ptr++;
            }
            if(ptr < n) ans[Q[i].second] = A[ptr].first;
            else ans[Q[i].second] = -1;
        }

        for(int i = 0; i < q; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}
