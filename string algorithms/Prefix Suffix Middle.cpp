// https://www.learning.algozenith.com/problems/Prefix-Suffix-Middle-398

/*

Description

Given a string S, find the longest string T such that:
→ T is the prefix of S.
→ T is the suffix of S.
→ T is present in the middle of S, such that T is not a prefix and suffix.

Suppose S = “aaaa”, then T = “aa”.
aa is a prefix, S[0..1].
aa is a suffix S[2..3].
aa is present in the middle and it is not a prefix or suffix, S[1..2].

If no T exists then print -1.

 


Input Format

The first line contains an integer T, ( 1 ≤ T ≤ 10000) - the number of test cases.

The first line of each test case contains an integer N, ( 2 ≤ N ≤ 100000).

The second line contains a string S of length N.

Sum of N across all test cases ≤ 10^6.


Output Format

For each test case print the string T, if no string T exists print -1.


Sample Input 1

3
9
abababaab
6
ffffff
5
abcde

Sample Output 1

ab
ffff
-1

1
​


*/


#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void _kmp(){
    int n;cin>>n;
    string s; cin>>s;
    int kmp[n],temp[n]={0};
    kmp[0]=0;
    int j=0;
    for(int i=1;i<n;i++){
        while(j>0 and s[i]!=s[j]) j=kmp[j-1];
        if(s[i]==s[j]) j++;
        kmp[i]=j;
        if(i<n-1)temp[kmp[i]]=1;
    }

    int last=kmp[n-1];
    temp[0]=0;
    if(temp[last]){
        cout<<s.substr(0,last)<<endl;
        return;
    }
    if(last and temp[kmp[last-1]]) cout<<s.substr(0,kmp[last-1])<<endl;
    else cout<<"-1"<<endl;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; 
    while(t--){_kmp();}
    return 0;
}
