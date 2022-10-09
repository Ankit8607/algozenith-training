// https://www.learning.algozenith.com/problems/Molecular-Formula-436

/*

Description

You've been given chemical formula of a compound. Your task is to print the count of each atom.
The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.
One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow. For example, H2O and H2O2 are possible, but H1O2 is impossible.
Two formulas concatenated together to produce another formula. For example, H2O2He3Mg4 is also a formula.
A formula placed in parentheses, and a count (optionally added) is also a formula. For example, (H2O2) and (H2O2)3 are formulas.

It's guaranteed that the total count of each individual atom is within INT_MAX.


Input Format

The only line of input contains a string S representing the chemical formula of a compound.


Output Format

Print the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.


Constraints

1 ≤ |S| ≤ 103


Sample Input 1

Mg(OH)2

Sample Output 1

H2MgO2

Sample Input 2

K4(ON(SO3)2)2

Sample Output 2

K4N2O14S4

Sample Input 3

(Ti34)10

Sample Output 3

Ti340

*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

string solve(string formula) {
    stack < pair < string, int > > s;

    for(int i = 0; i < (int)formula.length(); i++) {
        if(formula[i] == '(') {
            s.push({"(", -1});
        }
        else if(formula[i] == ')') {
            int multiplier = 0;
            while(i + 1 < (int)formula.length() && formula[i + 1] >= '0' && formula[i + 1] <= '9') {
                multiplier *= 10;
                multiplier += formula[i + 1] - '0';
                i++;
            }
            if(!multiplier) multiplier = 1;

            stack < pair < string, int > > temp;

            while(!s.empty()) {
                auto it = s.top();
                s.pop();
                if(it.first == "(") break;
                temp.push({it.first, it.second * multiplier});
            }

            while(!temp.empty()) {
                s.push(temp.top());
                temp.pop();
            }
        }
        else if(formula[i] >= 'A' && formula[i] <= 'Z') {
            string atom = "";
            atom += formula[i];
            while(i + 1 < (int)formula.length() && formula[i + 1] >= 'a' && formula[i + 1] <= 'z') {
                atom += formula[i + 1];
                i++;
            }

            int cnt = 0;
            while(i + 1 < (int)formula.length() && formula[i + 1] >= '0' && formula[i + 1] <= '9') {
                cnt *= 10;
                cnt += formula[i + 1] - '0';
                i++;
            }

            if(!cnt) cnt = 1;

            s.push({atom, cnt});
        }
    }

    map < string, int > M;

    while(!s.empty()) {
        M[s.top().first] += s.top().second;
        s.pop();
    }

    string ans = "";

    for(auto it : M) {
        ans += it.first;
        if(it.second > 1) ans += to_string(it.second);
    }

    return ans;
}


signed main()
{
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string formula;
    cin >> formula;

    cout << solve(formula) << "\n";

    return 0;
}


