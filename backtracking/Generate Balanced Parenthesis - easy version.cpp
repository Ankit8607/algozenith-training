// https://www.learning.algozenith.com/problems/Generate-Balanced-Parenthesis---easy-version-464

/*

Description

You have given a positive even integer n. Your task is to print all balanced parenthesis of length n in lexicographic order (https://en.wikipedia.org/wiki/Lexicographic_order). 

Balanced parentheses mean that each opening symbol has a corresponding closing symbol and the pairs of parentheses are properly nested.


Input Format

The only line of input contains a number n.


Output Format

Print all balanced parenthesis of length n in lexicographic order.


Constraints

2 ≤ n ≤ 24
It is guaranteed that n is even.


Sample Input 1

2

Sample Output 1

()

Sample Input 2

4

Sample Output 2

(())
()()

*/


#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

string ans = "";

void dfs(int curLen, int totalLen, int openCnt) {
    if(curLen == totalLen) {
        assert(openCnt == 1);
        ans += ")";
        cout << ans << "\n";
        ans.pop_back();
        return;
    }

    if(!openCnt) {
        ans += "(";
        dfs(curLen + 1, totalLen, openCnt + 1);
        ans.pop_back();
    }
    else {
        int remLen = totalLen - curLen + 1;;
        if(remLen > openCnt) {
            ans += "(";
            dfs(curLen + 1, totalLen, openCnt + 1);
            ans.pop_back();
        }
        ans += ")";
        dfs(curLen + 1, totalLen, openCnt - 1);
        ans.pop_back();
    }
}

signed main()
{
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    dfs(1, n, 0);

    return 0;
}
