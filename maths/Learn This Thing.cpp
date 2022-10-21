// https://www.learning.algozenith.com/problems/Learn-This-Thing-189

/*

Description

For a given n, find the number of even and odd numbers among the set, { nC0, nC1,... nCn }.


Input Format

First-line contains T (1 ≤ T ≤ 105), the number of test cases. Next T lines contain one integer per line, denoting n (0 ≤ n ≤ 1012). 


Output Format

For each test case, output two space-separated integers specifying the number of even numbers and odd numbers respectively.


Sample Input 1

2
3
4

Sample Output 1

0 4
3 2

Note

For 3, values are: 1 3 3 1. All are odd. Hence 0 4.
For 4, values are: 1 4 6 4 1. Hence 3 2.

*/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--) {
        ll n; cin >> n;
        ll ans = 1;
        for(ll i = 0; i < 64; i++) {
            if((n >> i) & 1) {
                ans *= 2;
            }
        }
        cout << n + 1 - ans << " " << ans << "\n";
    }
}
