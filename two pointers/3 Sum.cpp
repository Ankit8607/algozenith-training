// https://www.learning.algozenith.com/problems/3-Sum-63

/*

Description

Given an array A of N integers and an integer target, find three integers in A such that the sum is closest to the target (absolute value of (sum-target) is minimum). Print the minimum absolute value of (sum-target). You cannot select an index more than one. All three indexes should be distinct.


Input Format

The first line contains T, the number of test cases (1<=T<=100).

The first line contains two space-separated integers N, target where 3<=N<=10^3, -1e18<=target<=1e18.

Next line contains N space-separated integers (-1e9<=Ai<=1e9).

The Sum of N across all test cases ≤ 10^4.


Output Format

For each test case print the minimum absolute value of (sum-target).


Sample Input 1

1
5 3
1 2 3 4 5

Sample Output 1

3

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
int freq[100100];
void solve(){
    int n,target; cin>>n>>target;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        // freq[arr[i]]=0;
    }
    sort(arr,arr+n);
    int ans=LLONG_MAX;
    for(int j=0;j<n;j++){
        int i=0,k=n-1;
        while(i<j&&j<k){
            ans=min(ans,abs(arr[i]+arr[j]+arr[k]-target));
            if((arr[i]+arr[j]+arr[k]-target)<0) i++;
            else if((arr[i]+arr[j]+arr[k]-target)>0) k--;
            else{
                cout<<0<<endl;
                return;
            }
        }
    }
    cout<<ans<<endl;
    // while(tail<n){
    //     while(head+1<n&&(cnt<k || freq[arr[head+1]]>0)){
    //         head++;
    //         freq[arr[head]]++;
    //         if(freq[arr[head]]==1) cnt++;
    //     }
    //     ans+=(head-tail+1);
    //     if(tail<=head){
    //         freq[arr[tail]]--;
    //         if(freq[arr[tail]]==0) cnt--;
    //         tail++;
    //     }
    //     else{
    //         tail++;
    //         head=tail-1;
    //     }
    // }
}

signed main(){
    IOS
    int t=1;
    cin>>t;
    // fac();
    while(t--) solve();
    return 0;
}
