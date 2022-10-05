// https://www.learning.algozenith.com/problems/First-Min-Queries-377

/*

Description

You have given an array A of n integers. Your task is to answer q queries. Each query contains an integer x. 
For each query, print the minimum index i such that Ai ≥ x, and then decrease the value at position i by x, i.e., Ai = Ai - x. If there doesn't exist any index i satisfying the condition, then simply print 0.


Input Format

The first input line has two integers n and q: the number of values and queries.
The second line has n integers A1, A2, …, An: the array values.
Finally, there are q integers describing the queries. x1, x2, …, xq.


Output Format

Print the index i as mentioned in the problem statement. If such an index doesn't exist, then print 0.


Constraints

1 ≤ n, q ≤ 2 x 105
0 ≤ Ai, xi ≤ 109


Sample Input 1

8 5
3 2 4 1 5 5 2 6
4 4 7 1 1

Sample Output 1

3 5 0 1 1

*/


#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define F first
#define S second
// #define int long long
int mod=1000000007;
const int N=200010;

int n,q;
int arr[200100];
int t[800800];

void build(int id,int l,int r){
	if(l==r){
		t[id]=arr[l];
		return;
	}
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	t[id]=max(t[id<<1],t[id<<1|1]);
}

void update(int id,int l,int r,int x,int val){
	if(l>x || r<x) return;
	if(l==r){
		arr[l]=val;
		t[id]=val;
		return;
	}
	int mid=(l+r)>>1;
	update(id<<1,l,mid,x,val);
	update(id<<1|1,mid+1,r,x,val);
	t[id]=max(t[id<<1],t[id<<1|1]);
}
int temp;
int query(int id,int l,int r,int x){
	if(t[id] < x || temp) return 0;
	if(l==r ){
		temp=1;
		return l;
	}
	int mid=(l+r)>>1;
	return query(id<<1,l,mid,x)+query(id<<1|1,mid+1,r,x);
}

void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>arr[i];
	build(1,1,n);
	while(q--){
		int x; cin>>x;
		int k=0;
		temp=0;
		int index=query(1,1,n,x);
		cout<<index<<" ";
		if(index) update(1,1,n,index,arr[index]-x);
	}
	cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
	solve();
    return 0;
}
