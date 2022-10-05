// https://www.learning.algozenith.com/problems/Round-Trip-181

/*

Description

Zenithland has n cities and m roads between them. Your task is to check for the existence of a round trip that begins in a city, goes through two or more other cities, and finally returns to the starting city. Every intermediate city on the route has to be distinct.


Input Format

The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1, 2, …, n.
Then, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
Every road is between two different cities, and there is at most one road between any two cities.


Output Format

Print ‘YES’ if such round trip exists, otherwise print ‘NO’.


Constraints

1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n


Sample Input 1

5 6
1 3
1 2
5 3
1 5
2 4
4 5

Sample Output 1

YES

Sample Input 2

4 3
1 2
1 3
3 4

Sample Output 2

NO

*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int mod= 1000000007;
const int N=1000000000;
#define endl "\n"
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n,m;
// vector<vector<int>>g;
// vector<int> dx={0,0,1,-1};
// vector<int> dy={1,-1,0,0};
// void dfs(int i,int j){
//     s[i][j]='1';
//     for(int k=0;k<4;k++){
//         if((i+dx[k]>=0 && i+dx[k]<m) && (j+dy[k]>=0 && j+dy[k]<m) && s[i+dx[k]][j+dy[k]]=='.')
//             dfs(i+dx[k],j+dy[k]);
//     }
// }
void solve(){
    cin>>n>>m;
    // g.resize(n+1);
    vector<int>iso(n+1,0);
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        // g[a].push_back(b);
        // g[b].push_back(a);
        iso[a]=1; iso[b]=1;
    }

    int count=0;
    for(int i=1;i<=n;i++){
        if(!iso[i]) count++;
    }
    n-=count;
    if(m>n-1 and n>2){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(s[i][j]=='.'){
    //             rooms++;
    //             dfs(i,j);
    //         }
    //     }
    // }
}

signed main(){
    IOS
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}
