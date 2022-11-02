// https://www.learning.algozenith.com/problems/Count-Valid-Grid-Paths-257

/*

Description

There are 88418 paths in a 7×7 grid from the upper-left square to the lower-left square. Each path corresponds to a 48-character description consisting of characters D (down), U (up), L (left) and R (right).

For example, the path


corresponds to the description DRURRRRRDDDLUULDDDLDRRURDDLLLLLURULURRUULDLLDDDD.

You are given a description of a path which may also contain characters ? (any direction). Your task is to calculate the number of paths that match the description.


Input Format

The only input line has a 48-character string of characters ?, D, U, L and R.


Output Format

Print one integer: the total number of paths.


Sample Input 1

??????R??????U??????????????????????????LD????D?

Sample Output 1

201



*/


#include<bits/stdc++.h>
using namespace std;
 

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

 

#define pll pair<ll,ll> 
#define vll vector<ll> 
#define mll map<ll,ll>
#define MP        make_pair
#define ff        first
#define ss        second

 

#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define fr(i,a) rep(i,0,a)
#define per(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ROF(i,a) per(i,0,a)

 

#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define all1(x) bg(x)+1,end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define sor1(x) sort(all1(x))
#define pb push_back
#define ins insert
#define EL cout<<"\n";
#define REV(x) reverse(all(x))
 

#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl "\n"
#define ppb pop_back
#define PI 3.141592653589793238462
//#define MOD2 1000000009
 

 

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

 

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

 

 

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

 

void printvector(vector<ll> V){
    for(auto i:V){
        cout<<i<<" ";
    }
    cout<<endl;
}
// 
 
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag,
// tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;



// derangement theorem recurrence relation //  D(N)=(N-1)*(DP[I-1]+DP[I-2])

ll testcase;
/*-----------------------M I S T R Y-------------------------------*/
ll dx[]={1,0,-1,0};
ll dy[]={0,1,0,-1};
 

 bool compare( pair<ll,ll> &a, pair<ll,ll> &b)
 {
    return a.second>b.second;
 }

// ll fact(ll n)
// {
//     return (n*(n-1))/2;
// } 
// //ll n,m;
// vector<vector<ll>> g;
// vector<ll> comp;

// void dfs(ll node,ll cnt)
// {
//     comp[node]=cnt;
//     for(auto v:g[node])
//     {
//         if(!comp[v])
//         {
//             dfs(v,cnt);
//         }
//     }
// }
ll binpow(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=(ans*a)%MOD;
        }
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans;

}


ll pw(ll a,ll b,ll m)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=(ans*a)%m;
        }
        a=(a*a)%m;
        b>>=1;
    }
    return ans;

}

ll inverse(ll x){
    ll res = 1;
    ll expo = MOD-2;
    while(expo > 0){
        if(expo%2==1)
            res = (res * x) % MOD;
        x = (x * x) % MOD;
        expo/=2;
    }
    return res;
}

ll visited[7][7];
string s;
ll ans;
//?, D, U, L and R.
void rec(ll curr,ll x,ll y)
{
    if(x==6 && y==0)
    {
        //if(curr>1)
        //cerr<<curr<<endl;
        if(curr==48)
        {
            ans++;
        }
        return;
    }
    
    if(((x+1==7 || (visited[x-1][y] && visited[x+1][y])) && y+1<7 && y-1>=0 && !visited[x][y-1] && !visited[x][y+1]) ||
        ((y+1==7 || (visited[x][y-1] && visited[x][y+1])) && x+1<7 && x-1>=0 && !visited[x+1][y] && !visited[x-1][y]) ||
         ((x==0 || (visited[x+1][y] && visited[x-1][y])) && y+1<7 && y-1>=0 && !visited[x][y-1] && !visited[x][y+1]) ||
         ((y==0 || (visited[x][y+1] && visited[x][y-1])) && x+1<7 && x-1>=0 && !visited[x+1][y] && !visited[x-1][y]))
    {
        return;
    }
    visited[x][y]=1;
    



    if(s[curr]!='?')
    {
    if(s[curr]=='D')
    {
        if(x+1>=0 && x+1<7 && visited[x+1][y]==0)
        {
          //  visited[x+1][y]=1;
            rec(curr+1,x+1,y);
            //visited[x+1][y]=0;
        }
    }
    else if(s[curr]=='U')
    {
        if(x-1>=0 && x-1<7 && visited[x-1][y]==0)
        {
           // visited[x-1][y]=1;
            rec(curr+1,x-1,y);
            //visited[x-1][y]=0;
        }
    }
    else if(s[curr]=='L')
    {
        if(y-1>=0 && y-1<7 && visited[x][y-1]==0)
        {
            //visited[x][y-1]=1;
            rec(curr+1,x,y-1);
           // visited[x][y-1]=0;
        }
    }
    else if(s[curr]=='R')
    {
        if(y+1>=0 && y+1<7 && visited[x][y+1]==0)
        {
            //visited[x][y+1]=1;
            rec(curr+1,x,y+1);
           // visited[x][y+1]=0;
        }
    }
    visited[x][y]=0;
    return; 
   }
    if(s[curr]=='?')
    {
        for(int i=0;i<4;i++)
        {
            ll nx=dx[i]+x;
            ll ny=dy[i]+y;
            if(nx>=0 && ny>=0 && nx<7 && ny<7 && visited[nx][ny]==0)
            {
                //visited[nx][ny]=1;
                rec(curr+1,nx,ny);
                //visited[nx][ny]=0;
            }
        }
        visited[x][y]=0;
        return;
    }
   // return;
}


void solve()
{
    ans=0;
    memset(visited,0,sizeof(visited));
   //string s;
   cin>>s;
   rec(0,0,0);
   cout<<ans<<endl;

}
 


int main(){

 

#ifndef ONLINE_JUDGE
    freopen("error.txt","w",stderr);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    //T=1;
    // memset(sieve,true,sizeof(sieve));
    // //cerr<<sieve[101]<<endl;
    // for(ll i=2;i*i<100;i++)
    // {
    //     if(sieve[i]==1)
    //     {
    //     for(ll j=i*i;j<100;j+=i)
    //     {
    //         sieve[j]=0;
    //     }
    //    }
    // }
    ll T;
   // cin>>T;
    T=1;
    testcase=1;
    while(T--){
        solve();
        testcase++;
    }
    return 0;
}
