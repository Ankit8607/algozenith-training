// https://www.learning.algozenith.com/problems/Dice-Simulation-AZ101-315

/*

Description

You are given a dice with different values on each face. Find the integer at the top of the face after the sequence of commands to roll the dice is performed. The dice is initially located as shown.


 



Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains six space-separated integers Ai - values on each face.

The second line of each test case contains a string S - the sequence of commands.


Output Format

For each test case, print the integer at the top of the face after the sequence of commands to roll the dice is done.


Constraints

1≤ T ≤ 106

1≤ Ai ≤ 107

1≤ |S| ≤ 106

It is guaranteed that the sum of |S| over all test cases does not exceed 106.


Sample Input 1

3
1 2 3 4 5 6
NE
2 4 5 3 1 7
SWN
3 4 5 6 7 8
SSEN

Sample Output 1

4
2
7

Note

For the first test case, initially 1 is at top, rotating N, 2 is at top, rotating E, 4 is at top.

For the second test case, initially 2 is at top, rotating S, 1 is at top, rotating W, 5 is at top, rotating N, 2 is at top.

For the third test case, initially 3 is at top, rotating S, 7 is at top, rotating S, 8 is at top, rotating E, 6 is at top, rotating N, 7 is at top.

*/


#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ld long double
int mod= 1e9+7;
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
void solve()
{
    int a[7];
    for (int i = 0; i < 6; ++i) {
        cin>>a[i+1];
    }
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] == 'N') {
            int t = a[1];
            a[1] = a[2];
            a[2] = a[6];
            a[6] = a[5];
            a[5] = t;
        }
        else if(s[i] == 'S') {
            int t = a[1];
            a[1] = a[5];
            a[5] = a[6];
            a[6] = a[2];
            a[2] = t;
        }
        else if(s[i] == 'E') {
            int t = a[1];
            a[1] = a[4];
            a[4] = a[6];
            a[6] = a[3];
            a[3] = t;
        }
        else {
            int t = a[1];
            a[1] = a[3];
            a[3] = a[6];
            a[6] = a[4];
            a[4] = t;
        }
    }
    cout << a[1] << "\n";
    
}

signed main(){
    IOS
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}
