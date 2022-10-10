// https://www.learning.algozenith.com/problems/Multiply-Sum-Query-35

/*

Description

Given an array of N integers and Q queries. In each query two integers L, R is given, you have to find (A[L] + A[L+1]*2 + A[L+2]*3 + A[L+3]*4...A[R]*(R-L+1)) % 10^9+7.


Input Format

The first line contains two space-separated integers N, Q where 1<=N<=10^6, 1<=Q<=10^6.

Next line contains N space-separated integers (-1e9<=Ai<=1e9).

Next Q lines contain two space-separated integers L, R where 1<=L<=R<=N.


Output Format

For each query print the value of (A[L] + A[L+1]*2 + A[L+2]*3 + A[L+3]*4...A[R]*(R-L+1)) % 10^9+7 in a new line.


Sample Input 1

10 10
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

20702
999271828
999223661
999999984
44
999538829
999318004
999506718
11778
999600930

*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
ll n,q;
ll arr[1000100];
ll mulArr[1000100];
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(ll i=1;i<=n;i++){
        cin>>arr[i];
        mulArr[i]=arr[i]*i%mod;
    }   
    for(ll i=1;i<=n;i++){
        arr[i]+=arr[i-1];
        arr[i]%=mod;
        mulArr[i]+=mulArr[i-1];
        mulArr[i]%=mod;
    }
    for(ll i=1;i<=q;i++){
        int l,r;
        cin>>l>>r;
        ll ans = mulArr[r]-mulArr[l-1];
        ans-=(l-1)*(arr[r]-arr[l-1]);
        ans=(ans%mod+mod)%mod;
        cout<<ans<<endl;
    }
}
