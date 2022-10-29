// https://www.learning.algozenith.com/problems/Minimum-Penalty-62

/*

Description

Given an array of N integers and an integer D. Consider all subarray with length D, the penalty of the subarray is the number of distinct elements present in the subarray. Find a subarray of length D with minimum penalty. Print the minimum penalty.


Input Format

The first line contains T, the number of test cases (1<=T<=10000).

The first line contains two space-separated integers N, D where 1<=N<=10^6, 1<=D<=N.

Next line contains N space-separated integers (0<=Ai<=1e6).

The Sum of N across all test cases ≤ 5*10^6.


Output Format

For each test case print the minimum penalty in a newline.


Sample Input 1

5
6 3
0 1 1 2 2 2
5 3
1 0 1 2 3
5 5
1 1 2 3 4
5 1
1 2 3 4 5
7 3
1 2 1 2 3 4 2

Sample Output 1

1
2
4
1
2
 


Note

For first test case all the subarray with length = 3 and minimum element ->
0,1,1 - 2
1,1,2 - 2
1,2,2 - 2
2,2,2 - 1
So minimum penalty = 1

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
    int n,d; cin>>n>>d;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        freq[arr[i]]=0;
    }
    int i=0,cnt=0;
    for(i;i<d;i++){
        freq[arr[i]]++;
        if(freq[arr[i]]==1)cnt++;
    }
    int ans=cnt;
    for(i;i<n;i++){
        freq[arr[i-d]]--;
        if(freq[arr[i-d]]==0)cnt--;
        freq[arr[i]]++;
        if(freq[arr[i]]==1)cnt++;
        ans=min(ans,cnt);
    }
    cout<<ans<<endl;
}

signed main(){
    IOS
    int t=1;
    cin>>t;
    // fac();
    while(t--) solve();
    return 0;
}
