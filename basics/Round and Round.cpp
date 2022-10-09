// https://www.learning.algozenith.com/problems/Round-and-Round-88

/*

Description

Bob is standing in a park at (0,0) facing north. He is given a series of instructions to move around the park. The instructions can be:

‘W’: go straight 1 unit
‘L’: turn 90 degrees left
‘R’: turn 90 degrees right
Bob has to perform the given instructions forever. If he is going in a circle forever, print ‘YES’. Otherwise, print ‘NO’ (without the quotes).


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains N - the length of the input string of instructions.
The second line of each test case contains one string S - the series of instructions to move around the park.


Output Format

For each test case, print ‘YES’ if Bob is going in a circle forever. Otherwise, print ‘NO’. (without the quotes)


Constraints

1≤ T ≤ 100
1≤ |S| ≤ 105 where |S| denotes the length of the given series of instructions.


Sample Input 1

3

3

WWW

2

LW

4

WLLW


Sample Output 1

NO

YES

YES


Note

In the first sample test case, Bob moves north indefinitely.

In the second sample test case, Bob moves as follows: (0,0) => (-1,0) => (-1,-1) => (0,-1) => (0,0). So, Bob goes in a circle forever


In the third sample test case, Bob moves from (0,0) to (0,1) turns 180 degress and returns to (0,0). So, Bob goes in a circle forever

*/


#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    IOS
    int t;
    cin >> t;
    vector<int> moves[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while(t--) {
        int n; cin >> n;
        string s;
        cin >> s;
        int x = 0, y = 0, dir = 0;
        for(char i : s) {
            if(i == 'L') {
                dir = (dir - 1 + 4) % 4;
            }
            else if(i == 'R') {
                dir = (dir + 1) % 4;
            }
            else{
                x += moves[dir][0];
                y += moves[dir][1];
            }
        }
        if(x==0 && y==0) cout << "YES\n";
        else if(dir != 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
