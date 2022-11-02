// https://www.learning.algozenith.com/problems/Prime-Cycles-136

/*

Description

Find the number of Prime Cycles with the permutation of first N positive integers. The cycle is called a Prime Cycle if all neighbouring pairs sum up to be a prime. 

The two distinct prime cycles for N = 6 are:

1, 4, 3, 2, 5, 6
1, 6, 5, 2, 3, 4
The permutation of 3, 2, 5, 6, 1, 4 is considered the same as the first sequence.


Input Format

The input contains only a single integer N - denoting the number of positive integers.


Output Format

Print the number of Prime Cycles that are possible to form from first N positive numbers.


Constraints

2 ≤ N ≤ 19


Sample Input 1

2

Sample Output 1

1

Sample Input 2

4

Sample Output 2

2

Sample Input 3

6

Sample Output 3

2

Note

Explanation 1:
One one Prime cycle exists: {1, 2}.

Explanation 2:
Two Prime Cycles are there: {1, 2, 3, 4}, {1, 4, 3, 2}.

Explanation 3:
Two Prime Cycles are there: {1, 4, 3, 2, 5, 6}, {1, 6, 5, 2, 3, 4}.

*/


#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int N = 100;

ll ans = 0;
bool isPrime[N];
bool marked[N];
vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

void solve(int m, int n, int prev, int par) {
    if(!m) {
        if(isPrime[prev + 1]) {
            ans++;
        }
        return;
    }
    for(int i = 1 + par; i <= n; i++) {
        if(!marked[i] && isPrime[i + prev]) {
            marked[i] = true;
            solve(m - 1, n, i, 1 - par);
            marked[i] = false;
        }
    }
    return;
}

signed main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;

    if(n % 2 == 1) {
        cout << "0\n";
        return 0;
    }

    memset(isPrime, false, sizeof(isPrime));
    memset(marked, false, sizeof(marked));

    for(int u : prime) {
        isPrime[u] = true;
    }

    marked[1] = true;
    solve(n - 1, n, 1, 1);

    cout << ans << "\n";
}
