// https://www.learning.algozenith.com/problems/Convert-Base-Number-AZ101-316

/*

Description

You are given a number N in base A. Convert the number to base B.

The base of the numbers can be anything such that all digits can be represented using 0 to 9 and A to Z.

The value of ‘A’ is 10, ‘B’ is 11, ‘C’ is 12 and so on.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains three space-separated integers N, A, B.


Output Format

For each test case, print N in base B.


Constraints

1≤ T ≤ 103

1≤ N ≤ 1018

2≤ A ≤ 16

2≤ B ≤ 36


Sample Input 1

3
1010 2 16
A14 16 8
12 10 4

Sample Output 1

A
5024
30

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
        string s;
        cin>>s;
        int a,b;
        cin>>a>>b;
        int n = s.size();
        
        int temp = 0;
        int res = 1;
        for(int i=n-1;i>=0;i--){
            if(s[i] >= '0' && s[i] <= '9'){
                temp += (s[i]-'0')*res;
            }else{
                temp += (s[i]-'A'+10)*res;
            }
            
            res = a*res; 
        }
        
        string ans = "";
        
        while(temp){
            res = temp%b;
            if(res < 10){
                ans += (res+'0');
            }else{
                ans += (res-10+'A');
            }
            
            temp /= b;
        }
        reverse(ans.begin(),ans.end());
        
        cout<<ans<<endl;
    }
    
    return 0 ;
}
