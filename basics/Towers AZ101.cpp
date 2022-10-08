// https://www.learning.algozenith.com/problems/Towers-AZ101-340

/*

Description

You are given N blocks. You have to build towers by placing blocks on top of each other with the condition that the upper block must be smaller than the lower block. You have to process the blocks in the given order. Find the minimum possible number of towers you can create.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the length of the array. 

The second line of each test case contains N space-separated integers.


Output Format

For each test case, print the minimum possible number of towers you can create.


Constraints

1≤ T ≤ 105

1≤ N ≤ 105

1≤ Ai ≤ 109

It is guaranteed that the sum of N over all test cases does not exceed 106.


Sample Input 1

3
5
3 2 5 1 4
4
1 1 1 1
5
5 4 5 3 2 

Sample Output 1

2
4
2

Note

For the first test case, the towers would be: [3, 2, 1] and [5,4]

For the second test case, the towers would be: [1], [1], [1], [1]

For the third test case, the towers would be: [5, 4, 3] and [5, 2]

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
        int n;
        cin >> n;
        multiset<int> s;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            auto it = s.upper_bound(x);
            if(it == s.end()) {
                s.insert(x);
            }
            else {
                s.erase(it);
                s.insert(x);
            }
        }
        cout << s.size() << "\n";
    }
    return 0;
}
