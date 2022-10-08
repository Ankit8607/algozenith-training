// https://www.learning.algozenith.com/problems/Good-Pairs-AZ101-354

/*

Description

You are given two arrays A and B, both of size N. A pair is called good if i < j and Ai + Aj > Bi + Bj. Find the number of good pairs.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the length of the array. 

The second line of each test case contains N space-separated integers.

The third line of each test case contains N space-separated integers.


Output Format

For each test case, print the number of good pairs.


Constraints

1≤ T ≤ 106

1≤ N ≤ 106

1≤ Ai ≤ 109

It is guaranteed that the sum of N over all test cases does not exceed 106.


Sample Input 1

3
4
2 3 5 4
2 1 5 6
3
1 4 6
2 3 3
5
5 6 1 1 2
1 9 2 4 1

Sample Output 1

2
2
4

Note

For the first test case, following pairs satisfy the given inequality: (2+3) > (2+1) and (3+5) > (1+5)

For the second test case, following pairs satisfy the given inequality: (1+6) > (2+3) and (4+6) > (3+3)

For the third test case, following pairs satisfy the given inequality: (5+6) > (1+9), (5+1) > (1+2), (5+1) > (1+4) and (5+2) > (1+1)

*/


#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        
        int temp[n];
        for(int i=0;i<n;i++){
            temp[i] = (a[i]-b[i]);
        }
        sort(temp,temp+n);
        
        int count = 0;
        for(int i=0;i<n;i++){
            int x = upper_bound(temp,temp+n,-temp[i]) - temp;
            count += max(0ll,i-x);
        }
        
        cout<<count<<endl; 
    }
    
    return 0 ;
}
