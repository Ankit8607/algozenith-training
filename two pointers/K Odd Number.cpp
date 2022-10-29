// https://www.learning.algozenith.com/problems/K-Odd-Number-52
/*

Description

Given an array of N integers, find a subarray with at most K odd numbers and the total sum is maximum but not more than D. If no such subarray exists print "IMPOSSIBLE" without double-quotes.


Input Format

The first line contains T, the number of test cases (1<=T<=10).

The first line contains two space separated integers N, K, D where 1<=N<=10^5,  0<=K<=10^5, -1e9<=D<=1e9.

Next line contains N space-separated integers (-1e4<=Ai<=1e4).


Output Format

For each test case print the sum of subarray with at most K odd numbers and the total sum is maximum, but not more than D in a newline. If no subarray is possible then print "IMPOSSIBLE" without double-quotes.


Sample Input 1

6
3 2 5
1 2 3
3 1 2
-3 -1 -3
5 2 8
-1 2 3 4 -5
7 0 -2
1 -4 1 0 1 0 2
10 3 14
1 0 -7 1 -10 4 -2 10 -1 3
3 0 1000
-101 201 -301

Sample Output 1

5
-1
8
-4
14
IMPOSSIBLE

Note

For the first test case, the optimal subarray - (2,3) → number of odd number is 1<=2 and sum is 5<=5.

For the second test case, the optimal subarray - (-1) → number of odd number is 1<=2 and sum is -1<=2.

For the third test case, the optimal subarray - (-1,2,3,4) → number of odd number is 2<=2 and sum is 8<=8.

For the fourth test case, the optimal subarray - (-4) → number of odd number is 0<=0 and sum is -4<=-2.

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
    int n,k,d; cin>>n>>k>>d;
    int a[n],pre[n];
    multiset<int>mt;
    for(int i=0;i<n;i++){
        cin>>a[i];
        pre[i]=a[i];
        if(i)pre[i]+=pre[i-1];
    }
    int head=-1,tail=0,sum=0,c=0,ans=-1e18;
    while(tail<n){
        while(head+1<n and (c<k || (a[head+1]%2==0))){
            head++;
            if(a[head]%2) c++;
            mt.insert(pre[head]);
        }
        int base=(tail==0?0:pre[tail-1]);
        auto it=mt.upper_bound(d+base);
        if(it!=mt.begin()){
            it--;
            ans=max(ans,*it-base);
        }
        if(head<tail){
            tail++;
            head=tail-1;
        }   
        else{
            if(a[tail]%2) c--;
            mt.erase(mt.find(pre[tail]));
            tail++;
        }
    }
    if(ans==-1e18)cout<<"IMPOSSIBLE"<<endl;
    else cout<<ans<<endl;
}

signed main(){
    IOS
    int t=1;
    cin>>t;
    // fac();
    while(t--) solve();
    return 0;
}
