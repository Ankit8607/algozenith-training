// https://www.learning.algozenith.com/problems/Period-of-a-string-397

/*

Description

For each prefix of a given string S with N characters consisting of lowercase characters, we want to know whether the prefix is a periodic string. That is, for each i (2 <= i <= N) we want to know the largest K > 1 (if there is one) such that the prefix of S with length i can be written as AK , that is A concatenated K times, for some string A. Of course, we also want to know the period K. If there are multiple AK print the maximum value of K.


Input Format

The first line contains an integer T, ( 1 ≤ T ≤ 10000) - the number of test cases.

The first line of each test case contains an integer N, ( 2 ≤ N ≤ 100000).

The second line contains a string S of length N.

Sum of N across all test cases ≤ 10^6.


Output Format

For each test case, output “Test case #” and the consecutive test case number on a single line; then, for each prefix with length i that has a period K > 1, output the prefix size i and the largest period K separated by a single space; the prefix sizes must be in increasing order. Print a blank line after each test case.


Sample Input 1

2
9
abababaab
6
ffffff

Sample Output 1

Test case #1
4 2
6 3

Test case #2
2 2
3 3
4 4
5 5
6 6

*/


#include <bits/stdc++.h>
using namespace std;

#define int long long

int abc = 1;
int pi[100005];

void prefix(string s) {
    int n = s.size();
    pi[0] = 0;
    for (int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]) {
            j = pi[j-1];
        }
        if(s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cout << "Test case #" << abc++ << "\n";
        int n;
        cin >> n;
        string s;
        cin >> s;
        prefix(s);
        for (int i = 1; i < n; ++i) {
            if((i+1)%(i+1-pi[i]) == 0 && (i+1)/(i+1-pi[i]) > 1) {
                cout << i+1 << " " << (i+1)/(i+1-pi[i]) << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}
