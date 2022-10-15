// https://www.learning.algozenith.com/problems/Kth-Sum-Value-100

/*

Description

Given two arrays A of size N and B of size M and an integer K. Create a new array C of size N*M consisting of A[i]+B[j] for 1≤i≤N, 1≤j≤M. Find the Kth smallest element in the array C.


Input Format

The first line contains T, the number of test cases (1<=T<=10000).

The first line contains 3 space-separated integer N, M, K where 1<=N<=10^6, 1<=M<=10^6, 1<=K<=N*M.

Next line contains N space-separated integers (0<=Ai<=1e4).

Next line contains M space-separated integers (0<=Bi<=1e4).

Sum of min(N, M) across all test cases<=10^5.


Output Format

For each test case print the Kth smallest element in the array C.


Sample Input 1

1
3 3 6
1 2 3
4 5 6

Sample Output 1

7

Note

Array C -> [1+4,1+5,1+6,2+4,2+5,2+6,3+4,3+5,3+6] -> [5,6,7,6,7,8,7,8,9]
Array C after sorting - [5,6,6,7,7,7,8,8,9]
6th element is 7.

*/


#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ld long double
#define endl "\n"
int mod= 1000000007;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N=5000;
int n,k,m;
map<int,int>fre;
vector<int>a,b;
bool check(int x){
    int count=0;
    for(int i=0;i<n;i++){
        int lo=0,hi=m-1,ans=-1;
        int temp=x-a[i];
        if(temp<=0) break;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(b[mid]<temp){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        count+=ans+1;
    }
    // cout<<"x= "<<x<<" "<<"count= "<<count<<endl;
    return count<k;
}
void solve(){
    cin>>n>>m>>k;
    a.resize(n); b.resize(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(n > m){
        swap(a, b);
        swap(n, m);
    }
    int hi=a[n-1]+b[m-1];
    int lo=a[0]+b[0];
    int ans=lo;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(check(mid)){
            lo=mid+1;
            ans=mid;
        }
        else
            hi=mid-1;
        // cout<<ans<<" ";
    }
    cout<<ans<<endl;
}
signed main() {
    IOS
    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}
