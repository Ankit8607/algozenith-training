// https://www.learning.algozenith.com/problems/Shortest-Path-I-192

/*

Description

There are n cities and m roads. The capital is located at 1. Your task is to determine the length of the shortest route from the capital to every city.


Input Format

The first input line has two integers n and m: the number of cities and road connections. The cities are numbered 1, 2, …, n, and city 1 is Capital.
After that, there are m lines describing the roads. Each line has three integers a, b and c: a road begins at city a, ends at city b, and its length is c. Each road is a one-way road.
You can assume that it is possible to travel from Capital to all other cities.


Output Format

Print n integers: the shortest route lengths from Capital to cities 1, 2, …, n.


Constraints

1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n
1 ≤ c ≤ 109


Sample Input 1

3 4
1 2 6
1 3 2
3 2 3
1 3 4

Sample Output 1

0 5 2

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

class prioritize{
    public : bool operator()(ii &p1, ii &p2){
        return p1.S>p2.S;
    }
};

int n,m;
vector<ii> g[N];
// int color[N];
vector<int> dx={1,0,0,-1};
vector<int> dy={0,1,-1,0};
int vis[N],c,ans,total;

bool check(int x, int y){
    if(x<0 || x>=n || y<0 || y>=m){ return 0;}
    return 1;
}

// void dfs(int i, int j){
//     // color[node]=parent;
//     c++;
//     vis[i][j]=1;
//     for(int l=0;l<4;l++){
//         int x=i+dx[l];
//         int y=j+dy[l];
//         if(check(x,y) && !vis[x][y] ){
//             if(g[x][y]=='#') dfs(x,y);
//             else{
//                 cnt++;
//             }
//         }
//     }
// }

int dist[N];
void bfs(ii sc){
    dist[sc.F]=0;
    priority_queue<ii,vector<ii>,prioritize>q;
    q.push(sc);
    while(!q.empty()){
        ii cur=q.top(); q.pop();
        if(vis[cur.F]) continue;
        vis[cur.F]=1;
        // int dcur=dist[sc]
        // for(int i=0;i<4;i++){
        //     int x=cur.F+dx[i];
        //     int y=cur.S+dy[i];
        //     if(check(x,y) && g[x][y]=='.' && dist[x][y][parent]>dcur+1){
        //         dist[x][y][parent]=dcur+1;
        //         q.push({x,y});
        //     }
        // }
        for(auto v:g[cur.F]){
            if(dist[v.F]>dist[cur.F]+v.S){
                dist[v.F]=dist[cur.F]+v.S;
                q.push({v.F,dist[v.F]});
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    // g.resize(n+1);
    for(int i=1;i<=n;i++) dist[i]=1e18;
    for(int i=0;i<m;i++){
        int a,b,cost; cin>>a>>b>>cost;
        g[a].push_back({b,cost});
        // g[b].push_back({a,cost});
    }
    bfs(MP(1,0));
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}

signed main(){
    IOS
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}
