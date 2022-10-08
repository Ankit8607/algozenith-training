// https://www.learning.algozenith.com/problems/Longest-AP-AZ101-321

/*

Description

You are given an array A of N integers. You have to choose a contiguous arithmetic subarray with equal difference between consecutive integers, that has the maximum length. Find the maximum possible length.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the length of the array.

The second line of each test case contains N space-separated integers.


Output Format

For each test case, print the maximum possible length.


Constraints

1 ≤ T ≤ 105

2 ≤ N ≤ 105

-107 ≤ Ai ≤ 107

It is guaranteed that the sum of N over all test cases does not exceed 105.


Sample Input 1

3
4
1 2 3 5
6
1 4 7 4 1 -2
2
1 8

Sample Output 1

3
4
2

Note

For the first test case, 1 2 3 5

For the second test case, 1 4 7 4 1 -2

For the third test case, 1 8

*/


#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        
        int gap = arr[1]-arr[0];
        int ans = 2;
        int count = 2;
        for(int i=1;i<n-1;i++){
            if(arr[i+1]- arr[i] == gap){
                count++;
            }else{
                gap = arr[i+1] - arr[i];
                count = 2;
            }
            ans = max(ans,count);
        }
        
        cout<<ans<<endl; 
    }
    
    return 0;
}
