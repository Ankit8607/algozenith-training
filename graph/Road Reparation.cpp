// https://www.learning.algozenith.com/problems/Road-Reparation-191

/*

Description

There are n cities and m roads between them. Unfortunately, the condition of the roads is so poor that they cannot be used. Your task is to repair some of the roads so that there will be a decent route between any two cities.
For each road, you know its reparation cost, and you should find a solution where the total cost is as small as possible.


Input Format

The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1, 2, …, n.
Then, there are m lines describing the roads. Each line has three integers a, b and c: there is a road between cities a and b, and its reparation cost is c. All roads are two-way roads.
Every road is between two different cities, and there is at most one road between two cities.


Output Format

Print one integer: the minimum total reparation cost. However, if there are no solutions, print "IMPOSSIBLE".


Constraints

1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n
1 ≤ c ≤ 109


Sample Input 1

5 6
1 2 3
2 3 5
2 4 2
3 4 8
5 1 7
5 4 4

Sample Output 1

14

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
    // dist[sc]=0;
    priority_queue<ii,vector<ii>,prioritize>q;
    q.push(sc);
    while(!q.empty()){
        ii cur=q.top(); q.pop();
        // cout<<" before= "<<cur.S;
        if(vis[cur.F]) continue;
        // cout<<" after= "<<cur.S<<endl;
        ans+=cur.S; 
        total++;
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
            if(!vis[v.F])
                q.push({v.F,v.S});
        }
        // if(!vis[q.top().F])
        // {
        //     ans+=q.top().S; 
        //     total++;
        // }
    }
}

void solve(){
    cin>>n>>m;
    // g.resize(n+1);
    // for(int i=1;i<=n;i++) g[i]=1e9;
    for(int i=0;i<m;i++){
        int a,b,cost; cin>>a>>b>>cost;
        g[a].push_back({b,cost});
        g[b].push_back({a,cost});
    }
    bfs(MP(1,0));
    if(total==n)
        cout<<ans<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
}

signed main(){
    IOS
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}
