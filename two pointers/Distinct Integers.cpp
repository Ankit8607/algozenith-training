// https://www.learning.algozenith.com/problems/Distinct-Integers-56

/*

Description

Given an array A of N integers and an integer K, a subarray of A is good if the number of distinct integers present in the subarray is exactly K. Find the number of good subarrays.


Input Format

The first line of the input contains a single integer T denoting the number of test cases, (1<=T<=100000).

The first line of each test case contains two space-separated integers N, K (1<=N<=100000), (1<=K<=10^6).

The second line contains N space-separated integers A1,A2,…,AN, (0<=Ai<=10^6).

Sum of N overall test case <=10^6.


Output Format

For each test case output in a new line the number of good subarrays.


Sample Input 1

5
5 2
1 2 3 4 5
6 3
1 2 3 2 4 2
10 4
1 2 2 3 2 4 1 3 1 2
10 5
1 2 3 4 1 2 3 4 1 2
10 5
1 2 3 4 1 5 2 5 2 6 

Sample Output 1

4
6
21
0
12
 


Note

For the 1st test case, good subarrays are - {1,2},{2,3},{3,4},{4,5}

For the 2nd test case, good subarrays are - {1,2,3}, {1,2,3,2}, {2,3,2,4}, {2,3,2,4,2}, {3,2,4}, {3,2,4,2}.

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
int result(int a[],int n,int k){
    int head=-1;
    int tail=0;
    int c=0;
    int ans=0;
    while(tail<n){
        while(head+1<n and (c<k || (freq[a[head+1]]>0))){
            head++;
            if(freq[a[head]]==0){c++;}
            freq[a[head]]++;
            
        }
        ans+=(head-tail+1);
        
        if(tail<=head){
            freq[a[tail]]--;
            if(freq[a[tail]]==0){c--;}
            tail++;
        }else{
            tail++;
            head=tail-1;
        }
              
    }
    return ans;
}
void solve(){
    int n,k; cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=result(a,n,k)-result(a,n,k-1);
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
