// https://www.learning.algozenith.com/problems/Rotated-Sorted-Array-106

/*

Description

Given a rotated sorted array. Find the index of the minimum element in the array.

All the elements are distinct.

 


Input Format

The first line contains T, the number of test cases (1<=T<=10000).

The first line contains an integer N where 1<=N<=10^5.

The second line contains N space-separated integers A1,A2....AN where -1e9<=Ai<=1e9.

Sum of N over all test cases ≤10^6.


Output Format

For each test case print the index of the minimum element in the array.

0-indexed.


Sample Input 1

5
5
3 4 5 1 2
5
4 5 1 2 3
5
5 1 2 3 4
5
1 2 3 4 5
5
2 3 4 5 1

Sample Output 1

3
2
1
0
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
    return arr[i]<arr[0];
}
void solve(){
    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    int lo=0,hi=n-1,ans=0;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(check(mid)){
            hi=mid-1;
            ans=mid;
        }
        else lo=mid+1;
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
