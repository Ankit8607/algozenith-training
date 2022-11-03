// https://www.learning.algozenith.com/problems/Four-Values-263

/*

Description:

You are given an array of n integers, and your task is to find four values (at distinct positions) whose sum is x.


Input Format

The first input line has two integers n and x: the array size and the target sum.
The second line has n integers a1, a2, …,an: the array values.


Output Format

Print 'YES' if such four values exist, otherwise 'NO'.


Constraints

1 ≤ n ≤ 1000
1 ≤ x, ai ≤ 109


Sample Input 1

8 15
3 2 5 8 1 3 2 3

Sample Output 1

YES

Note

Four values are {2, 8, 3, 2}.

*/


#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

signed main(){
    IOS 
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    set<int> s;
    s.insert(arr[0]+arr[1]);
    
    for(int i=2;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(s.count(x-arr[i]-arr[j])){
                cout<<"YES"<<endl;
                return 0;
            }
        }
        
        for(int j=0;j<i;j++){
            s.insert(arr[j]+arr[i]);
        }
    }
    
    cout<<"NO"<<endl;
    return 0;
}
