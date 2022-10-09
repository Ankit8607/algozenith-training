// https://www.learning.algozenith.com/problems/Exponentiation-AZ101-363

/*

Description

You are given four integers - 
A
,
B
,
C
, and 
P
. 
P
 is a prime number.
Find 
A
B
C
%
P
.

NOTE: 
0
0
=
1
.


Input Format

The first line of the input contains one integer 
T
 - the number of test cases. Then 
T
 test cases follow.
The first line of each test case contains four space-separated integers 
A
,
B
,
C
,
P
.


Output Format

For each test case, print  
A
B
C
%
P

Constraints

1
≤
T
≤
2
×
10
5

0
≤
A
,
B
,
C
≤
10
9

2
≤
P
≤
10
4

Sample Input 1

3
2 4 2 7
1 6 20 5
3 1 200 3

Sample Output 1

2
1
0

Note

For the first test case, 
2
4
2
%
7
=
2
16
%
7
=
65536
%
7
=
2
.
For the second test case, 
1
6
20
%
5
=
1
%
5
=
1
.
For the third test case, 
3
1
200
%
3
=
3
1
%
3
=
3
%
3
=
0
.

*/


#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;

inline int mul(int a, int b, int mod) {
  return (int) ((long long) a * b % mod);
}

inline int power(int a, long long b, int mod) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a, mod);
    }
    a = mul(a, a, mod);
    b >>= 1;
  }
  return res;
}



signed main()
{
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int _;
    cin >> _;

    while (_--) {
        int a, b, c, p;
        cin >> a >> b >> c >> p;

        if (b == 0 && c != 0) {
            cout << "1\n";
        }
        else if (!a) {
            cout << "0\n";
        }
        else if (a % p == 0) {
            cout << "0\n";
        }
        else {
            int y = power(b, c, p - 1);
            cout << power(a, y, p) << "\n";
        }
    }
    return 0;
}
