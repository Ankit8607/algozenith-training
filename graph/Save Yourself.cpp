// https://www.learning.algozenith.com/problems/Save-Yourself-182

/*

Description

You and some monsters are in a matrix. When taking a step to some direction in the matrix, each monster may simultaneously take one as well. Your goal is to reach one of the boundary squares without ever sharing a square with a monster.
Your task is to find out if your goal is possible, and if it is, print the shortest length of the path that you can follow. Your plan has to work in any situation; even if the monsters know your path beforehand.


Input Format

The first input line has two integers n and m: the height and width of the matrix.
After this, there are n lines of m characters describing the matrix. Each character is ‘.’ (floor), ‘#’ (wall), ‘A’ (start), or ‘M’ (monster). There is exactly one ‘A’ in the input.


Output Format

First, print "YES" if your goal is possible, and "NO" otherwise.
If your goal is possible, also print the length of the shortest path that you'll follow.


Constraints

1 ≤ n, m ≤ 1000


Sample Input 1

5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######

Sample Output 1

YES
5

Sample Input 2

3 3
###
#A#
#M.

Sample Output 2

NO

Sample Input 3

1 3
##A

Sample Output 3

YES
0

*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int mod= 1000000007;
const int N=1010;
#define endl "\n"
#define F first
#define S second
#define MP make_pair
#define ii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n,m;
string g[N];
// bool is_pos=true;
// int color[N];
vector<int> dx={1,0,0,-1};
vector<int> dy={0,1,-1,0};
int vis[N][N],c,cnt=0,parent;

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

int dist[N][N][2];
void bfs(queue<ii>q){
    // dist[st]=0;
    // queue<int>q;
    // q.push(st);
    while(!q.empty()){
        ii cur=q.front(); q.pop();
        int dcur=dist[cur.F][cur.S][parent];
        for(int i=0;i<4;i++){
            int x=cur.F+dx[i];
            int y=cur.S+dy[i];
            // cout<<" x= "<<x<<" y= "<<y;
            if(check(x,y) && g[x][y]=='.' && dist[x][y][parent]>dcur+1){
                dist[x][y][parent]=dcur+1;
                q.push({x,y});
                // cout<<" YES "<<endl;
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    queue<ii>mons;
    queue<ii>A;
    // g.resize(n+1);
    // for(int i=1;i<=n;i++) dist[i]=1e9;
    for(int i=0;i<n;i++){
        // int a,b; cin>>a>>b;
        cin>>g[i];
        for(int j=0;j<m;j++){
            dist[i][j][0]=1e9; dist[i][j][1]=1e9;
            if(g[i][j]=='M') mons.push({i,j}), dist[i][j][0]=0;
            else if(g[i][j]=='A') A.push({i,j}), dist[i][j][1]=0;
        }
        // g[a].push_back(b);
        // g[b].push_back(a);
    }

    bool isp=false;
    int ans=1e9;
    parent=0;
    bfs(mons);
    parent=1;
    bfs(A);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || i==n-1){
                if(dist[i][j][1]<dist[i][j][0])
                    isp=true,ans=min(ans,dist[i][j][1]);
            }
            else if(j==0 || j==m-1){
                if(dist[i][j][1]<dist[i][j][0])
                    isp=true, ans=min(ans,dist[i][j][1]);
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<dist[i][j][0]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<dist[i][j][1]<<" ";
    //     }
    //     cout<<endl;
    // }

    if(isp) cout<<"YES"<<endl<<ans<<endl;
    else cout<<"NO"<<endl;
}

signed main(){
    IOS
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}
