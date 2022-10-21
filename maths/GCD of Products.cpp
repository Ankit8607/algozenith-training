// https://www.learning.algozenith.com/problems/GCD-of-Products-92

/*

Description

You have to calculate the GCD of N numbers. Since the numbers are too large to be written as numbers, they are written as products of smaller numbers. Find their GCD.


Input Format

The first line of the input contains one integer N - the number of numbers.
Each of the next N lines contains an integer M followed by M space-separated integers, A1, A2,..., AM -  the numbers whose product is the i-th number.
It is guaranteed that the sum of M over all N numbers doesn't exceed 106.


Output Format

Print the GCD on a single line. Since this number might be pretty big, output it modulo 109+7.


Constraints

2≤ N ≤ 106
1≤ M ≤ 106
1≤ Ai ≤ 107


Sample Input 1

3

4 2 3 1 2

3 3 6 2

3 2 4 7


Sample Output 1

4


Note

The first number will be A1 = 2*3*1*2 = 12
The second number will be A2 = 3*6*2 = 36
The third number will be A3 = 2*4*7 = 56

The GCD of these three numbers will be GCD(12, 36, 56) = 4

*/


#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod=1e9+7;

int prime[10000001];
void sieve() {
    for(int i = 1; i < 10000001; ++i) {
        prime[i] = i;
    }
    for(int i = 2; i < 10000001; ++i) {
        if(prime[i] == i) {
            for(int j = i; j < 10000001; j += i) {
                prime[j] = i;
            }
        }
    }
}

int pw (int a, int b, int p) {
    if(b == 0) return 1;
    int t = pw(a, b/2, p);
    t = (t * t) % p;
    if(b % 2) return (a * t) % p;
    return t;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sieve();
    int n;
    cin >> n;
    map<int, int> m1;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        map<int, int> m2;
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            while (x > 1) {
                m2[prime[x]]++;
                x /= prime[x];
            }
        }
        if(i == 0) {
            m1 = m2;
        }
        else {
            for(auto it:m1) {
                m1[it.first] = min(m1[it.first], m2[it.first]);
            }
        }
    }
    int ans = 1;
    for(auto it : m1) {
        ans = (ans * pw(it.first, it.second,mod)) % mod;
    }
    cout << ans;
    return 0;
}
