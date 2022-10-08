// https://www.learning.algozenith.com/problems/Maximizing-MEX-AZ101-357

/*

Description

You have an empty array A and a positive integer X. You are given Q queries with an integer Y, which you have to append to the array. In one move, you can change Y as: Y = Y + X or Y = Y - X, Y cannot become negative. You can perform this move multiple times. After each query, find the maximum MEX of the array. 

The MEX of an array is the minimum excluded non-negative integer.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains two space-separated integers Q X - the number of queries and value of X.

Each of the next lines contain one integer Y - the element you have to append in the array.


Output Format

For each test case, print the MEX for each query as space-separated integers.


Constraints

1≤ T ≤ 105

1≤ Q ≤ 105

1≤ X ≤ 105

0≤ Yi ≤ 109

It is guaranteed that the sum of Q over all test cases does not exceed 105.


Sample Input 1

3
4 3
5
3
1
2
5 2
3 
1
2
8
0
3 1
87
32
21

Sample Output 1

0 1 3 3 
0 0 2 4 5 
1 2 3

Note

For the first test case, the given array can be changed to: [2, 0, 1, 5] from [5 3 1 2] , X=3. (all changes are with adding and subtracting X from the numbers).

The mex of [2] is 0
The mex of [2, 0] is 1
The mex of [2, 0, 1] is 3
The mex of [2, 0, 1, 5] is 3

For the second test case, the given array can be changed to: [1, 3, 0, 2, 4]

For the third test case, the given array can be changed to: [0, 1, 2]

*/


#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
         int q, x;
        cin >> q >> x;
        vector<int> v[x];
        set<int> s;
        for (int i = 0; i <= q; ++i) {
            s.insert(i);
        }
        while (q--) {
            int t;
            cin >> t;
            t%=x;
            if (v[t].empty()) {
                v[t].push_back(t);
            }
            else {
                int xx=v[t].back();
                v[t].push_back(xx+x);
                t=xx+x;
            }
            s.erase(t);

            cout << *s.begin() << " ";
        }
        cout << "\n";
    }
    return 0;
}
