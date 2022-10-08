// https://www.learning.algozenith.com/problems/Reduce-the-Array-AZ101-353

/*

Description

You are given an array of N integers. In one operation, remove any two elements in the array and add their sum to the array. The cost of this operation will be the sum of the two elements. Print the minimum cost till the size of the array does not become 1.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the length of the array. 

The second line of each test case contains N space-separated integers.


Output Format

For each test case, print the minimum cost till the size of the array does not become 1.


Constraints

1≤ T ≤ 106

1≤ N ≤ 106

1≤ Ai ≤ 109

It is guaranteed that the sum of N over all test cases does not exceed 106.


Sample Input 1

3
4
3 1 4 2
3
1 1 1
4
2 3 1 3

Sample Output 1

19
5
18

Note

For the first test case, take 5 and 6 to get sum (5+6) = 11

For the second test case, take 1 and 1, array becomes [2, 1] and then take 2 and 1 to get sum (1+1) + (2+1) = 5

For the third test case, take 1 and 2, array becomes [3, 3, 3] and then take 3 and 3, array becomes [6, 3] and then take 6 and 3 to get sum (1+2) + (3+3) + (6+3) = 18

*/


#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

signed main(){
    IOS
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            q.push(arr[i]);
        }
        
        int ans = 0;
        
        while(q.size() > 1){
            int temp = 0;
            temp += q.top();
            q.pop();
            temp += q.top();
            q.pop();
            ans += temp;
            q.push(temp);
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}
