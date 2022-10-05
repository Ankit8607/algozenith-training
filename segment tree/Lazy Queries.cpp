// https://www.learning.algozenith.com/problems/Lazy-Queries-381

/*

Description

Your task is to maintain an array of n values and efficiently process the following types of queries:

Increase each value in range [a, b] by x.
Set each value in range [a, b] to x.
Calculate the sum of values in range [a, b].
 

Input Format

The first input line has two integers n and q: the array size and the number of queries.
The next line has n values t1, t2, …, tn: the initial contents of the array.
Finally, there are q lines describing the queries. The format of each line is one of the following: "1 a b x", "2 a b x", or "3 a b".


Output Format

Print the answer to each sum query.


Constraints

1 ≤ n, q ≤ 2 x 105
1 ≤ ti, x ≤ 106
1 ≤ a ≤ b ≤ n


Sample Input 1

6 5
2 3 1 1 5 3
3 3 5
1 2 4 2
3 3 5
2 2 4 5
3 3 5

Sample Output 1

7
11
15

*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define LD long double

const int N = 100010;

struct node{
    int st,inc,sum;
    node(int a=0,int b=0,int c=0):
        st(a),inc(b), sum(c){}
};

int n,q;
int arr[200100];
node t[800100];

void build(int id, int l, int r) {
    if(l==r){
        t[id]=node(0,0,arr[l]);
        return;
    }
    int mid = (l+r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    t[id].sum = t[id<<1].sum+t[id<<1|1].sum;
    return;
}

void push(int id,int l,int r){
    if(t[id].st){
        t[id].sum=(r-l+1)*t[id].st;
        if(l!=r){
            t[id<<1].st=t[id].st;
            t[id<<1].inc=0;
            t[id<<1|1].st=t[id].st;
            t[id<<1|1].inc=0;
        }
        t[id].st=0;
        // t[id].inc=0;
    }
    if(t[id].inc){
        t[id].sum+=(r-l+1)*t[id].inc;
        if(l!=r){
            // if(t[id<<1].st) t[id<<1].st+=t[id].inc;
            t[id<<1].inc+=t[id].inc;
            // if(t[id<<1|1].st) t[id<<1|1].st+=t[id].inc;
            t[id<<1|1].inc+=t[id].inc;
        }
        t[id].inc=0;
        // t[id].st=0;
    }
}
void update1(int id, int l, int r, int lq, int rq,int val) {
    push(id,l,r);
    if(l>rq || r<lq) return;
    if(l>=lq and r<=rq) {
        t[id].inc+=val;
        push(id,l,r);
        return;
    }
    int mid = (l + r) / 2;
    update1(2 * id, l, mid, lq, rq,val);
    update1(2 * id + 1, mid + 1, r, lq,rq,val);
    t[id].sum=t[id<<1].sum+t[id<<1|1].sum;
    return;
}

void update2(int id, int l, int r, int lq, int rq,int val) {
    push(id,l,r);
    if(l>rq || r<lq) return;
    if(l>=lq and r<=rq) {
        t[id].st=val;
        t[id].inc=0;
        push(id,l,r);
        return;
    }
    int mid = (l + r) / 2;
    update2(2 * id, l, mid, lq, rq,val);
    update2(2 * id + 1, mid + 1, r, lq,rq,val);
    t[id].sum=t[id<<1].sum+t[id<<1|1].sum;
    return;
}

int query(int id, int l, int r,int lq,int rq) {
    push(id,l,r);
    if(l>rq || r<lq) return 0;
    if(l >=lq and r<=rq) {
        return t[id].sum;
    }
    int mid = (l + r) / 2;
    return query(id<<1,l,mid,lq,rq)+query(id<<1|1,mid+1,r,lq,rq);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>arr[i];
    build(1,0,n-1);
    while(q--){
        int t,a,b,x; cin>>t;
        if(t==1){
            cin>>a>>b>>x;
            update1(1,0,n-1,a-1,b-1,x);
        }
        else if(t==2){
            cin>>a>>b>>x;
            update2(1,0,n-1,a-1,b-1,x);
        }
        else{
            cin>>a>>b;
            cout<<query(1,0,n-1,a-1,b-1)<<endl;
        }
    }
    return 0;
}
