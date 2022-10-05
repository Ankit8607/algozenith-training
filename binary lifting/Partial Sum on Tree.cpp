// https://www.learning.algozenith.com/problems/Partial-Sum-on-Tree-452

/*

Description

You are given a tree with N nodes. Initially, all the nodes values is zero. You have to perform Q queries - 3 space-separated integers x, y, z → add z to all the nodes on the shortest path from x to y.

After performing all the queries print the final value of nodes 1,2,….n.


Input Format

The first line contains an integer T (1 ≤ T ≤ 10000) - the number of test cases.

The second line of each test case contains two space-separated integers N (1 ≤ N ≤ 10^5).

The next N-1 lines contain two space-separated integers u, v (1 ≤ u, v ≤ N, u≠v) denoting there is an undirected edge between node u and node v.

The next line contains an integer Q (1 ≤ Q ≤ 10^5).

The next Q lines contain three space-separated integers x, y, z (1 ≤ x, y≤ N, -10^6 ≤ z ≤ 10^6).

Sum of N+Q across all test cases ≤ 2*10^6.


Output Format

For each test case print N space-separated integers denoting the value of node 1,2….n in a new line.


Sample Input 1

2
5
5 4
2 1
3 2
4 2
10
2 5 -8
5 2 -3
4 4 -6
4 3 -1
2 2 3
1 3 6
2 4 -8
4 4 -5
5 3 8
2 1 6
16
13 7
10 6
6 4
8 4
9 4
16 12
14 8
2 1
3 1
12 1
15 10
4 3
11 3
5 2
7 2
36
1 9 32344
16 8 335632
7 14 -184549
4 14 -566786
11 9 -710223
7 4 -902974
12 6 434571
13 14 471558
3 10 642273
3 7 292965
15 4 -643712
15 12 879886
15 8 -307835
15 5 -244965
10 8 612065
11 11 348816
3 6 527481
16 14 567975
12 7 -950446
14 5 -144486
6 7 -283238
6 1 353436
7 4 -748946
11 14 120982
1 12 -923018
13 9 -136443
2 15 564490
6 2 429536
8 7 -384482
1 13 -438491
7 8 -682297
4 2 570947
10 8 724338
4 10 906307
10 10 -968424
2 1 252342

Sample Output 1

12 3 13 -23 -3 
-838653 -2519479 1801473 2232885 -389451 4594633 -3947343 562115 -814322 2164423 -240425 344600 -103376 264694 247864 903607 

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

int n,depth[N],val[N],par[N][20];
vector<int>g[N];

void dfs(int node,int pa,int dep){
	depth[node]=dep;
	par[node][0]=pa;
	for(int i=1;i<20;i++){
		par[node][i]=par[par[node][i-1]][i-1];
	}
	for(auto v:g[node]){
		if(v!=pa){
			dfs(v,node,dep+1);
		}
	}
}
int lca(int u,int v){
	if(depth[v]>depth[u]) swap(u,v);
	int jump=depth[u]-depth[v];
	for(int i=19;i>=0;i--){
		if(jump&(1<<i)) u=par[u][i];
	}
	if(u==v){ 
		return u;
	}
	for(int i=19;i>=0;i--){
		if(par[u][i]!=par[v][i]){
			u=par[u][i];
			v=par[v][i];
		}
	}
	return par[u][0];
}
void push(int node,int pa){
	for(auto v:g[node]) if(v!=pa) push(v,node);
	val[par[node][0]]+=val[node];
}
void solve(){
    cin>>n;
	for(int i=0;i<=n;i++){
		val[i]=0;
		g[i].clear();
		depth[i]=0;
	}
	for(int i=1;i<n;i++){
		int a,b; cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1,0,0);
	int q; cin>>q;
	while(q--){
		int a,b,c; cin>>a>>b>>c;
		val[a]+=c; val[b]+=c;
		int lc=lca(a,b);
		val[lc]-=c;
		val[par[lc][0]]-=c;
	}
	push(1,0);
	for(int i=1;i<=n;i++) cout<<val[i]<<" ";
	cout<<endl;
}

int main(){
    IOS
    int t; cin>>t; while(t--)
    solve();
    return 0;
}
