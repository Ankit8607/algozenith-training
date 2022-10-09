// https://www.learning.algozenith.com/problems/Min-Stack-435

/*

Description

Implement a stack that supports the following operations.

push x -- Push element x onto stack.
pop -- Remove the element on top of the stack, if the stack is non-empty. Otherwise do nothing.
top -- Print the top element, if the stack is non-empty. Otherwise, print -1.
getMin -- Print the minimum element in the stack, if the stack is non-empty. Otherwise, print -1.
Initially, the stack is empty.


Input Format

The first line of input contains Q - the number of queries.
Each of next line contains input in one of the four formats mentioned in the problem statement.


Output Format

Print the answer for the top and getMin operations.


Constraints

1 ≤ Q ≤ 106
0 ≤ x ≤ 109


Sample Input 1

11
push 1
push 3
top
getMin
pop
top
getMin
pop
pop
top
getMin

Sample Output 1

3
1
1
1
-1
-1

*/


class MinStack {
public:
    stack<int> st, minSt;

    MinStack() {}

    void push(int x) {
        if(st.empty()) {
            st.push(x);
            minSt.push(x);
            return;
        }
        st.push(x);
        minSt.push(min(minSt.top(), x));
        return;
    }

    void pop() {
        if(st.empty()) return;
        st.pop();
        minSt.pop();
    }

    int top() {
        if(st.empty()) return -1;
        return st.top();
    }

    int getMin() {
        if(minSt.empty()) return -1;
        return minSt.top();
    }
};
