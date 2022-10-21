// https://www.learning.algozenith.com/problems/Tough-Mex-186

/*

Description

For a (possibly empty) sequence of positive integers S, mex is defined as f(S) as the smallest positive integer that does not appear in S. For example, f([]) = 1, f([3,4,3,5]) = 1, f([2,5,1,1,2,3]) = 4.

You have given a sequence of N integers A1, A2, …, AN. Your task is to find the sum of f(S) over all 2N possible subsequences S of this sequence.

Since the resulting sum can be very big, compute it modulo 998244353.


Input Format

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers A1, A2, …, AN.


Output Format

For each test case, print a single line containing one integer ― the sum of f(S) over all subsequences modulo 998244353.


Constraints

1 ≤ T ≤ 10
1 ≤ N ≤ 105
1 ≤ Ai ≤ 109 for each valid i


Sample Input 1

2
2
1 1
3
1 2 1

Sample Output 1

7
17

Note

Example case 1: The values for all possible subsequences are f([]) = 1, f([1]) = 2, f([1]) = 2, f([1,1]) = 2.

Example case 2: The values for all possible subsequences are f([]) = 1, f([1]) = 2, f([2]) = 1, f([1]) = 2, f([1,2]) = 3, f([2,1]) = 3, f([1,1]) = 2, f([1,2,1]) = 3.

*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int mod= 998244353;
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

int ncr(int n,int r){
    if(r>n) return 0;
    int ans=(fact[n]*power(fact[r],mod-2))%mod;
    ans=(ans*power(fact[n-r],mod-2))%mod;
    ans+=mod;
    return ans%mod;
}

void solve(){
    int n; cin>>n;
    int arr[n];
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }
    sort(arr,arr+n);
    int ans=0;
    int cov=0;
    int tmpans=1;
    for(int i=1;i<=mp.size()+1;i++){
        cov+=mp[i];
        // cout<<"cov= "<<cov<<endl;
        ans+=(i*(power(2,n-cov))%mod)*tmpans;
        ans%=mod;
        // cout<<"ans= "<<ans<<endl;
        tmpans=tmpans*(power(2,mp[i])-1)%mod;
        if(mp[i]==0) break;
    }
    cout<<ans%mod<<endl;
}

signed main(){
    IOS
    int t=1;
    cin>>t;
    fac();
    while(t--) solve();
    return 0;
}
