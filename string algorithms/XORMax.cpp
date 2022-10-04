// https://www.learning.algozenith.com/problems/XORMax-392

/*

Description

You are given q queries and a multiset A, initially containing only integer 0. There are three types of queries:

"+ x" — add integer x to multiset A.

"- x" — erase one occurrence of integer x from multiset A. It's guaranteed that at least one x is present in the multiset A before this query.

"? x" — you are given integer x and need to compute the value , i.e. the maximum value of bitwise exclusive OR (also know as XOR) of integer x and some integer y from the multiset A.


Input Format

First line contains an integer q, 1 ≤ q ≤ 10^5.

Each of the following q lines of the input contains one of three characters '+', '-' or '?' and an integer xi (1 ≤ xi ≤ 109). It's guaranteed that there is at least one query of the third type.

Note, that the integer 0 will always be present in set A.


Output Format

For each query of the type '?' print one integer — the maximum value of bitwise exclusive OR (XOR) of integer xi and some integer from the multiset A.


Sample Input 1

12
? 4
+ 4
? 4
+ 4
? 3
- 4
- 4
? 3
+ 4
? 4
+ 1
+ 1

Sample Output 1

4
4
7
3
4

*/


#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N=10000002;

struct node{
    node *child[2];
    int cnt;
    node(){
        cnt=0;
        child[0]=NULL;
        child[1]=NULL;
    } 
};

void insert(int x, node *root){
    node *cur=root;
    for(int i=31;i>=0;i--){
        // cout<<i<<" ";
        cur->cnt++;
        int bit=(x>>i)&1;
        if(cur->child[bit]==NULL) cur->child[bit]=new node();
        cur=cur->child[bit];
    }
    cur->cnt++;
}

void erase(int x, node *root){
    node *cur=root;
    for(int i=31;i>=0;i--){
        cur->cnt--;
        int bit=(x>>i)&1;
        cur=cur->child[bit];
    }
    cur->cnt--;
}

int fmax(int x, node * root){
    node *cur=root;
    int ans=0;
    // cout<<"hi"<<endl;
    for(int i=31;i>=0;i--){
        // cout<<i<<" ";
        int bit=(x>>i)&1;
        if(cur->child[1^bit]!=NULL and (cur->child[1^bit]->cnt)>0){
            ans+=(1<<i);
            cur=cur->child[1^bit];
        }
        else cur=cur->child[bit];
    }
    return ans;
}
void solve(){
    int q; cin>>q;
    struct node *root = new node;
    insert(0,root);
    for(int i=0;i<q;i++){
        char c; int a;
        cin>>c>>a;
        if(c=='+') insert(a,root);
        else if(c=='-') erase(a,root);
        else cout<<fmax(a,root)<<endl;
    }
}

signed main()
{
    #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
    solve();
}
