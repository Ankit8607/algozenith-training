// https://www.learning.algozenith.com/problems/LR-Power-Sum-Query-21

/*

Description

Given an array of N integers, Q queries, and an integer K. In each query two integers L, R is given, you have to find (A[L] + A[L+1] * K + A[L+2] * K^2 + …. A[R] * K^(R-L))% 10^9+7.


Input Format

The first line contains three space-separated integers N, Q, K where 1<=N<=10^6, 1<=Q<=10^6, 1<=K<=10^9.

Next line contains N space-separated integers (-1e9<=Ai<=1e9).

Next Q lines contain two space-separated integers L, R where 1<=L<=R<=N.


Output Format

For each query print the value of (A[L] + A[L+1] * K + A[L+2] * K^2 + …. A[R] * K^(R-L))% 10^9+7 in a new line.


Sample Input 1

10 10 234565
12 -23 -123 2345 2345 44 345 -93945 -5353 1
1 5
1 8
1 10
2 2
6 6
4 8
2 9
4 10
3 6
5 9

Sample Output 1

644011223
645979052
534876628
999999984
44
725883751
503173837
859246404
845338365
605774687

*/


#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
ll power(ll x,ll y)
{
    ll res = 1;
    while(y)
    {
        if(y&1) 
            res = (res*x)%mod;
        y=y/2,x=(x*x)%mod;
    }
    return res%mod;
}
const int N = 1000001;
ll powerK[N];
ll arr[N];
ll prefixSum[N];
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,q,k;
    cin>>n>>q>>k;
    powerK[0] = 1;
    for(int i=1;i<=n;i++)
        powerK[i] = k*powerK[i-1]%mod;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        arr[i] = arr[i]*powerK[i]%mod;
        if(arr[i]<0)
            arr[i]+=mod;
    }
    prefixSum[0] = 0;
    for(int i=1;i<=n;i++){
        prefixSum[i] = prefixSum[i-1]+arr[i];
        if(prefixSum[i]>=mod)
            prefixSum[i]-=mod;
    }
    while(q--){
        ll l,r;
        cin>>l>>r;
        ll ans = prefixSum[r]-prefixSum[l-1];
        if(ans<0)
            ans+=mod;
        ans = ans*power(powerK[l],mod-2)%mod;
        cout<<ans<<"\n";
    }
}
