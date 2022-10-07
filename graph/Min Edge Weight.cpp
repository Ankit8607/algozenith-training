// https://www.learning.algozenith.com/problems/Min-Edge-Weight-37

/*

Description

You are given a weighted tree of N nodes. D(u,v) is defined as the minimum weight of edge in the simple path from u to v.  Find the summation of D(u,v) for all 1≤u≤N, 1≤v≤N, where u<v.


Input Format

The first line of input contains one integer T (1 ≤ T ≤ 105) — the number of test cases. Then T test cases follow.
The first line of each test case contains an integer N - the number of nodes in the tree (1 ≤ N ≤ 105).
The next N-1 line of each test case contains 3 space-separated integers u, v, w  denoting that there is an edge between node u and node v of weight w. (1 ≤ u,v ≤ N), (1 ≤ w ≤ 109 ).

It is guaranteed that the sum of N over all test cases does not exceed 106.


Output Format

For each test case print the summation of D(u,v) for all 1≤u≤N, 1≤v≤N, where u<v in a new line.


Sample Input 1

5
5
1 2 1
2 3 5
3 4 3
4 5 2
5
1 2 5
1 3 4
2 4 1
3 5 2
5
1 2 3
2 3 4
2 4 6
3 5 1
8
1 2 4
2 3 6
2 4 1
2 5 3
3 6 1
3 7 3
3 8 1
10
1 2 10
1 3 5
1 4 9
1 5 7
2 6 10
2 7 11
3 8 9
3 9 11
3 10 15

Sample Output 1

21
23
27
53
316

Note

For the 1st test case:

D(1,2) = D(1,3) = D(1,4) = D(1,5) = 1

D(2,3) = 5, D(2,4) = 3, D(2,5) = 2

D(3,4) = 3, D(3,5) = 2

D(4,5) = 2

Summation = 21

For the second test case:

D(1,2) = 5, D(1,3) = 4, D(1,4) = 1, D(1,5) = 2

D(2,3) = 4, D(2,4) = 1, D(2,5) = 2

D(3,4) = 1, D(3,5) = 2

D(4,5) = 1

Summation = 23

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
int par[N],sz[N];
vector<pair<int,ii>> edge;

int find(int x){
    if(par[x]==x) return x;
    return par[x]=find(par[x]);
}

void merge(int x,int y){
    int xroot=find(x);
    int yroot=find(y);
    if(sz[xroot]>=sz[yroot]){
        par[yroot]=xroot;
        sz[xroot]+=sz[yroot];
    }
    else{
        par[xroot]=yroot;
        sz[yroot]+=sz[xroot];
    }
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        par[i]=i;
        sz[i]=1;
    }
    edge.clear();
    for(int i=1;i<n;i++){
        int a,b,c; cin>>a>>b>>c;
        edge.push_back({c,{a,b}});
    }
    sort(edge.begin(),edge.end());
    reverse(edge.begin(),edge.end());
    int ans =0;
    for(auto v:edge){
        ans+=(v.F)*(sz[find(v.S.F)]*sz[find(v.S.S)]);
        // cout<<"ans= "<<ans<<" ";
        merge(v.S.F,v.S.S);
    }
    cout<<ans<<endl;
}

signed main(){
    IOS
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}
