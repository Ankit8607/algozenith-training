// https://www.learning.algozenith.com/problems/Queue-using-2-Stacks-AZ101-330

/*

Description

Implement a queue using 2 stacks. You will be given the following type of Q queries:

push x - add x to the queue
pop - pop the front element of the queue, you also have to print the element you have popped.
front - find the element at the front of the queue

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer Q - the number of queries

Each of the next Q lines contain the queries.


Output Format

For each test case, print the required queries.


Constraints

1≤ T ≤ 106

1≤ Q ≤ 106

1≤ X ≤ 106

It is guaranteed that the sum of Q over all test cases does not exceed 106.


Sample Input 1

1
7
push 3
push 5
pop
front
push 7
pop
pop

Sample Output 1

3
5
5
7

Note

Queue becomes: [3]
Queue becomes: [3, 5]
Queue becomes [5] and element at front was 3
Queue becomes [5]  and element at front is 5
Queue becomes [5, 7]
Queue becomes [7] and element at front was 5
Queue becomes empty and element at front was 7

*/

#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        stack<int> s1, s2;
        int front = 0;
        int q;
        cin >> q;
        while (q--) {
            string s;
            cin >> s;
            if(s == "push") {
                int x;
                cin >> x;
                if(s1.empty()) {
                    front = x;
                }
                s1.push(x);
            }
            else if(s == "pop") {
                if(s2.empty()) {
                    while(!s1.empty()) {
                        s2.push(s1.top());
                        s1.pop();
                    }
                }
                int x = s2.top();
                s2.pop();
                cout << x << "\n";
            }
            else { // front
                if(s2.empty()) {
                    cout << front << "\n";
                }
                else {
                    cout << s2.top() << "\n";
                }
            }
        }
    }
    return 0;
}
