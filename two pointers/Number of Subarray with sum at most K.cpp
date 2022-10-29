// https://www.learning.algozenith.com/problems/Number-of-Subarray-with-sum-at-most-K-57

/*

Description

Given an array of N integers, find the number of subarrays with a sum less than equal to K.


Input Format

The first line contains T, the number of test cases (1<=T<=10).

The first line of each test case contains two space-separated integers N, K where 1<=N<=10^5, 0<=K<=10^9.

Next line contains N space-separated integers (0<=Ai<=1e4).


Output Format

For each test case print the number of subarrays with a sum less than K in a newline.


Sample Input 1

5
3 5
1 2 3
3 6
3 2 1
5 0
2 1 0 4 5
7 6
1 2 3 0 1 5 2
10 10
1 0 1 1 10 2 3 7 5 9

Sample Output 1

5
6
1
18
18
 


Note

For the first test case, number of subarray with sum <=5 -> (1),(1,2),(2),(2,3),(3)

For the second test case, all the subarrays have sum <=6.

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
    int head=-1, tail=0, sum=0,ans=0;
    while(tail<n){
        while(head+1<n&&(sum+arr[head+1]<=k)){
            head++;
            sum+=arr[head];
        }
        ans+=(head-tail+1);
        if(tail<=head){
            sum-=arr[tail];
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
