// https://www.learning.algozenith.com/problems/Set-Queries-AZ101-336

/*

Description

You have an empty set and can perform the following operations on it:

1 x - Add integer x to the set
2 x - Find the smallest integer that is not present in the set, which is greater than or equal to x.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer Q - the number of queries. 

Each of the next Q lines contain two space-separated integers ti and xi - type and value of the query.


Output Format

For each test case, print the answer for the queries.


Constraints

1≤ T ≤ 105

1≤ Q ≤ 105

1≤ ti ≤ 2

1≤ xi ≤ 1012

It is guaranteed that the sum of Q over all test cases does not exceed 106.


Sample Input 1

2
4
1 1
1 3
2 1
2 4
3
2 4
1 4
2 4

Sample Output 1

2
4
4
5

Note

For the first test case, the set is [1, 3]. Value which is not present and is ≥ 1 is 2 and ≥ 4 is 4.

For the second test case, the value which is not present and is ≥ 4 is 4. Then set becomes [4]. Value which is not present and is ≥ 4 is 5 now.

*/


// Maintain two sets - one which contains the  values of xi and other which contains xi + 1(erase it afterwards if it comes as xi)

// Time Complexity per test case: O(Q log Q)

 

#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

signed main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;
        set<int> s, ns;
        while (q--) {
            int t, x;
            cin >> t >> x;
            if(t == 1) {
                s.insert(x);
                ns.erase(x);
                if(!s.count(x+1)) {
                    ns.insert(x+1);
                }
            }
            else {
                if(!s.count(x)) {
                    cout << x << "\n";
                }
                else {
                    cout << *ns.lower_bound(x)<<"\n";
                }
            }
        }
    }
    return 0;
}
