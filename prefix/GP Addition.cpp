// https://www.learning.algozenith.com/problems/GP-Addition-30

/*

Description

Given an array of N integers and Q queries and an integer K. Initially, all the elements of the array have value 0.

In each query 3 integers A, L, R is given, which means perform GP addition

Arr[L]+=A

Arr[L+1]+=AK

Arr[L+2]+=AKK

Arr[L+3]+=AKKK

.

.

.

.

Arr[R]+=A*(K^(R-L))

 

After performing all the operations. Print the final array % 10^9+7.


Input Format

The first line contains three space-separated integers N, Q, K where 1<=N<=10^6, 1<=Q<=10^6, 1<=K<=10^9.

Next Q lines contain three space-separated integers A, L, R where 0<=A<=10^4, 1<=L<=R<=N.


Output Format

Print the N space-separated integer representing the final array %10^9+7.


Sample Input 1

5 5 2
3 1 5
4 2 2
6 3 5
9 5 5
4 2 4

Sample Output 1

3 14 26 52 81 

*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int mod= 1000000007;
const int N=100100;
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int power(int a, int b){
    int ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;     
}
int fact[N];
void fac(int n){
    fact[0]=1;
    for(int i=1;i<=n;i++) 
        fact[i]=(i*fact[i-1])%mod;
}
void solve(){
    int n,k,q; cin>>n>>q>>k;
    int arr[n+2]={0};
    for(int i=0;i<q;i++){
        int a,l,r; cin>>a>>l>>r;
        arr[l]+=a;
        arr[r+1]-=(a*power(k,r-l+1))%mod;
        arr[r+1]=(arr[r+1]%mod+mod)%mod;
    }
    for(int i=1;i<=n;i++){
        arr[i]+=(arr[i-1]*k)%mod;
        arr[i]%=mod;
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

signed main(){
    IOS
    int t=1;
    // cin>>t;
    // fac();
    while(t--) solve();
    return 0;
}
