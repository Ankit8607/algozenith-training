// https://www.learning.algozenith.com/problems/Longest-Palindromic-Substring---Hard-Version-417

/*

Description

Given a string of length 
n
, your task is to determine the longest palindromic substring of the string. For example, the longest palindrome in "algoazzaa" is "azza".
If there are multiple longest palindromic substrings, Output the one which comes first in the string.


Input Format

The first line contains 
T
 - the number of test cases.
The first line of each test case contains a string of length 
n
. Each character is one of a–z.


Output Format

For each test case, Output the Longest Palindromic Substring.
If there are multiple longest palindromic substrings, Output the one which comes first in the string.


Constraints

1
≤
T
≤
10
4

1
≤
n
≤
10
5
Sum of 
n
 across all test cases is 
≤
 
10
6
.


Sample Input 1

9
algoazzaa
aaaaaaaaaa
ababababab
ihpohpzoffel
flexflexvpqxierullgcfckjqflexflex
obsession
abcxcbaxcba
zzabc
aaccaabbaaccaaccaabbaaccaa

Sample Output 1

azza
aaaaaaaaaa
ababababa
ff
cfc
ses
abcxcba
zz
aaccaabbaaccaaccaabbaaccaa

*/


#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define F first
#define S second
#define pi pair<int,int>
#define pl pair<ll,ll>

string s;

void findLongestPalindromicString()
{
    int N = s.length(); N = 2*N + 1;
    int L[N]; 
    L[0] = 0; L[1] = 1;
    int C = 1; 
    int R = 2; 
    for (int i = 2; i < N; i++)
    {
        int iMirror = 2*C-i;
        L[i] = 0;
        if(R > i)
            L[i] = min(L[iMirror], R-i);
        while ( (i+L[i]<N && i-L[i]>0) && ( ((i+L[i]+1)%2==0)||(s[(i+L[i]+1)/2]==s[(i-L[i]-1)/2])))
            L[i]++;
        if(i+L[i]>R)
        {
            C=i;
            R=i+L[i];
        }
    }
    cout<<*max_element(L,L+N)<<"\n";
}
int main() {   

    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);   

    int t_;
    cin>>t_;
    for(int t__=1;t__<=t_;t__++)
    {
        int n;
        cin>>n;
        cin>>s;
        findLongestPalindromicString();
    }
    return 0;
}
