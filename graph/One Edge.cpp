// https://www.learning.algozenith.com/problems/One-Edge-183

/*

Description

You have given an undirected graph with n nodes, and m edges between them. The goal is to add exactly one edge between two nodes such that the total number of connected components in the graph decreases.
Your task is to find out the number of ways to add such edge.


Input Format

The first input line has two integers n and m: the number of nodes and edges. The nodes are numbered 1, 2, …, n.
After that, there are m lines describing the edges. Each line has two integers a and b: there is an edge between those nodes.
An edge always connects two different nodes, and there is at most one edge between any two nodes.


Output Format

Print the number of ways to add such edge, described in the statement.


Constraints

1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n


Sample Input 1

5 4
1 2
2 3
1 3
4 5

Sample Output 1

6

Sample Input 2

4 3
1 2
2 3
3 4

Sample Input 3

0

Note

Explanation 1:
There are 6 ways to add edge so that the number of connected components in the graph decreases: (1, 4), (1, 5), (2, 4), (2, 5), (3, 4), (3, 5).

Explanation 2:
The given graph is already connected. Even if add any edge, we can't decrease the number of connected components.

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
    for(int i=0;i<comp.size();i++){
        ans+=presum*comp[i];
        presum+=comp[i];
    }
    cout<<ans<<endl;
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
