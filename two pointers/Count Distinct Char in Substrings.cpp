// https://www.learning.algozenith.com/problems/Count-Distinct-Char-in-Substrings-60

/*

Description

Given a string S consisting of the lowercase character of length N. Score of a string is the number of distinct characters present in the string. Like the score of "character" is 6.

Find the sum of the score of all substring of S.


Input Format

The first line contains T, the number of test cases (1<=T<=10).

The first line of each test case contains an integers N, size of the string, 1<=N<=10^5.

The second line of each test case contains a string S of length N.


Output Format

For each test case print the sum of the score of all substring of S in a newline.


Sample Input 1

5
2
ac
3
aac
5
abode
5
aaaaa
10
jdnbfjdhzw

Sample Output 1

4
8
35
15
207

Note

For the 1st test case:
Substring and score = ("a",1), ("c",1) ("ac",2).
Total score = 4

For the 2nd test case:
Substring and score = ("a",1), ("aa",1), ("aac",2), ("a",1), ("ac",2), ("c",1).
Total score = 8

*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int mod= 1000000007;
const int N=400010;
#define endl "\n"
#define F first
#define S second
#define MP make_pair
#define ii pair<int,int>
#define all(a) a.begin(),a.end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve(){
	int n; cin>>n;
	string s; cin>>s;
	int ans=0;
	int last=0;
	for(char ch='a';ch<='z';ch++){
		last=-1;
		for(int i=0;i<n;i++){
			if(s[i]==ch){
				ans+=(i-last)*(n-i);
				last=i;
			}
		}
	}
	cout<<ans<<endl;
}

signed main(){
    IOS
    int t; cin>>t; while(t--)
    solve();
    return 0;
}
