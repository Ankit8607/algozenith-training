// https://www.learning.algozenith.com/problems/Distinct-Characters-AZ101-361

/*

Description

You are given a string S. You are given Q queries of two types, asking the number of distinct characters in the range [L, R] and changing the i-th character to c. (1-based indexing)


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test contains a string S.

The second line of each test case contains one integer Q - the number of queries. 

Each of the next Q lines contain two types of queries: either 1 i c or 2 L R. The query 1 is for changing the i-th character to c and the query 2 is for finding the number of distinct characters in the range [L, R].


Output Format

For each test case, print the required queries.


Constraints

1≤ T ≤ 105

1≤ |S| ≤ 105

1≤ Q ≤ 106

1≤ Ai ≤ 105

It is guaranteed that the sum of |S| and the sum of Q over all test cases does not exceed 105.


Sample Input 1

2
abbac
3
2 1 3
1 2 c
2 1 4
flower
4
2 2 5
1 3 l
1 6 w
2 1 6

Sample Output 1

2
3
4
4

Note

For the first test case, distinct characters from 1-3 in abbac are ‘a’ and ‘b’. Changing string to acbac, distinct characters from 1-3 in abcac are ‘a’, ‘b’ and ‘c’.

For the second test case, distinct characters from 2-5 in flower are ‘l’, ‘o’, ‘w’, ‘e’. Changing string to fllwer and then to fllwee, distinct characters from 1-6 are ‘f’, ‘l’, ‘w’, ‘e’.

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
        int q;
        cin>>q;
        set<int> skk[26];
        
        for(int i=0;i<(int)s.size();i++){
            skk[s[i]-'a'].insert(i+1);
        }
        
        while(q--){
            int x;
            cin>>x;
            
            if(x == 1){
                int a;
                char b;
                cin>>a>>b;
                skk[s[a-1]-'a'].erase(a);
                skk[b-'a'].insert(a);
                s[a-1] = b;
            }else if(x == 2){
                int a,b;
                int ans=0;
                cin>>a>>b;
                for(int i=0;i<26;i++){
                    auto itr = skk[i].lower_bound(a);
                    if(itr == skk[i].end())
                        continue;
                    if(a<=*itr && *itr<=b){
                        ans++;
                    }
                }
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}
