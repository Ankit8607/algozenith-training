// https://www.learning.algozenith.com/problems/Tree-Diameter---II-402

/*

Description

You are given a tree consisting of n nodes. The diameter of a tree is the maximum distance between two nodes. Your task is to count the number of different diameters of the tree.


Input Format

The first input line contains an integer n: the number of nodes. The nodes are numbered 1, 2, …, n.
Then there are n − 1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.


Output Format

Print the count of diameters of the tree.


Constraints

1 ≤ n ≤ 2 x 105
1 ≤ a, b ≤ n


Sample Input 1

5
1 2
1 3
3 4
3 5

Sample Output 1

2

Note

Two diameters are:

2 → 1 → 3 → 4
2 → 1 → 3 → 5

*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200100;
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n;
vector<int> g[N];
int dep[N],par[N],dia,c;
vector<int>cnt;

// dfs for tree
void dfs(int node, int depth, int parent){
    par[node]=parent;
    dep[node]=depth;
    for(auto v:g[node]){
        if(v!=parent){
            dfs(v,depth+1,node);
        }
    }
    if(dia){
        if(dep[node]==dia/2){
            c++;
        }
    }
}

void solve(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if(n<=2){
        cout<<1<<endl;
        return;
    }
    dfs(1,0,0);
    int starting_node=1;
    for(int i=2;i<=n;i++){
        if(dep[i]>dep[starting_node]) starting_node=i;
    }

    dfs(starting_node,0,0);
    int end=starting_node;
    for(int i=1;i<=n;i++){
        if(dep[i]>dia){
            dia=dep[i];
            end=i;
        }
    }
    
    vector<int>center;
    int p=par[end];
    while(p!=starting_node){
        if(dep[p]==(dia/2) || dep[p]==ceil(dia/2.0)){
            center.push_back(p);
        }
        p=par[p];
    }

    if(dia%2==0){
        int c1=center[0];
        for(auto v:g[c1]){
            c=0;
            dfs(v,1,c1);
            cnt.push_back(c);
        }
        int total=0, presum=0;
        for(auto v:cnt){
            total+=presum*v;
            presum+=v;
        }
        cout<<total<<endl;
    }
    else{
        int c1=center[0],c2=center[1];
        c=0;
        dfs(c1,0,c2);
        int mul1=c,mul2;
        c=0;
        dfs(c2,0,c1);
        mul2=c;
        cout<<mul1*mul2<<endl;
    }
}

signed main(){
    IOS
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}
