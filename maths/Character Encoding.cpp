// https://www.learning.algozenith.com/problems/Character-Encoding-168

/*

Description

Find the number of solutions of following equation.

x1 + x2 + x3 + … + xn = k, satisfying that 0 ≤ xi < m, modulo 1000000007.


Input Format

The only line of input contains three space-separated integers n, m, k.


Output Format

Print the number of solutions.


Constraints

1 ≤ n, m, k ≤ 105


Sample Input 1

2 4 5

Sample Output 1

2

Sample Input 2

20 10 50

Sample Output 2

366736536

Note

For the first test cases, only two solutions exist (2, 3) and (3, 2).

*/


#include<bits/stdc++.h>
using namespace std;

#define ll long long int

const int N = 500010;

int mod = 1e9 + 7;

int power(int a, int b, int M) {
    if(!b) return 1;
    int temp = power(a, b / 2, M);
    temp = 1LL * temp * temp % M;
    if(b % 2) temp = 1LL * temp * a % M;
    return temp;
}

int fact[N];

void pre() {
    fact[0] = 1;
    for(int i = 1; i < N; i++) {
        fact[i] = 1LL * fact[i - 1] * i % mod;
    }
}

int ncr(int n, int r) {
    if(n < r) return 0;
    assert(n >= 0 && n < N && r >= 0 && r < N);
    int ans = fact[n];
    ans = 1LL * ans * power(fact[n - r], mod - 2, mod) % mod;
    ans = 1LL * ans * power(fact[r], mod - 2, mod) % mod;
    if(ans < 0) ans += mod;
    assert(ans >= 0 && ans < mod);
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    pre();
    int n, m, k;
    cin >> n >> m >> k;

    int ans = 0;

    for(int i = 0; i <= n; i++) {
        int temp = ncr(n, i);
        if(n + k - i * m - 1 < n - 1) break;
        temp = 1LL * temp * ncr(n + k - i * m - 1, n - 1) % mod;
        if(temp < 0) temp += mod;
        if(i % 2) ans = (ans - temp + mod) % mod;
        else ans = (ans + temp) % mod;
    }

    assert(ans >= 0 && ans < mod);

    cout << ans << "\n";

    return 0;
}
