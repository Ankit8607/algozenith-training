// https://www.learning.algozenith.com/problems/Sieve-of-Eratosthenes-Revisited-216

/*

Description

Find all prime numbers between the range from L to R (endpoints inclusive). Print them in non-decreasing order.


Input Format

The only line of input contains L and R, representing the range.


Output Format

The first line of output contains n - the number of prime numbers in between [L, R].
The second line contains n space-separated integers denoting the prime numbers between [L, R] in non-decreasing order.


Constraints

1 ≤ L ≤ R ≤ 1012
R - L + 1 ≤ 106 


Sample Input 1

1 20

Sample Output 1

8
2 3 5 7 11 13 17 19

Sample Input 2

100000000000 100000000020

Sample Output 2

2
100000000003 100000000019

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
int freq[1001000];
void solve(){
    int l,r; cin>>l>>r;
    vector<int>prime;
    int lim=sqrt(r);
    int a[lim+1]={0};
    for(int i=2;i<=lim;i++){
        if(a[i]==0){
            prime.push_back(i);
            for(int j=i*i;j<=lim;j+=i){
                a[j]=1;
            }
        }
    }

    // cout<<"prime= ";
    // for(auto i:prime) cout<<i<<" ";
    // cout<<endl;

    int ans[r-l+1]={0};
    for(auto i:prime){
        int st=i*((l+i-1)/i);
        while(st<=r){
            if(st!=i) ans[st-l]=1;
            st+=i;
        }
    }
    int cnt=0;
    vector<int>v;

    int i=(l>2?l:2);
    for(i;i<=r;i++){
        if(ans[i-l]==0){
            cnt++;
            v.push_back(i);
        }
    }
    cout<<cnt<<endl;
    for(auto i:v) cout<<i<<" ";
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
