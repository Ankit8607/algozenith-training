// https://www.learning.algozenith.com/problems/Maximum-Area-AZ101-351

/*

Description

You have a rectangular sheet of paper with dimensions H x W. You make N horizontal and verticals cuts in the sheet. Find the area of the maximum fragment after each cut.

It is guaranteed that there won't be any two identical cuts. Also, The cut that you make in the previous queries persists on the paper for the next queries. 


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains three space-separated integers H W N - the dimensions of the sheet and the number of cuts.

Each of the next N lines is of the form H Y or V X. For H Y, you make a horizontal cut at distance Y from the lower edge of the sheet and for V X, you make a vertical cut at a distance X from the left edges of the sheet.


Output Format

For each test case, print the area of the maximum fragment after each cut.


Constraints

1≤ T ≤ 105

1≤ N ≤ 105

2≤ W, H ≤ 109

1≤ Y ≤ H - 1

1≤ X ≤ W - 1

It is guaranteed that the sum of N over all test cases does not exceed 106.


Sample Input 1

2
5 3 3
H 1
V 1
V 2
3 5 4
H 2
V 2
H 1
V 1

Sample Output 1

12
8
4
10
6
3
3

*/

// Store all the height and width in two multisets. Also store all the horizontal and vertical cut marks in separate sets.

// Time Complexity per test case: O(N * log(W + H))

#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

signed main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int w, h, n;
        cin >> h >> w >> n;
        set<int> hori, verti;
        hori.insert(0);
        hori.insert(h);
        verti.insert(0);
        verti.insert(w);
        multiset<int> w1, h1;
        w1.insert(w);
        h1.insert(h);
        while(n--) {
            char c;
            int x;
            cin >> c >> x;
            if(c == 'H') {
                hori.insert(x);
                auto it = hori.lower_bound(x);
                auto it1 = it, it2 = it;
                it1--; it2++;
                h1.erase(h1.find(*it2 - *it1));
                h1.insert(*it2 - *it);
                h1.insert(*it - *it1);
            }
            else {
                verti.insert(x);
                auto it = verti.lower_bound(x);
                auto it1 = it, it2 = it;
                it1--; it2++;
                w1.erase(w1.find(*it2 - *it1));
                w1.insert(*it2 - *it);
                w1.insert(*it - *it1);
            }
            int ans = (*prev(w1.end())) * (*prev(h1.end()));
            cout << ans << "\n";
        }
    }
    return 0;
}
