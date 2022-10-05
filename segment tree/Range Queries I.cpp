// https://www.learning.algozenith.com/problems/Range-Queries-I-375

/*

Description

You have given an array A of n elements. Your task is to process q queries of the following types.

1 i x : Update the value at position i to x.
2 i j : Print the sum of values in the range [i, j].

Input Format

The first input line has two integers n and q: the number of values and queries.
The second line has n integers A1, A2, …, An: the array values.
Finally, there are q lines describing the queries. Each line has three integers: either "1 i x" or "2 i j".


Output Format

Print the result of each query of type 2.


Constraints

1 ≤ n, q ≤ 2 x 105
1 ≤ Ai, x ≤ 109
1 ≤ i ≤ n
1 ≤ i ≤ j ≤ n


Sample Input 1

8 4
3 2 4 5 1 1 5 3
2 1 4
2 5 6
1 3 1
2 1 4

Sample Output 1

14
2
11

*/


#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define F first
#define S second
#define int long long
int mod=1000000007;
const int N=200010;

int n,q;
int arr[200100];
int t[800400];

void build(int id, int l, int r){
	if(l==r){
		t[id]=arr[l];
		return;
	}
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	t[id]=t[id<<1]+t[id<<1|1];
}

void update(int id,int l,int r,int i,int v){
	if(l>i || r<i) return;
	if(l==r){
		arr[l]=v;
		t[id]=v;
		return;
	}
	int mid=(l+r)/2;
	update(id<<1,l,mid,i,v);
	update(id<<1|1,mid+1,r,i,v);
	t[id]=t[id<<1]+t[id<<1|1];
}

int query(int id,int l,int r,int lq,int rq){
	if(l>rq || r<lq) return 0;
	if(l>=lq and r<=rq) return t[id];
	int mid=(l+r)/2;
	return query(id<<1,l,mid,lq,rq)+query(id<<1|1,mid+1,r,lq,rq);
}

void solve(){
	cin>>n>>q;
	map<int,int> mp;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	build(1,0,n-1);
	while(q--){
		int a; cin>>a;
		if(a==1){
			int i,x; cin>>i>>x; i--;
			update(1,0,n-1,i,x);
		}
		else{
			int i,j; cin>>i>>j;
			i--,j--;
			cout<<query(1,0,n-1,i,j)<<endl;
		}
	}
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
	solve();
    return 0;
}
