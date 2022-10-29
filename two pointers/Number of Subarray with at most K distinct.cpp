// https://www.learning.algozenith.com/problems/Number-of-Subarray-with-at-most-K-distinct-58

/*

Description

Given an array of N integers, find the number of subarrays with at most K distinct elements.


Input Format

The first line contains T, the number of test cases (1<=T<=10).

The first line contains two space-separated integers N, K where 1<=N<=10^5, 0<=K<=10^5.

Next line contains N space-separated integers (0<=Ai<=1e6).


Output Format

For each test case print the number of subarrays with at most K distinct elements in a newline.


Sample Input 1

5
3 2
1 2 3
3 2
3 2 2
5 0
2 1 0 4 0
7 3
1 2 1 0 1 0 2
10 5
1 0 7 1 10 2 4 10 1 3

Sample Output 1

5
6
0
28
46
 
 
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
    int n,k; cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int head=-1, tail=0, cnt=0,ans=0;
    while(tail<n){
        while(head+1<n&&(cnt<k || freq[arr[head+1]]>0)){
            head++;
            freq[arr[head]]++;
            if(freq[arr[head]]==1) cnt++;
        }
        ans+=(head-tail+1);
        if(tail<=head){
            freq[arr[tail]]--;
            if(freq[arr[tail]]==0) cnt--;
            tail++;
        }
        else{
            tail++;
            head=tail-1;
        }
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
