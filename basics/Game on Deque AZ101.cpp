// https://www.learning.algozenith.com/problems/Game-on-Deque-AZ101-362

/*

Description

You recently learnt to use the C++ STL deque and decided to play a game on it. You are given a deque with N elements. You take the first two elements of the deque, pop them and push the larger of the two in the front and the smaller at the back of the deque. You are given Q queries, asking the first two elements of the deque you will take on the X-th operation. 


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains two space-separated integers N Q - the number of elements in the deque and the number of queries.

The second line of each test case contains N space-separated integers.

Each of the next Q lines contain a single integer X.


Output Format

For each test case, print the first two elements of the deque you will take on the X-th operation for each query. They should be printed in the order in which they will be pulled out of the deque.


Constraints

1≤ T ≤ 105

2≤ N ≤ 105

0≤ Q ≤ 105

0≤ Ai ≤ 109

1≤ Xi ≤ 1018

It is guaranteed that the sum of N and the sum of Q over all test cases does not exceed 106.


Sample Input 1

2
2 1
1 2
1
4 4
1 3 4 4
1
2
3
4

Sample Output 1

1 2
1 3
3 4
4 4
4 1

Note

For the first test case, in operation 1, you take 1 and 2

For the second test case, in operation 1, you take 1 and 3, deque becomes [3, 4, 4, 1]

In operation 2, you take 3 and 4, deque becomes [4, 4, 1, 3]

In operation 3, you take 4 and 4, deque becomes [4, 1, 3, 4]

In operation 4, you take 4 and 1, deque becomes [4, 3, 4, 1]

*/


#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

signed main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        int m = 0;
        deque<int> d;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            d.push_back(x);
            m = max(m, x);
        }
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if(d[i] == m) {
                j = i;
                break;
            }
        }
        vector<pair<int, int>> v;
        v.push_back({0, 0});
        for (int i = 0; i <= j; ++i) {
            int a = d.front();
            d.pop_front();
            int b = d.front();
            d.pop_front();
            v.push_back({a, b});
            if(a > b) {
                d.push_front(a);
                d.push_back(b);
            }
            else {
                d.push_front(b);
                d.push_back(a);
            }
        }
        d.pop_front();
        n--;
        while (q--) {
            int x;
            cin >> x;
            if(x < v.size()) {
                cout << v[x].first << " " << v[x].second << "\n";
            }
            else {
                cout << m << " " << d[(x - v.size())%n] << "\n";
            }
        }
    }
    return 0;
}
