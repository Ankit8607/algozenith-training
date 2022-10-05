// https://www.learning.algozenith.com/problems/Path-GCD-451

/*

Description

Given a tree of N nodes and an array A of length N corresponding to the value of the nodes.

You have to answer Q queries. In each query, two nodes are given x, y→ find the gcd of nodes present on the shortest path from x to y.


Input Format

The first line contains an integer T (1 ≤ T ≤ 10000) - the number of test cases.

The second line of each test case contains two space-separated integers N (1 ≤ N ≤ 10^5).

The next line contains N space-separated integers denoting the value of the nodes. (1 ≤ A[i] ≤ 10^6).

The next N-1 lines contain two space-separated integers u, v (1 ≤ u, v ≤ N) denoting there is an undirected edge between node u and node v.

The next line contains an integer Q (1 ≤ Q ≤ 10^5).

The next Q lines contain three space-separated integers x, y (1 ≤ x, y ≤ N).

Sum of N+Q across all test cases ≤ 2*10^6.


Output Format

For each query print the output in a new line.


Sample Input 1

2
5
2 4 5 10 6
1 2
2 3
3 4
4 5
5
1 2
2 5
4 5
3 4
4 5
5
5 10 15 10 10
1 2
2 3
3 4
3 5
10
1 2
1 3
2 4
2 5
3 5
3 4
4 1
4 5
5 1
2 3

Sample Output 1

2
1
2
5
2
5
5
5
5
5
5
5
5
5
5

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

int n,depth[N],val[N];
vector<int>g[N];
int par[N][20],dp[N][20];

int gcd(int a,int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
void dfs(int node,int parent,int dep){
	depth[node]=dep;
	par[node][0]=parent;
	dp[node][0]=val[node];
	for(int i=1;i<20;i++){
		par[node][i]=par[par[node][i-1]][i-1];
		dp[node][i]=gcd(dp[node][i-1],dp[par[node][i-1]][i-1]);
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
	int ans=0;
	for(int i=19;i>=0;i--)
		if(jump&(1<<i)) 
			ans=gcd(ans,dp[u][i]),
			u=par[u][i];
	if(u==v) return gcd(ans,val[u]);
	for(int i=19;i>=0;i--){
		if(par[u][i]!=par[v][i]){
			ans=gcd(ans,dp[u][i]);
			u=par[u][i]; 
			ans=gcd(ans,dp[v][i]);
			v=par[v][i];
		}
	}
	return gcd(ans,gcd(val[par[u][0]],gcd(val[u],val[v])));
}

void solve(){
    cin>>n;
	for(int i=0;i<=n;i++){
		g[i].clear();
		depth[i]=0;
		for(int j=0;j<20;j++) par[i][j]=0;
	}
	for(int i=1;i<=n;i++) cin>>val[i];
	for(int i=1;i<n;i++){
		int a,b; cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	depth[0]=-1;
	dfs(1,0,0);
	int q; cin>>q;
	while(q--){
		int x,y,z; cin>>x>>y;
		cout<<lca(x,y)<<endl;
	}
}

int main(){
    IOS
    int t; cin>>t; while(t--)
    solve();
    return 0;
}
