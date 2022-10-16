// https://www.learning.algozenith.com/problems/Median-of-Subarray-Sum-45

/*

Description

Given an array of N integers A. The score of a subarray is the sum of all integers in the subarray. Mr.X calculated the score of all N*(N+1))/2 subarray. Mr.X wants you to find the median of the array containing the score of all the subarray.

 

Note: The median of a sequence is the value that is in the middle when the sequence is sorted. If the length of the sequence is even, there are two values in the middle and the median is the smaller of these values (or either when they are equal).


Input Format

The first line contains an integer T, the number of test cases (1<=T<=10000).

The first line of each test case contains an integer N where (1<=N<=10^5).

Next line contains N space-separated integers (0<=Ai<=1e9).

Sum of N across all test cases ≤ 10^6.


Output Format

For each test case output the median of the array containing the score of all the subarray in a new line.


Sample Input 1

5
3
1 2 3
1
5
2
1 5
10
1 2 2 3 3 4 5 4 6 7
15
100 222 333 511 555 232 444 555 777 888 999 1000 1112 12345 123456

Sample Output 1

3
5
5
13
3629
 


Note

1st test case:
Subarray and score:
1 -> 1
1,2 -> 3
1,2,3 -> 6
2 -> 2
2,3 -> 5
3 -> 3
New array = {1,2,3,3,5,6}, median = 3

2nd test case:
Subarray and Score:
5 -> 5
New array = {5}, median = 5

3rd test case:
Subarray and score
1 -> 1
1,5 -> 5
5 -> 5
New array = {1,5,5}, median = 5.

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
    int i=0,j=0,count=0,sum=0;
    while(j<=n){
        if(((pre[j]-pre[i])>x) && i<=j ){
            i++;
        }
        else{
            count+=j-i;
            j++;
        }
    }
    // cout<<"x= "<<x<<" "<<"count= "<<count<<endl;
    return count>=(m+1)/2;
}
void solve(){
    cin>>n;
    m=(n*(n+1))/2;
    int hi=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        hi+=arr[i];
    }
    pre[0]=0;
    for(int i=1;i<=n;i++) pre[i]=arr[i-1]+pre[i-1];
    int lo=*min_element(arr,arr+n);
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
