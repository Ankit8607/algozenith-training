// https://www.learning.algozenith.com/problems/Building-Roads-179
/*

Description

Zenithland has n cities and m roads between them. The goal is to construct new roads so that there is a route between any two cities. A road is bidirectional.
Your task is to find out the minimum number of roads required.


Input Format

The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1, 2, …, n.
After that, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
A road always connects two different cities, and there is at most one road between any two cities.
 


Output Format

Print the number of minimum roads required.


Constraints

1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n


Sample Input 1

4 2
1 2
3 4

Sample Output 1

1

Note

Construct a road between cities 1 and 3.

*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int mod= 1000000007;
const int N=100005;
#define endl "\n"
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n,m;
vector<vector<int>>g;
// bool is_pos=true;
// int color[N];
// vector<int> dx={0,0,1,-1};
// vector<int> dy={1,-1,0,0};
int vis[N],c;
void dfs(int node){
    // color[node]=parent;
    c++;
    vis[node]=1;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

// int dist[N];
// void bfs(int st){
//     dist[st]=0;
//     queue<int>q;
//     q.push(st);
//     while(!q.empty()){
//         int cur=q.front(); q.pop();
//         int dcur=dist[cur];
//         for(auto v:g[cur]){
//             if(dist[v]>dcur+1){
//                 dist[v]=dcur+1;
//                 q.push(v);
//             }
//             else if(dist[v]==dcur) is_pos=false;
//         }
//     }
// }

void solve(){
    int q;
    cin>>n>>m;
    g.resize(n+1);
    // for(int i=1;i<=n;i++) dist[i]=1e9;
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int>comp;
    for(int i=1;i<=n;i++){
        if(!vis[i]){ 
            c=0;
            dfs(i);
            comp.push_back(c);
        }
    }
    int ans=0,presum=0;
    cout<<(int)comp.size()-1<<endl;
    // if(is_pos) cout<<"YES"<<endl;
    // else cout<<"NO"<<endl;
}

signed main(){
    IOS
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}
