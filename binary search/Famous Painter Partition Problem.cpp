// https://www.learning.algozenith.com/problems/Famous-Painter-Partition-Problem-449

/*
Description

We have to paint n boards of length {A1, A2…An}. There are k painters available and each takes 1 unit time to paint 1 unit of the board. The problem is to find the minimum time to get
this job done under the constraints that any painter will only paint continuous sections of boards.

Note:

2 painters cannot share a board to paint. A board cannot be painted partially by one painter, and partially by another.
A painter will only paint contiguous boards. If a painter paints board 1 and 3 but not 2 is invalid.

Input Format

The first line contains a single integer T (1 ≤ T ≤ 100000) - the number of test cases.

The first line of each test case contains 2 space-separated integers N, K (1 ≤ N ≤ 100000, 1 ≤ K ≤ 100000) - the number of boards and the number of painters.

The second line of each test case contains N space-separated integers (0 ≤ xi ≤ 10^9) - the length of the boards.

Sum of N across all test cases ≤ 10^6.


Output Format

For each test case print the minimum time required to complete the painting in a new line.


Sample Output 1

5
5 2
1 2 3 4 5
5 3
2 5 7 2 5
5 1
1 2 3 4 5
5 5
1 2 3 4 5
5 4
1 7 2 3 5

Sample Input 2

9
7
15
5
7


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
int arr[100100],pre[100100];
bool check(int x){
    int count=1,time=0;
    for(int i=0;i<n;i++){
        time+=arr[i];
        if(time>x){
            time=arr[i];
            count++;
        }
    }
    // cout<<"x= "<<x<<" "<<"count= "<<count<<endl;
    return count<=k;
}
void solve(){
    cin>>n>>k;
    int hi=0;
    for(int i=0;i<n;i++) cin>>arr[i], hi+=arr[i];
    int lo=*max_element(arr,arr+n);
    int ans=0;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(check(mid)){
            hi=mid-1;
            ans=mid;
        }
        else
            lo=mid+1;
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
