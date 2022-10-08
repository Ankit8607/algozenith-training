// https://www.learning.algozenith.com/problems/Multimap-AZ101-341

/*

Description

You are given Q queries and have to perform the following operations:

add x y - add student name X (string) for marks y (integer). If it already exists, add a new entry.
erase x - erase the first current entry of student with name x
eraseall x - erase all entries of student with name x
print x - print the first entry of marks of student with name x, if entry is not there for x, print 0.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer Q - the number of queries.

Each of the next Q ines contains queries.


Output Format

For each test case, print the required queries.


Constraints

1≤ T ≤ 105

1≤ Q ≤ 105

1≤ X ≤ 106

It is guaranteed that the sum of Q over all test cases does not exceed 105.


Sample Input 1

1
9
add alice 24
add bob 21
add alice 23
add alice 22
print alice
erase alice
print alice
eraseall alice
print alice

Sample Output 1

24
23
0

Note

Map becomes: [alice: 24]
Map becomes: [alice: 24, bob: 21]
Map becomes: [alice: 24, bob: 21, alice: 23]
Map becomes: [alice: 24, bob: 21, alice: 23, alice: 22]
alice: 24
Map becomes: [bob: 21, alice: 23, alice: 22] (since first entry of alice is removed)
alice: 23
Map becomes: [bob: 21]
key alice doesn't exist, hence alice: 0

*/


#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

signed main(){
    IOS
    int t;
    cin>>t;
    
    while(t--){
        int q;
        cin>>q;
        multimap<string,int> mm;
        while(q--){
            string s;
            cin>>s;
            
            if(s == "add"){
                string x;
                int y;
                cin>>x>>y;
                mm.insert({x,y});
            }else if(s == "erase"){
                string x;
                cin>>x;
                multimap<string,int>::iterator itr;
                itr = mm.find(x);
                if(itr != mm.end()){
                    mm.erase(itr);
                }
            }else if(s == "eraseall"){
                string x;
                cin>>x;
                mm.erase(x);
            }else if(s == "print"){
                string x;
                cin>>x;
                multimap<string,int>::iterator itr;
                itr = mm.find(x);
                if(itr != mm.end()){
                    cout<<itr->second<<endl;
                }else{
                    cout<<0<<endl;
                }
            }
        }
    }
    
    return 0; 
}
