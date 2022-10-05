// https://www.learning.algozenith.com/problems/Area-and-Perimeter-of-Connected-Components-396

/*

Description

You have been given a grid of size N x N. Each cell is either empty (.) or occupied (#). Size of each cell is 1 x 1. In the connected component, you can reach any cell from every other cell in the component by repeatedly stepping to adjacent cells in the north, south, east, and west directions. 
Your task is to find the area and perimeter of the connected component having the largest area. The area of a connected component is just the number of '#' characters that are part of it. If multiple connected components tie for the largest area, find the smallest perimeter among them.


Input Format

The first line of input contains N, and the next N lines describe the grid. At least one '#' character will be present.


Output Format

Please output one line containing two space-separated integers, the first being the area of the largest connected component, and the second being its perimeter. If multiple connected components tie for the largest area, print the one which has the smallest perimeter among them.


Constraints

1 ≤ N ≤ 1000


Sample Input 1

6
##....
....#.
.#..#.
.#####
...###
....##

Sample Output 1

13 22

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
// #define ii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n,m;
string g[N];
// bool is_pos=true;
// int color[N];
vector<int> dx={0,0,1,-1};
vector<int> dy={1,-1,0,0};
int vis[N][N],c,cnt=0;

bool check(int x, int y){
    if(x<0 || x>=n || y<0 || y>=n ){ cnt++; return 0;}
    return 1;
}

void dfs(int i, int j){
    // color[node]=parent;
    c++;
    vis[i][j]=1;
    for(int l=0;l<4;l++){
        int x=i+dx[l];
        int y=j+dy[l];
        if(check(x,y) && !vis[x][y] ){
            if(g[x][y]=='#') dfs(x,y);
            else{
                cnt++;
            }
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
    for(int i=0;i<n;i++){
        // int a,b; cin>>a>>b;
        cin>>g[i];
        // g[a].push_back(b);
        // g[b].push_back(a);
    }
    int marea=0, mperi=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[i][j]=='#' && !vis[i][j]){
                c=0; cnt=0;
                dfs(i,j);
                if(marea<c){
                    marea=c;
                    mperi=cnt;
                }
                else if(marea==c && mperi>cnt){
                    mperi=cnt;
                }
            }
        }
    }
    cout<<marea<<" "<<mperi<<endl;
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
