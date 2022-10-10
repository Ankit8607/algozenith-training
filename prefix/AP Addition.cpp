// https://www.learning.algozenith.com/problems/AP-Addition-28

/*

Description

Given an array of N integers and Q queries. Initially, all the elements of the array have value 0.

In each query 4 integers A, D, L, R is given, which means perform AP addition

Arr[L]+=A

Arr[L+1]+=A+D

Arr[L+2]+=A+2D

Arr[L+3]+=A+3D

.

.

.

.

Arr[R]+=A+(R-L)*D.

After performing all the operations. Print the final array % 10^9+7.


Input Format

The first line contains two space-separated integers N, Q where 1<=N<=10^6, 1<=Q<=10^6.

Next Q lines contain four space-separated integers A, D, L, R where 0<=A,D<=10^4, 1<=L<=R<=N.


Output Format

Print the N space-separated integer representing the final array %10^9+7.


Sample Input 1

5 5
1 3 1 5
2 4 2 2
5 6 3 5
6 9 5 5
1 4 2 4

Sample Output 1

1 7 17 30 36 

*/


#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

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


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    int A[n + 2], D[n + 2];
    memset(A, 0, sizeof(A));
    memset(D, 0, sizeof(D));

    while(q--) {
        int a, d, l, r;
        cin >> a >> d >> l >> r;
        add(D[l], d); sub(D[r + 1], d);
        add(A[l], a); sub(A[r + 1], a);
        sub(A[l], mul(l, d)); add(A[r + 1], mul(l, d));
    }

    for(int i = 1; i <= n; i++) {
        add(A[i], A[i - 1]);
        add(D[i], D[i - 1]);
        int ans = A[i];
        add(ans, mul(D[i], i));
        cout << ans << " ";
    }
    cout << "\n";
    return 0;
}
