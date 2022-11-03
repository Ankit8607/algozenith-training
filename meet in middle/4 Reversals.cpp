// https://www.learning.algozenith.com/problems/4-Reversals-468

/*

Description:

We are given two equal-length strings S and T. Figure out if we can get string T starting from string S and applying 4 substring reversal operations.


Input Format

The first line contains an integer TC (number of test cases),

The next line contains a string S. 

The next line contains a string T. 


Output Format

For each test case print “YES” if it is possible to form a square fence, else print “NO” without double quotes in a new line.


Constraints

1 ≤ TC ≤ 10^2
1 ≤ |S| ≤ 40
|T|=|S|

Sample Input 1

2
abacde
beacda
abcdef
abdefc

Sample Output 1

YES
YES

Note

TEST CASE 1:

S = prqs

T = psrq

4 transitions are : 

prqs → pqrs
pqrs → srqp
srqp → srpq
srpq → psrq
 

TEST CASE 2:

S = abdec

T = bdaec

4 transitions are : 

abdec → abced
abced → aecbd
aecbd → bcead
bcead → bdaec

*/


#include<bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using lli =  int long long;
lli n,n2;
lli tot = 1e9+10;
set<string> gen;

string reverse1(string s , int l ,int r){
    reverse(s.begin()+l,s.begin()+r+1);
    return s;
}


// generates all posible strings from substring reversal with k moves left 
void brute(string st , int k){

    if(k==0){ 
        gen.insert(st);
        return;
    }
    int l=0;int r = st.length()-1;

   for(int i=0;i<=r;i++){
        for(int j=i;j<=r;j++){
            string s2 = st;
            s2 = reverse1(st,i,j);
            brute(s2,k-1);
        }   
    }

}


int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    IOS
    lli t;

    cin>>t;
    while(t--){
        string s,t;
        cin >> s >> t;
        set<string> gen1;
        set<string> gen2;

        brute(s,2);
        gen1=gen;      //Stores all possible values of S2 after 2 step substring reversal from S
        gen.clear();

        brute(t,2);
        gen2=gen;       //Stores all possible values of S2 after 2 step substring reversal from T
        gen.clear();

        //Check if any S2 value from the 2 sets are same.
        int c=0;
        for(auto it:gen1){
            if(gen2.find(it)!=gen2.end()){
                cout << "YES" <<"\n";
                c=1;
                break;
            }

        }
        if(!c)
            cout << "NO" << "\n";
    }
    return 0;
}

//TIME COMPLEXITY
// O(N^5 logN)
