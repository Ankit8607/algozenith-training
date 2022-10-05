// https://www.learning.algozenith.com/problems/Colour-Tree-390

/*

Description

You have been given a tree with N nodes and N - 1 edges. You want to colour each node, such that no two adjacent nodes (directly connected by an edge) and no two nearly-adjacent nodes (both directly connected to a common node with edges) has the same colour. 
Your task is to find the minimum number of colours required to accomplished this. 


Input Format

The first line of input contains N. Each of the remaining N−1 lines describes an edge in terms of the two nodes it connects.


Output Format

Print the minimum number of colours require.


Constraints

1 ≤ N ≤ 105


Sample Input 1

4
1 2
4 3
2 3

Sample Output 1

3

Note

We require 4 different colours, colour(1) = 1, colour(2) = 2, colour(3) = 3, colour(4) = 1.

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

int n,m,k;
vector<vector<int>>g;
int grid[101][10];
// bool is_pos=true;
// int color[N];
vector<int> dx={0,0,1,-1};
vector<int> dy={1,-1,0,0};
int vis[101][10],c;

bool check(int x, int y){
    if(x<0 || x>=10 || y<0 || y>=n) return 0;
    return 1;
}

void dfs(int i, int j, int pari){
    // color[node]=parent;
    c++;
    if(pari)
    vis[i][j]=1;
    for(int l=0;l<4;l++){
        if(check(i+dx[l],j+dy[l]) && grid[i+dx[l]][j+dy[l]]==grid[i][j]){
            dfs(i+dx[l],j+dy[l],1);
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
    cin>>n;
    // g.resize(n+1);
    // for(int i=1;i<=n;i++) dist[i]=1e9;
    int deg[n+1]={0};
    int ans=0;
    for(int i=0;i<n-1;i++){
        int a,b; cin>>a>>b;
        // g[a].push_back(b);
        // g[b].push_back(a);
        deg[a]++; deg[b]++;
    }
    for(int i=0;i<n;i++) ans=max(ans,deg[i]);
    cout<<ans+1<<endl;
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
