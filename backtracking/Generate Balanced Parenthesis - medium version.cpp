// https://www.learning.algozenith.com/problems/Generate-Balanced-Parenthesis---medium-version-465

/*

Description

You have given two positive integers n and k. Your task is to print all balanced parenthesis of length n in lexicographic order (https://en.wikipedia.org/wiki/Lexicographic_order) with depth exactly k. 

Balanced parentheses mean that each opening symbol has a corresponding closing symbol and the pairs of parentheses are properly nested.

Note:

depth("") = 0.
depth('(' + A + ')) = depth(A) + 1, where A is a balanced paranthesis sequence.
depth(A + B) = max(depth(A), depth(B)), where A and B are both balanced paranthesis sequence.
depth("(") = depth(")") = 0

Input Format

The only line of input contains two numbers number n and k.


Output Format

Print all balanced parenthesis of length n with depth k in lexicographic order.


Constraints

2 ≤ n ≤ 24
1 ≤ k ≤ n / 2
It is guaranteed that n is an even number.


Sample Input 1

6 2

Sample Output 1

(()())
(())()
()(())

Sample Input 2

4 2

Sample Output 2

(())

*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

string ans = "";

void dfs(int curLen, int totalLen, int openCnt, int depth, int k) {
    if(curLen == totalLen) {
        assert(openCnt == 1);
        ans += ")";
        if(depth == k) cout << ans << "\n";
        ans.pop_back();
        return;
    }

    if(!openCnt) {
        ans += "(";
        dfs(curLen + 1, totalLen, openCnt + 1, max(depth, openCnt + 1), k);
        ans.pop_back();
    }
    else {
        int remLen = totalLen - curLen + 1;
        if(remLen > openCnt && openCnt < k) {
            ans += "(";
            dfs(curLen + 1, totalLen, openCnt + 1, max(depth, openCnt + 1), k);
            ans.pop_back();
        }
        ans += ")";
        dfs(curLen + 1, totalLen, openCnt - 1, max(depth, openCnt - 1), k);
        ans.pop_back();
    }
}

signed main()
{
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    dfs(1, n, 0, 0, k);

    return 0;
}
