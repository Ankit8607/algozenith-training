// https://www.learning.algozenith.com/problems/Time-to-Ski-AZ101-358

/*

Description

You went skiing in a snowy field. You can move along the four directions, north, south, east and west which would be denoted by ‘N’, ‘S’, ‘E’ and ‘W’ respectively. If you move along a previously unvisited segment of path(i.e. this segment of the path is visited the first time), then time to cross it would be 5 second, otherwise time would be 1 second. Find the time you would take to ski given the movements.

Note: A segment is not a Coordinate or cell, rather its a segment between two points. That segment needs to be repeated for change in cost, no just one point.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one string S - the movements of your ski ride. 


Output Format

For each test case, print the time you would take to ski given the movements.


Constraints

1≤ T ≤ 105

1≤ |S| ≤ 105

It is guaranteed that the sum of |S| over all test cases does not exceed 106.


Sample Input 1

3
EEE
NNSE
EW

Sample Output 1

15
16
6

Note

Let’s assume you are at (0,0) at the start.

For the first test case, you go from (0,0) to (1,0) to (2,0) to (3,0). 3 unique segments, so time = 3*5 = 15

For the second test case, you go from (0,0) to (0,1) to (0,2) to (0,1) to (1,1). 3 unique segments and 1 repeated segment [(0,1) to (0,2)], so time = 35 + 11 = 16

For the third test case, you go from (0,0) to (1,0) to (0,0). 1 unique segment and 1 repeated segment [(0,0) to (1,0)], so time = 15 + 11 = 6

*/


#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    string str;
    cin>>str;
    int x=0, y=0;
    int ans=0;
    set<pair<pair<int,int>, pair<int,int>>> s;
    for(int i=0;i<str.size();i++){
        pair<int,int> init = {x,y};
        pair<int,int> fin;
        pair<pair<int,int>, pair<int,int>> one;
        pair<pair<int,int>, pair<int,int>> two;
        if(str[i]=='N'){
            fin = {x,y+1};
        }
        else if(str[i]=='S'){
            fin = {x,y-1};
        }
        else if(str[i]=='E'){
            fin = {x+1,y};
        }
        else{
            fin = {x-1,y};
        }
        one = {init,fin};
        two = {fin,init};
        if(s.find(one)!=s.end()){
            ans+=1;
        }
        else{
            ans+=5;
            s.insert(one);
            s.insert(two);
        }
        x = fin.first;
        y = fin.second;
    }
    cout<<ans<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin>>t; while(t--)
        solve();

    return 0;
}
