// https://www.learning.algozenith.com/problems/Coloured-Marbles-91

/*

Description

You have N marbles, out of which C1 are red, C2 are blue and C3 are green. (C1+C2+C3 = N) You have to tell the number of different arrangements possible. Since the answer can be quite large, print it modulo 109+7.

Assume that marbles of the same colour are indistinguishable.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains four integers N, C1, C2, C3 - the number of marbles, the numbers of red coloured marbles, the number of blue coloured marbles and the number of green coloured marbles respectively.


Constraints

1 ≤ T ≤ 105
0 ≤ C1, C2, C3 ≤ N ≤ 105 
It is guaranteed that C1 + C2 + C3 = N.


Sample Input 1

3
3 1 1 1
2 0 2 0
5 4 0 1

Sample Output 1

6
1
5

Note

In the first test case of the example, the following are the 6 different arrangements possible:
In the second test case of the example, only one different arrangement is possible:

*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int mod= 1000000007;
const int N=2000010;
#define endl "\n"
#define F first
#define S second
#define MP make_pair
#define ii pair<int,int>
#define all(a) a.begin(),a.end()
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
int dearr[100100];
void der(int n){
    dearr[0]=1;
    dearr[1]=0;
    for(int i=2;i<=n;i++){
        dearr[i]=dearr[i-1]+pow(-1,i%2)*power(fact[i],mod-2);
        dearr[i]=((dearr[i]%mod)+mod)%mod;
    }
}
void solve(){
    int n; cin>>n;
    int a,b,c; cin>>a>>b>>c;
    int ans=(fact[n]*power(fact[a],mod-2))%mod;
    ans=(ans*power(fact[b],mod-2))%mod;
    ans=(ans*power(fact[c],mod-2))%mod;
    cout<<ans<<endl;
}

signed main(){
    IOS
    int t=1;cin>>t;
    fac();
    while(t--) solve();
    return 0;
}
