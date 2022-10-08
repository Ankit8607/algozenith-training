// https://www.learning.algozenith.com/problems/Indexed-Set-345

/*

Description

You are given Q queries and have to perform the following operations:

add x - if x doesn't present in the set, add element x in the set. Otherwise do nothing.
remove x - remove element x from the set, if it exists. Otherwise do nothing.
find x - find the value at position x (0-indexing) if it exists. Otherwise print -1.
findpos x - find the position (0-indexing) of the element with value x if it exists. Otherwise, find the position that the element would have in the set
The set is ordered in the non-decreasing order of the elements.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains one integer Q - the number of queries.
Each of the next Q lines contains queries.


Output Format

For each test case, print the required queries.


Constraints

1≤ T ≤ 105
1≤ Q ≤ 105
1≤ x ≤ 105

It is guaranteed that the sum of Q over all test cases does not exceed 106.


Sample Input 1

1
6
add 4
add 1
add 6
find 1
findpos 7
findpos 6

Sample Output 1

4
3
2

Note

Set becomes: [4]
Set becomes: [1, 4]
Set becomes: [1, 4, 6]
S[1] = 4
7 doesn’t exist in set, but if it did set would be: [1, 4, 6, 7] and S[3] = 7
S[3] = 6;

*/


Use insert(x) for inserting element x in the set
Use erase(x) for deleting element x from the set
Use find_by_order(x) for finding the iterator to element with value x
Use order_of_key(x) to find the index of the element x, if x doesn’t exist it finds the position that the element would have in the set
Time Complexity per test case: O(Q * log N)

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
/*
    order_of_key (k)
    find_by_order(k)
*/

signed main()
{
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;

    while(T--) {
        int Q; cin >> Q;

        ordered_set s;

        while(Q--) {
            string op;
            int x;
            cin >> op >> x;

            if(op == "add") {
                s.insert(x);
            }
            else if(op == "remove") {
                if(s.find(x) != s.end()) {
                    s.erase(s.find(x));
                }
            }
            else if(op == "find") {
                if(x >= (int)s.size()) {
                    cout << "-1\n";
                }
                else {
                    cout << *(s.find_by_order(x)) << "\n";
                }
            }
            else {
                cout << s.order_of_key(x) << "\n";
            }
        }
    }
    return 0;
}
