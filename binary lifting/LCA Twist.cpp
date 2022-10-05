// https://www.learning.algozenith.com/problems/LCA-Twist-434

/*

Description

Given a tree of N nodes and Q queries - 

. In each query, three nodes are given x, y, z → find the lowest common ancestor of node x and y if z is a root of the tree.


Input Format

The first line contains an integer T (1 ≤ T ≤ 10000) - the number of test cases.

The second line of each test case contains two space-separated integers N (1 ≤ N ≤ 10^5).

The next N-1 lines contain two space-separated integers u, v (1 ≤ u, v ≤ N, u≠v) denoting there is an undirected edge between node u and node v.

The next line contains an integer Q (1 ≤ Q ≤ 10^5).

The next Q lines contain three space-separated integers x, y, z (1 ≤ x, y, z ≤ N).

Sum of N+Q across all test cases ≤ 2*10^6.


Output Format

For each query print the output in a new line.


Sample Input 1

2
8
8 7
2 1
4 1
6 4
7 4
3 2
5 2
43
7 6 8
8 5 8
7 3 4
1 8 2
3 4 4
2 2 3
5 7 6
2 2 5
2 5 6
1 6 3
2 5 5
6 3 4
2 2 4
5 4 8
5 4 4
8 8 8
6 4 7
5 4 7
7 6 3
5 6 4
3 2 8
5 7 2
6 6 6
5 4 3
5 3 2
2 5 3
5 8 3
1 5 7
3 1 2
8 1 2
1 7 4
1 8 7
2 8 3
6 7 8
7 4 1
6 2 3
5 6 1
6 8 5
1 4 2
2 7 4
8 5 5
2 1 4
4 3 6
15
7 3
10 3
11 3
13 11
15 11
9 7
12 9
2 1
3 1
4 1
5 1
8 6
14 6
6 2
19
1 13 4
6 5 9
11 6 10
1 6 6
13 5 10
12 4 7
1 14 1
7 7 2
9 10 4
7 14 12
15 10 1
3 5 12
6 4 13
8 3 13
13 9 10
10 9 3
4 1 5
4 13 8
2 2 1

Sample Output 1

7
8
4
1
4
2
4
2
2
1
5
4
2
4
4
8
4
4
4
4
2
2
6
2
2
2
2
1
2
1
4
7
2
7
4
2
1
4
1
4
5
1
4
1
1
3
6
3
7
1
7
3
7
3
3
1
3
3
3
1
1
2

*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int mod= 1000000007;
const int N=100100;
#define endl "\n"
#define F first
#define S second
#define MP make_pair
#define ii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n,depth[N];
vector<int>g[N];
int par[N][20];

void dfs(int node,int parent,int dep){
	depth[node]=dep;
	par[node][0]=parent;
	for(int i=1;i<20;i++){
		par[node][i]=par[par[node][i-1]][i-1];
	}
	for(auto v:g[node]){
		if(v!=parent){
			dfs(v,node,dep+1);
		}
	}
}
int lca(int u,int v){
	if(depth[u]<depth[v]) swap(u,v);
	int jump=depth[u]-depth[v];
	for(int i=19;i>=0;i--)
		if(jump&(1<<i)) 
			u=par[u][i];
	if(u==v) return u;
	for(int i=19;i>=0;i--){
		if(par[u][i]!=par[v][i]){
			u=par[u][i]; v=par[v][i];
		}
	}
	return par[u][0];
}

void solve(){
    cin>>n;
	for(int i=0;i<=n;i++){
		g[i].clear();
		depth[i]=0;
		for(int j=0;j<20;j++) par[i][j]=0;
	}
	for(int i=1;i<n;i++){
		int a,b; cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	depth[0]=-1;
	dfs(1,0,0);
	int q; cin>>q;
	while(q--){
		int x,y,z; cin>>x>>y>>z;
		int xy=lca(x,y);
		int xz=lca(x,z);
		int yz=lca(y,z);
		// cout<<"hi "<<xy<<" "<<xz<<" "<<yz<<endl;
		if(depth[xy]>max(depth[xz],depth[yz]))
			cout<<xy<<endl;
		else if(depth[yz]>max(depth[xz],depth[xy]))
			cout<<yz<<endl;
		else cout<<xz<<endl;
	}
}

int main(){
    IOS
    int t; cin>>t; while(t--)
    solve();
    return 0;
}
