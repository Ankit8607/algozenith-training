// https://www.learning.algozenith.com/problems/Multiply-All-GCDs-164

/*

Description

You are given N integers (not necessarily distinct) => A1, A2, A3, ..., AN. There are 2N possible subsets (including the empty subset). 
The GCD of a subset is defined as the greatest common divisor of all the integers in that subset. 
You need to find the product of the GCDs of all the 2N possible subsets you can construct from A. Since the answer can be large, you need to output the answer modulo 1000000007. Do you think you can solve this question?

Note: The greatest common divisor of an empty subset is 1.


Input Format

The first line of input consists of a single integer T denoting the number of test cases. The description of T test cases follow. 
The first line of each test case consists of a single integer N. The second line of each test case consists of N space-separated integers A1, A2, ..., AN.


Output Format

For each test case, output a single integer on a separate line denoting the answer for that test case. Note that you need to output all the values modulo 1000000007 (109 + 7).


Constraints

1 ≤ T ≤ 30
1 ≤ N ≤ 105
1 ≤ Ai ≤ 105


Sample Input 1

3
1
1
2
1 2
3
1 2 2

Sample Output 1

1
2
8

Note

For the first test case, N = 1, and A = [1]. There are 2 possible subsets => {}, {1} and both have a gcd of 1. Hence, the answer is 1 * 1 = 1.

For the second test case, N = 2, and A = [1, 2]. There are 4 possible subsets => {}, {1}, {2}, {1, 2}, having a gcd of 1, 1, 2 and 1 respectively. Hence, the answer is 1 * 1 * 2 * 1 = 2.

For the third test case, N = 3, and A = [1, 2, 2]. There are 8 possible subsets => {}, {1}, {2}, {2}, {1, 2}, {2, 2}, {1, 2}, {1, 2, 2}, having a gcd of 1, 1, 2, 2, 1, 2, 1, 1. Hence, the answer is 1 * 1 * 2 * 2 * 1 * 2 * 1 * 1 = 8.

*/



#include<bits/stdc++.h>
using namespace std;

#define ll long long int

const int N = 100010;

int mod = 1e9 + 7;

int power(int a, int b, int M) {
    if(!b) return 1;
    int temp = power(a, b / 2, M);
    temp = 1LL * temp * temp % M;
    if(b % 2) temp = 1LL * temp * a % M;
    return temp;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n; cin >> n;

        int F[N], S[N], cnt[N];
        memset(F, 0, sizeof(F));
        memset(S, 0, sizeof(S));
        memset(cnt, 0, sizeof(cnt));

        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            cnt[x]++;
        }

        for(int i = 1; i < N; i++) {
            for(int j = i; j < N; j += i) {
                F[i] += cnt[j];
            }
        }

        for(int i = N - 1; i >= 1; i--) {
            S[i] = power(2, F[i], mod - 1) - 1;
            if(S[i] < 0) S[i] += mod - 1;
            for(int j = i + i; j < N; j += i) {
                S[i] = (S[i] - S[j] + (mod - 1)) % (mod - 1);
            }
        }

        int ans = 1;
        for(int i = 1; i < N; i++) {
            assert(S[i] >= 0 && S[i] < mod - 1);
            ans = 1LL * ans * power(i, S[i], mod) % mod;
        }

        assert(ans >= 0 && ans < mod);
        cout << ans << "\n";
    }
    return 0;
}
