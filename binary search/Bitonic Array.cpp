// https://www.learning.algozenith.com/problems/Bitonic-Array-105

/*

Description

Given a bitonic array A consisting of N integers and an integer Q. In each query, you will be given an integer K, find the positions of K in A. Integer K exists in A.

Bitonic array - A bitonic sequence is a sequence with A[1]<A[2]<A[3]....A[k]>A[k+1]>A[k+2]....>A[N] for some 1<=K≤N. 


Input Format

The first line contains T, the number of test cases (1<=T<=10000).

The first line contains two space separated-integer N, Q where 1<=N<=10^5, 1<=Q<=10^6.

The second line contains N space-separated integers A1,A2....AN where -1e9<=Ai<=1e9.

Next Q lines contains an integer K, -1e9<=K<=1e9.

Sum of N, Q across all test case ≤10^6


Output Format

For each test case print the positions of K in A in sorted order in a new line.

Positions are 1-indexed.


Sample Input 1

1
6 4
1 2 5 3 2 1
1
2
5
3

Sample Output 1

1 6
2 5
3
4

*/


#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"
int mod= 1000000007;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N=5000;
int arr[100100];
bool check(int i){
    if(i==0) return 0;
    return arr[i]<arr[i-1];
}
void solve(){
    int n,q; cin>>n>>q;
    for(int i=0;i<n;i++) cin>>arr[i];
    int lo=0,hi=n-1,k=0;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(check(mid)){
            hi=mid-1;
        }
        else{ 
            lo=mid+1;
            k=mid;
        }
    }
    // cout<<"k= "<<k<<endl;
    for(int i=0;i<q;i++){
        int x; cin>>x;
        lo=0;hi=k;
        int ans=0;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]<=x){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        if(arr[ans]==x)
        cout<<ans+1<<" ";
        lo=k+1; hi=n-1;
        ans=lo;
        if(k<n-1){
            // cout<<"hi";
            while(lo<=hi){
                int mid=(lo+hi)/2;
                if(arr[mid]>=x){
                    ans=mid;
                    lo=mid+1;
                }
                else hi=mid-1;
            }
            // cout<<ans<<" ";
            if(arr[ans]==x) cout<<ans+1;
        }
        cout<<endl;
    }
}
signed main() {
    IOS
    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}
