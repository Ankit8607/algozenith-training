// https://www.learning.algozenith.com/problems/Consecutive-one-44

/*

Description

Given a binary array of length N. The score of an array is the length of the longest continuous subsegment consisting of only one.

Find the maximum score possible if you can change at most K elements of the array.


Input Format

The first line contains an integer T, the number of test cases.
The first line of each test case contains two space-separated integer N, K where 
The next line contains N space-separated integers which are either 0 or 1.


Output Format

For each test case print the maximum score possible if you can change at most K elements of the array in a new line.


Constraints

1 ≤ T ≤ 104
1 ≤ N ≤ 105
0 ≤ K ≤ N
Sum of N across all test cases ≤ 106.


Sample Input 1

5
10 2
1 0 1 1 0 1 1 0 0 1
10 1
1 1 0 1 0 0 0 1 0 0
10 3
1 0 0 1 1 0 1 1 0 1
10 3
1 1 1 0 0 0 1 1 1 1
10 3
1 1 0 0 1 1 0 0 1 1

Sample Output 1

7
4
8
10
7
 
 
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"
int mod= 1000000007;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N=5000;
int n,k;
int arr[100100];
bool check(int x){
    int count=0;
    for(int i=0;i<x;i++){
        if(arr[i]==0) count++;
    }
    int ans=count;
    for(int i=x;i<n;i++){
        if(arr[i-x]==0) count--;
        if(arr[i]==0) count++;
        ans=min(ans,count);
    }
    return ans<=k;
}
void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>arr[i];
    int lo=0,hi=n;
    int ans=0;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(check(mid)){
            lo=mid+1;
            ans=mid;
        }
        else{ 
            hi=mid-1;
        }
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
