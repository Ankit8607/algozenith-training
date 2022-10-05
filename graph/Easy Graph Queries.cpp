// https://www.learning.algozenith.com/problems/Easy-Graph-Queries-374

/*

Description

You have given an undirected graph G with N nodes and M edges. You've to answer Q queries. Each query is either of the following two types:

1 X: Print the size of the connected components containing node X.
2 X Y: Print ‘YES’ (without quotes) if node X and Y belong to the same connected component, else print ‘NO’ (without quotes).

Input Format

The first line of input contains three space-separated integers N, M, and Q (1 ≤ N, M, Q ≤ 105).
Next M lines contain two space-separated integers u and v (1 ≤ u, v ≤ N).
Each of the next Q lines contains queries of one of the types as described in the statement.


Output Format

Print Q lines as the answer to the Q queries, each on a new line.


Sample Input 1

6 5 5
1 2
2 3
1 3
4 4
5 6
1 2
1 4
2 3 4
1 5
2 5 6

Sample Output 1

3
1
NO
2
YES

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
int vis[N];
int c,comp;
void dfs(int node){
    // color[node]=parent;
    c++;
    vis[node]=comp;
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
    cin>>n>>m>>q;
    g.resize(n+1);
    // for(int i=1;i<=n;i++) dist[i]=1e9;
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int compsize[n+1]={0};
    for(int i=1;i<=n;i++){
        if(!vis[i]){ 
            comp++;
            c=0;
            dfs(i);
            compsize[comp]=c;
        }
    }
    for(int i=0;i<q;i++){
        int a; cin>>a;
        if(a==1){
            int x; cin>>x;
            cout<<compsize[vis[x]]<<endl;
        }
        else{
            int x,y; cin>>x>>y;
            if(vis[x]==vis[y]) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    // if(is_pos) cout<<"YES"<<endl;
    // else cout<<"NO"<<endl;
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
