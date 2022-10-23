// https://www.learning.algozenith.com/problems/XOR-AND-OR-Query-49

/*

Description

Given an array of N integers and Q queries. In each query, you are given two parameters L and R; you have to find the following:

1. Smallest integer X1 such that the value of (AL XOR X1) + (AL+1 XOR X1) + ... + (AR XOR X1) is maximum possible.

2. Smallest integer X2 such that the value of (AL OR X2) + (AL+1 OR X2) + ... + (AR OR X2) is maximum possible.

3. Smallest integer X3 such that the value of (AL AND X3) + (AL+1 AND X3) + ... + (AR AND X3) is maximum possible.

Range of X1, X2, X3 allowed → 0 <= X1, X2, X3 < 2^31.

Print the sum of X1, X2, X3 for each query in a newline.


Input Format

The first line of the input contains a single integer T denoting the number of test cases, (1<=T<=100).

The first line of each test case contains a single integer N, (2<=N<=100000).

The second line contains N space-separated integers A1,A2,…,AN, (1<=Ai<=10^9).

The third line contains an integer Q, (1<=Q<=10^5).

The next Q lines contain two space-separated integers L, R (1<=L<=R<=N).

Sum of Q over all test cases does not exceed 10^6.


Output Format

For each query print the value of X1  + X2 + X3  in a new line.

 


Sample Input 1

5
5
1 2 3 4 5
5
1 5
2 5
3 4
2 4
3 3
3
1 2 2
3
1 2
2 3
1 3
4
1 2 2 4
5
1 2
2 3
3 4
2 4
3 4
10
123 234565 3456765 3456 09888 433534 908767 125698 545676 23456
10
1 4
1 6
1 9
1 10
3 7
3 9
4 7
6 9
4 9
7 9
10
23456 3456 987 8765 3456 34565 9876 654555 234566 87654344
10
1 8
1 6
1 9
1 10
2 7
2 9
4 7
8 9
9 9
7 9

Sample Output 1

4294967300
4294967294
4294967294
4294967299
4294967291
4294967294
4294967292
4294967295
4294967294
4294967292
4294967294
4294967298
4294967294
4298580736
4298580736
4299121201
4299120657
4298857985
4299120753
4295712255
4295106335
4295958639
4295222095
4295618668
4295028860
4295751805
4382781565
4295010408
4295751784
4295002150
4294863804
4294732728
4295640583

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

void solve(){
    int n; cin>>n;
    int arr[n+1],pre[n+1][31]={};
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=0;i<31;i++){
        for(int j=1;j<=n;j++){
            pre[j][i]=((arr[j]&(1<<i))>0);
        }
    }
    for(int i=0;i<31;i++){
        for(int j=2;j<=n;j++){
            pre[j][i]+=pre[j-1][i];
        }
    }
    // for(int i=n;i>=1;i--){
    //     for(int j=30;j>=0;j--){
    //         cout<<pre[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int q; cin>>q;
    for(int i=0;i<q;i++){
        int l,r; cin>>l>>r;
        int cnt0=0,cnt1=0,x1=0,x2=0,x3=0,ans=0;
        for(int i=0;i<31;i++){
            cnt1=pre[r][i]-pre[l-1][i];
            cnt0=r-l+1-cnt1;
            // cout<<cnt0<<" ";
            if(cnt0>cnt1) x1+=(1<<i);
            if(cnt0>0) x2+=(1<<i);
            if(cnt1>0) x3+=(1<<i);
            // cout<<x1<<" ";
        }
        cout<<x2+x3+x1<<endl;
    }

}

signed main(){
    IOS
    int t=1;
    cin>>t;
    // fac();
    while(t--) solve();
    return 0;
}
