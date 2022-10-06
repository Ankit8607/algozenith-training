// https://www.learning.algozenith.com/problems/Edge-Removals-40

/*

Description

You have given an undirected graph G with N nodes, indexed from 1 to N and M edges, indexed from 1 to M.

There are two types of operations:
1 X: Remove the edge numbered X.
2: Print the number of connected components in the graph.


Input Format

The first line of contains three space-separated numbers N, M, Q (1 ≤ N, M, Q ≤ 100000).

The next M lines contain 2 space-separated integers u and v which depicts an edge between nodes u and v (1 ≤ u, v ≤ N). ith line denotes the ith edge.

This is followed by Q lines, each describing an operation in the following format:
1 X: Remove the edge numbered X.
2: Print the number of connected components in the graph.

There are no self-loops or multiple edges in the graph.

Note: If there are multiple queries for removal of the same edge, then the last such query should be considered. Also, the index of the edges does not change after the removal of any of the edges between the nodes.

 


Output Format

The output should consist of the answer to each of the operations of the 2nd type printed on a new line.


Sample Input 1

3 3 5
1 2
2 3
3 1
2
1 2
2
1 1
2
 


Sample Output 1

1
1
2
 


Note

Initially, the graph is connected.
Even after the removal of the 2nd edge, the graph is connected. Now if we remove the 1st edge, node 2 is now isolated. And graph now contains 2 components as {2}, {1, 3}.

*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int mod= 1000000007;
const int N=100010;
#define endl "\n"
#define F first
#define S second
#define MP make_pair
#define ii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n,m,color[N],comp;
vector<int> g[N];

int parent[N],sz[N];
int find(int x){
    if(parent[x]!=x) return parent[x]=find(parent[x]);
    return x;
}

void merge(int a, int b){
    if(sz[a]>=sz[b]){
        parent[b]=a;
        sz[a]+=sz[b];
    }
    else{
        parent[a]=b;
        sz[b]+=sz[a];
    }
}

void solve(){
    int q;
    cin>>n>>m>>q;
    comp=n;
    ii edge[m+1];

    for(int i=1;i<=n;i++){
        parent[i]=i;
        sz[i]=1;
    }
    for(int i=1;i<=m;i++){
        int a,b; cin>>a>>b;
        edge[i]={a,b};
    }
    ii que[q+1];
    vector<int>mark(m+1,0),ans;
    for(int i=1;i<=q;i++){
        int a,b=0; cin>>a;
        if(a==1){
            cin>>b;
            mark[b]=1;
        }
        que[i]={a,b};
    }
    for(int i=1;i<=m;i++){
        if(!mark[i] && find(edge[i].F)!=find(edge[i].S)){
            merge(find(edge[i].F),find(edge[i].S));
            comp--;
        }
    }
    for(int i=q;i>0;i--){
        if(que[i].F==1){
            if( find(edge[que[i].S].F)!=find(edge[que[i].S].S)){
                merge(find(edge[que[i].S].F),find(edge[que[i].S].S));
                comp--;
                // cout<<"q[i].S= "<<que[i].S<<" ";
            }
        }
        else{
            // cout<<"comp= "<<comp<<endl;
            ans.push_back(comp);
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto v:ans) cout<<v<<endl;
}

signed main(){
    IOS
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}
