// https://www.learning.algozenith.com/problems/Complete-the-Game-406

/*

Description

A game has n levels, connected by m teleporters, and your task is to get from level 1 to level n. The game has been designed so that there are no directed cycles in the underlying graph. In how many ways can you complete the game?


Input Format

The first input line has two integers n and m: the number of levels and teleporters. The levels are numbered 1, 2, …, n.
After this, there are m lines describing the teleporters. Each line has two integers a and b: there is a teleporter from level a to level b.


Output Format

Print one integer: the number of ways you can complete the game. Since the result may be large, print it modulo 109+7.


Constraints

1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n


Sample Input 1

4 5
1 2
2 4
1 3
3 4
1 4

Sample Output 1

3

*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int mod= 1000000007;
const int N=100100;
#define endl "\n"
#define F first
#define S second
#define MP make_pair
#define ii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n,m;
vector<int> g[N];
int indeg[N],ways[N];

void bfs(){
    ways[1]=1;
    queue<int> q;
    for(int i=1;i<n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(auto v:g[x]){
            ways[v]=(ways[v]+ways[x])%mod;
            indeg[v]--;
            if(indeg[v]==0) q.push(v);
        }
    }
}

void solve(){
   cin>>n>>m;
//    for(int i=1;i<=n;i++) par[i]=i;
   for(int i=1;i<=m;i++){
       int a,b; cin>>a>>b;
       g[a].push_back(b);
       indeg[b]++;
   }
   bfs();
   cout<<ways[n]%mod<<endl;
}

signed main(){
    IOS
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}
