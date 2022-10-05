// https://www.learning.algozenith.com/problems/Creating-Teams-180

/*

Description

There are n students in AlgoZenith Course and m friendships between them. Your task is to divide the students into two teams in such a way that no two students in a team are friends. You can freely choose the sizes of the teams. The size of each team should be positive.


Input Format

The first input line has two integers n and m: the number of students and friendships. The students are numbered 1, 2, …, n.
Then, there are m lines describing friendships. Each line has two integers a and b: students a and b are friends.
Every friendship is between two different students. You can assume that there is at most one friendship between any two students.


Output Format

Print ‘YES’ if it's possible to divide students in two teams, otherwise print ‘NO’.


Constraints

1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n


Sample Input 1

5 3
1 2
1 3
4 5

Sample Output 1

YES

Sample Input 2

4 3
1 2
2 3
1 3

Sample Output 2

NO

*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int mod= 1000000007;
const int N=100005;
#define endl "\n"
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n,m;
vector<vector<int>>g;
bool is_pos=true;
int color[N];
// vector<int> dx={0,0,1,-1};
// vector<int> dy={1,-1,0,0};

// void dfs(int node,int parent){
//     color[node]=parent;
//     for(auto v:g[node]){
//         if(!color[v]){
//             dfs(v,3-color[node]);
//         }
//         else if(color[node]==color[v]){
//             is_pos=false;
//         }
//     }
// }

int dist[N];
void bfs(int st){
    dist[st]=0;
    queue<int>q;
    q.push(st);
    while(!q.empty()){
        int cur=q.front(); q.pop();
        int dcur=dist[cur];
        for(auto v:g[cur]){
            if(dist[v]>dcur+1){
                dist[v]=dcur+1;
                q.push(v);
            }
            else if(dist[v]==dcur) is_pos=false;
        }
    }
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    for(int i=1;i<=n;i++) dist[i]=1e9;
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(dist[i]==1e9) bfs(i);
    }
    if(is_pos) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(s[i][j]=='.'){
    //             rooms++;
    //             dfs(i,j);
    //         }
    //     }
    // }
}

signed main(){
    IOS
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}
