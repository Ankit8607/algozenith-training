// https://www.learning.algozenith.com/problems/Maximise-the-fraction-103

/*

Description

Given two arrays A and B of size N and an integer K. You have to select K indexes i1,i2,i3....iK such that 

(A[i1]+A[i2]+A[i3]+……+A[iK]) / (B[i1]+B[i2]+B[i3]+……+B[iK]) is maximum.


Input Format

The first line contains T, the number of test cases (1<=T<=10000).

The first line contains an integer N, K where 1<=N<=10^4, 1<=K<=N.

Next line contains N space-separated integers (1<=Ai<=1e4).

Next line contains N space-separated integers (1<=Bi<=1e4).

Sum of N across all test cases<=10^5.


Output Format

For each test case print the maximum possible value of (A[i1]+A[i2]+A[i3]+……+A[iK]) / (B[i1]+B[i2]+B[i3]+……+B[iK]). You have to print the result round off to 6 decimal places.


Sample Input 1

3
3 2
10 9 7
3 5 4
8 3
4 4 2 1 5 3 2 5
2 2 2 5 3 5 2 3
1 1
1 
1

Sample Output 1

2.428571
1.857143
1.000000

Note

1st test case:
Select index → [1,3], result = 17/7.

*/


#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ld long double
#define endl "\n"
int mod= 1000000007;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N=5000;
int n,k;
map<int,int>fre;
int arr[100100],brr[100100];
bool check(ld x){
    priority_queue <ld, vector<ld>, greater<ld>> pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]-x*brr[i]);
        if(pq.size()>k)
            pq.pop();
    }
    ld sum = 0.0;
    while(pq.size()){
        sum+=pq.top();
        pq.pop();
    }
    return sum>=0.0;
}
void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++)
        cin>>brr[i];
    ld lo = 0.0, hi = 1e8;
    ld ans = 0.0;
    while(abs(lo-hi)>1e-9){
        ld mid = (lo+hi)/2.0;
        if(check(mid))
            ans = mid,
            lo = mid;
        else
            hi = mid;
    }
    cout<<fixed<<setprecision(6)<<ans<<"\n";
}
signed main() {
    IOS
    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}
