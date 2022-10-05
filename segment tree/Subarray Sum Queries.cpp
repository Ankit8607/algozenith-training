// https://www.learning.algozenith.com/problems/Subarray-Sum-Queries-378

/*

Description

There is an array consisting of n integers. Some values of the array will be updated, and after each update, your task is to report the maximum subarray sum in the array.


Input Format

The first input line contains integers n and m: the size of the array and the number of updates. The array is indexed 1, 2,…, n.
The next line has n integers: x1, x2, …, xn: the initial contents of the array.
Then there are m lines describing the changes. Each line has two integers k and x: the value at position k becomes x.


Output Format

After each update, print the maximum subarray sum. Empty subarrays (with sum 0) are allowed.


Constraints

1 ≤ n, m ≤ 2 x 105
−109 ≤ xi ≤ 109
1 ≤ k ≤ n
−109 ≤ x ≤ 109


Sample Input 1

5 3
1 2 -3 5 -1
2 6
3 1
2 -2

Sample Output 1

9
13
6

1
​


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

struct node{
	int lsum,rsum,totsum,maxsum;
	node(int a=0,int b=0,int c=0,int d=0){
		lsum=a;
		rsum=b;
		totsum=c;
		maxsum=d;
	}
};

node t[800800];

void build(int id,int l,int r){
	if(l==r){
		int sum=max(0LL,arr[l]);
		t[id]=node(sum,sum,arr[l],sum);
		return;
	}
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	t[id]=node(max(t[id<<1].lsum,t[id<<1].totsum+t[id<<1|1].lsum),max(t[id<<1|1].rsum,t[id<<1|1].totsum+t[id<<1].rsum),t[id<<1].totsum+t[id<<1|1].totsum,max(t[id<<1].rsum+t[id<<1|1].lsum,max(t[id<<1].maxsum,t[id<<1|1].maxsum)));
}

void update(int id,int l,int r,int x,int val){
	if(l>x || r<x) return;
	if(l==r){
		arr[l]=val;
		int temp=max(val,0LL);
		t[id]=node(temp,temp,val,temp);
		return;
	}
	int mid=(l+r)>>1;
	update(id<<1,l,mid,x,val);
	update(id<<1|1,mid+1,r,x,val);
	t[id]=node(max(t[id<<1].lsum,t[id<<1].totsum+t[id<<1|1].lsum),max(t[id<<1|1].rsum,t[id<<1|1].totsum+t[id<<1].rsum),t[id<<1].totsum+t[id<<1|1].totsum,max(t[id<<1].rsum+t[id<<1|1].lsum,max(t[id<<1].maxsum,t[id<<1|1].maxsum)));
}

// int query(int id,int l,int r){
// 	if(l==r ){
// 		temp=1;
// 		return l;
// 	}
// 	int mid=(l+r)>>1;
// 	return query(id<<1,l,mid,x)+query(id<<1|1,mid+1,r,x);
// }

void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>arr[i];
	build(1,1,n);
	while(q--){
		// cout<<"t[1]= ";
		// cout<<t[1].lsum<<" "<<t[1].rsum<<" "<<t[1].totsum<<" "<<t[1].maxsum<<endl;
		int x,val; cin>>x>>val;
		update(1,1,n,x,val);
		cout<<t[1].maxsum<<endl;
	}
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
	solve();
    return 0;
}
