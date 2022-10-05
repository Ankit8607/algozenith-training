// https://www.learning.algozenith.com/problems/Bracket-Queries-380

/*

Description

You have given a bracket sequence s1, s2, …, sn or in other words, a string s of length n, consisting of characters '(' and ')'. 
You've been asked Q queries. The ith query is of the form li and ri. The answer to the i-th query is the length of the maximum correct bracket subsequence of sequence sli, sli + 1, ..., sri.
Find the correct answer to all queries.


Input Format

The first line contains a sequence of characters s1, s2, ..., sn without any spaces. Each character is either a "(" or a ")". 
The second line contains integer Q — the number of queries. 
Each of the next Q lines contains a pair of integers. The i-th line contains integers li, ri — the description of the i-th query.


Output Format

For each query, print the answer on a new line.


Constraints

1 ≤ n ≤ 106
1 ≤ Q ≤ 105
1 ≤ li ≤ ri ≤ n


Sample Input 1

()
1
1 2

Sample Output 1

2

Sample Input 2

())(())(())(
7
1 1
2 3
1 2
1 12
8 12
5 11
2 10

Sample Output 2

0
0
2
10
4
6
6

*/


#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

struct node{
    int op,cl,ans;
    node(int a=0,int b=0,int c=0):
        op(a),cl(b), ans(c){}
};
string s;
int n;
node t[4000100];

node merge(node a, node b){
    node temp;
    int t=min(a.op,b.cl);
    temp.ans=a.ans+b.ans+2*t;
    temp.op=(a.op+b.op-t);
    temp.cl=(a.cl+b.cl-t);
    // cout<<"temp.ans= "<<temp.ans<<endl;
    return temp;
}
void build(int id, int l, int r) {
    if(l==r){
        if(s[l]=='(') t[id]=node(1,0,0);
        else t[id]=node(0,1,0);
        return;
    }
    int mid = (l+r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    t[id] = merge(t[id<<1],t[id<<1|1]);
    return;
}

// void update(int node, int start, int end, int idx, int val) {
//     if(start == end) {
//         tree[node] = val;
//         return;
//     }
//     int mid = (start + end) / 2;
//     if(idx <= mid) update(2 * node, start, mid, idx, val);
//     else update(2 * node + 1, mid + 1, end, idx, val);
//     tree[node] = tree[2 * node] + tree[2 * node + 1];
//     return;
// }

node query(int id, int l, int r,int lq,int rq) {
    if(l>rq || r<lq) return node(0,0,0);
    if(l >=lq and r<=rq) {
        return t[id];
    }
    int mid = (l + r) / 2;
    return merge(query(id<<1,l,mid,lq,rq),query(id<<1|1,mid+1,r,lq,rq));
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>s;
    n=s.size();
    int q; cin>>q;
    build(1,0,n-1);
    while(q--){
        int l,r; cin>>l>>r;
        cout<<query(1,0,n-1,l-1,r-1).ans<<endl;
    }
    return 0;
}
