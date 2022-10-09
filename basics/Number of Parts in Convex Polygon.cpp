// https://www.learning.algozenith.com/problems/Number-of-Parts-in-Convex-Polygon-68

/*

Description

You have given Convex N-gon. Draw all diagonals of the convex N-gon. Suppose no three diagonals pass through a point.
Into how many parts is the N-gon divided?


Input Format

The first line contains T (1 ≤ T ≤ 100000), the number of test cases.
Each of the next T lines contains a positive integer N denoting the number of sides of convex polygon (3 ≤ N ≤ 109).


Output Format

For each test case, print a single number denoting the number of parts the convex N-gon divided. Since answer can be large, print it with modulo 1000000007.


Sample Input 1

2

4

5


Sample Output 1

4

11


Note



*/


#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 200010;

int inf = 1e9;
int mod = 1e9 + 7;

inline void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}

inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += mod;
}

inline int mul(int a, int b) {
  return (int) ((long long) a * b % mod);
}

inline int power(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

inline int inv(int a) {
  a %= mod;
  if (a < 0) a += mod;
  int b = mod, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += mod;
  return u;
}

int fact[N];

void pre() {
    fact[0] = 1;
    for(int i = 1; i < N; i++)
        fact[i] = mul(fact[i - 1], i);
    return;
}

signed main()
{
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    pre();

    int T; cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int nc2 = mul(n, n - 1); nc2 = mul(nc2, inv(2));
        int nc4 = mul(mul(n, n - 1), mul(n - 2, n - 3)); nc4 = mul(nc4, inv(24));
        int ans = 1;
        add(ans, nc2);
        add(ans, nc4);
        sub(ans, n);
        cout << ans << "\n";
    }

    return 0;
}
