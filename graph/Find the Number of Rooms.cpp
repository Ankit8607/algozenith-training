// https://www.learning.algozenith.com/problems/Find-the-Number-of-Rooms-178

/*

Description

You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n × m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.


Input Format

The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the map. Each character is either ‘.’ (floor) or '#' (wall).


Output Format

Print one integer: the number of rooms.


Constraints

1 ≤ n, m ≤ 1000


Sample Input 1

5 8
########
#..#...#
####.#.#
#..#...#
########

Sample Output 1

3

*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int mod= 1000000007;
const int N=1000000000;
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int power(int a, int b){
    int ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;     
}
int n,m;
string s[1010];
int rooms;
vector<int> Dx={0,0,1,-1};
vector<int> Dy={1,-1,0,0};
void dfs(int i,int j){
    s[i][j]='1';
    for(int k=0;k<4;k++){
        if((i+Dx[k]>=0 && i+Dx[k]<m) && (j+Dy[k]>=0 && j+Dy[k]<m) && s[i+Dx[k]][j+Dy[k]]=='.')
            dfs(i+Dx[k],j+Dy[k]);
    }
}
void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='.'){
                rooms++;
                dfs(i,j);
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     cout<<s[i];
    //     cout<<endl;
    // }
    cout<<rooms<<endl;
}

signed main(){
    IOS
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}
