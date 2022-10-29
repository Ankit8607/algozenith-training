// https://www.learning.algozenith.com/problems/Count-Unique-Char-in-Substrings-61

/*

Description

Given a string S consisting of the lowercase character of length N. Score of a string is the number of unique characters present in the string( characters which are only present once in the string). Like score of "character" is 3 {h,t,e}.

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
6
35
5
194

Note

For the 1st test case:
Substring and score = ("a",1), ("c",1) ("ac",2).
Total score = 4

For the 2nd test case:
Substring and score = ("a",1), ("aa",0), ("aac",1), ("a",1), ("ac",2), ("c",1).
Total score = 6

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
	int lst[26];
	for(int i=0;i<n;i++){
		lst[s[i]]=i;
	}
	int ans=0;
	for(char ch='a';ch<='z';ch++){
		int st=-1,lst=-1;
		for(int i=0;i<n;i++){
			if(s[i]==ch){
				ans+=(lst-st)*(i-lst);
				st=lst;
				lst=i;
			}
		}
		ans+=(lst-st)*(n-lst);
	}
	cout<<ans<<endl;
}

signed main(){
    IOS
    int t; cin>>t; while(t--)
    solve();
    return 0;
}
