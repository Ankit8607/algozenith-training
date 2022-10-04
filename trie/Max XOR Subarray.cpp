// https://www.learning.algozenith.com/problems/Max-XOR-Subarray-394

/*

Description

Given an array of integers. find the maximum XOR subarray value in the given array.


Input Format

The first line contains an integer T ( 1 ≤ T ≤ 10), the number of test cases.

The first line of each test case contains 2 space-separated integers N,1 ≤ N ≤ 10^5.

The second line of each test case contains N space-separated integers, 1≤ Ai ≤ 10^5


Output Format

For each test case print the answer in a new line.


Sample Input 1

3
5
1 2 3 4 5
6
7 14 6 8 6 65
5
74 14 5 6 9

Sample Output 1

7
79
78

*/


#include <bits/stdc++.h>
using namespace std;

#define int long long

class node {
public:
    int freq=0;
    node* child[2]={0};
};

void insert(int x, node *root){
    node *cur=root;
    for(int i=31;i>=0;i--){
        int bit=(x>>i)&1;
        if(cur->child[bit]==NULL) cur->child[bit]=new node;
        cur=cur->child[bit];
        cur->freq++;
    }
}

int findMaxXOR(int x, node* root) {
    node* cur = root;
    int ans = 0;
    for (int j = 31; j >= 0; --j) {
        int bit=(x>>j)&1;
        if(cur->child[1^bit]!=NULL and (cur->child[1^bit]->freq)>0){
            ans+=(1<<j);
            cur=cur->child[1^bit];
        }
        else cur=cur->child[bit];
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        node* root = new node();
        int pre = 0;
        int ans = 0;
        insert(0, root);
        for (int i = 0; i < n; ++i) {
            pre ^= v[i];
            ans = max(ans, findMaxXOR(pre, root));
            insert(pre, root);
        }
        cout << ans << "\n";
    }
    return 0;
}
