// https://www.learning.algozenith.com/problems/Tree-Diameter---I-401

/*

Description

You are given a tree consisting of n nodes. The diameter of a tree is the maximum distance between two nodes. Your task is to determine the diameter of the tree.


Input Format

The first input line contains an integer n: the number of nodes. The nodes are numbered 1, 2, …, n.
Then there are n − 1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.


Output Format

Print the diameter of the tree.


Constraints

1 ≤ n ≤ 2 x 105
1 ≤ a, b ≤ n


Sample Input 1

5
1 2
1 3
3 4
3 5

Sample Output 1

3

Note

The diameter corresponds to the path 2→1→3→5.

*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int mod= 1000000007;
const int N=200100;
#define endl "\n"
#define F first
#define S second
#define MP make_pair
#define ii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

class prioritize{
    public : bool operator()(ii &p1, ii &p2){
        return p1.S>p2.S;
    }
};

int n,m;
vector<int> g[N];
// vector<int> dx={1,0,0,-1};
// vector<int> dy={0,1,-1,0};
int vis[N],dep[N],par[N];

bool check(int x, int y){
    if(x<0 || x>=n || y<0 || y>=m){ return 0;}
    return 1;
}

// dfs for tree
void dfs(int node, int depth, int parent){
    par[node]=parent;
    dep[node]=depth;
    for(auto v:g[node]){
        if(v!=parent)
            dfs(v,depth+1,node);
    }
}

// int dist[N];
// void bfs(ii sc){
//     dist[sc.F]=0;
//     ld time=0;
//     priority_queue<ii,vector<ii>,prioritize>q;
//     q.push(sc);
//     while(!q.empty()){
//         ii cur=q.top(); q.pop();
//         if(vis[cur.F]) continue;
//         vis[cur.F]=1;
        
//     }
// }

void solve(){
    int q;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b,cost; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0,0);
    int node=1;
    for(int i=2;i<=n;i++){
        if(dep[i]>dep[node]) node=i;
    }

    dfs(node,0,0);
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,dep[i]);
    cout<<ans<<endl;
}

signed main(){
    IOS
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}
