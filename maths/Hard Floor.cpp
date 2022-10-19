// https://www.learning.algozenith.com/problems/Hard-Floor-217


/*

Description

Your task is to find the answer to the following sum.



Input Format

The only line of input contains two space-separated integers n and m.


Output Format

Print the answer on a new line.


Constraints

1 ≤ n ≤ 1012
1 ≤ m ≤ 109


Sample Input 1

4 2

Sample Output 1

22

Sample Input 2

100000000000 100000000

Sample Output 2

728180943

*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int mod= 1000000007;
const int N=20;
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
void fac(){
    fact[0]=1;
    for(int i=1;i<=N;i++) 
        fact[i]=(i*fact[i-1])%mod;
}
// vector<int>v;
// map<int,int>mp;
// int arr[20];
// int ans=0,n;
// char store[14][14];
// set<vector<int>>st;
// bool is_prime(int t){
//     for(int i=2;i*i<=t;i++){
//         if(t%i==0) return 0;
//     }
//     return 1;
// }
// bool check(int temp){
//     if(is_prime(temp+v.back())) return 1;
//     return 0;
// }
// void rec(int level){
//     if(level==n){
//         for(auto i:v) cout<<i<<" ";
//         cout<<endl;
//         vector<int>stor(n-1);
//         for(int i=0;i<n-1;i++){
//             stor[i]=v[i]+v[i+1];
//         }
//         sort(stor.begin(),stor.end());
//         st.insert(stor);
//         return;
//     }
//     for(int i=1;i<=n;i++){
//         if(arr[i] and (level==0||check(i))){
//             v.push_back(i);
//             arr[i]=0;
//             rec(level+1);
//             v.pop_back();
//             arr[i]=1;
//         }
        
//     }
// }
void solve(){
    int n,m; cin>>n>>m;
    int cnt=0,ans=0,last=1;
    for(int i=1;i<=n;i+=last){
        int temp=n/(n/i);
        last=temp-cnt;
        ans+=(power((n/i)%mod,m)*(last%mod))%mod;
        ans%=mod;
        cnt+=last;
    }
    cout<<ans<<endl;
}

signed main(){
    IOS
    int t=1;
    // cin>>t;
    // fac();
    while(t--) solve();
    return 0;
}
