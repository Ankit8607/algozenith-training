// https://www.learning.algozenith.com/problems/Range-Queries-II-376

/*

Description

You have given an array A of n elements. Your task is to process q queries of the following types.

1 i j x : Increase each value at positions from [i, j] by x.
2 i : Print the value at position i.

Input Format

The first input line has two integers n and q: the number of values and queries.
The second line has n integers A1, A2, …, An: the array values.
Finally, there are q lines describing the queries. Each line has three integers: either "1 i j x" or "2 i".


Output Format

Print the result of each query of type 2.


Constraints

1 ≤ n, q ≤ 2 x 105
1 ≤ Ai, x ≤ 109
1 ≤ i ≤ n
1 ≤ i ≤ j ≤ n


Sample Input 1

8 3
3 2 4 5 1 1 5 3
2 4
1 2 5 1
2 4

Sample Output 1

5
6

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

void update(int id,int l,int r,int lq,int rq,int val){
	if(l>rq || r<lq) return;
	if(l>=lq and r<=rq){
		t[id]+=val;
		return;
	}
	int mid=(l+r)/2;
	update(id<<1,l,mid,lq,rq,val);
	update(id<<1|1,mid+1,r,lq,rq,val);
}

int query(int id,int l,int r,int x){
	if(l>x || r<x) return 0;
	// if(l==r) return arr[l]+=t[id];
	if(l==r){
			arr[l]+=t[id];
			t[id]=0;
			return arr[l];
		}
	if(t[id]){
		t[id<<1]+=t[id];
		t[id<<1|1]+=t[id];
		t[id]=0;
	}
	int mid=(l+r)/2;
	return query(id<<1,l,mid,x)+query(id<<1|1,mid+1,r,x);
}

void solve(){
	cin>>n>>q;
	map<int,int> mp;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	// build(1,0,n-1);
	while(q--){
		int a; cin>>a;
		if(a==2){
			int i; cin>>i;
			i--;
			cout<<query(1,0,n-1,i)<<endl;
		}
		else{
			int i,j,x; cin>>i>>j>>x;
			i--,j--;
			update(1,0,n-1,i,j,x);
		}
	}
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
	solve();
    return 0;
}
