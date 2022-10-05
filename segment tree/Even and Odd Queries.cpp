// https://www.learning.algozenith.com/problems/Even-and-Odd-Queries-379

/*

Description

You've given an array A of N integers. Your task is to support the following queries.

0 x y : Modify the number at index x to y.
1 l r : Print the count the number of even numbers in range l to r inclusive.
2 l r : Print the count the number of odd numbers in range l to r inclusive.

Input Format

The first input line has an integer N, the number of elements.
The second line has N integers A1, A2, …, AN: the array values.
The third line has an integer Q, the number of queries.
Each of the next Q lines contains the query of one of the three types described in the statement. 


Output Format

Print the output of query of type 1 and 2 on a new line.


Constraints

1 ≤ N, Q ≤ 105
1 ≤ l ≤ r ≤ N
0 ≤ Ai ≤ 109
1 ≤ x ≤ N
0 ≤ y ≤ 109


Sample Input 1

6
1 2 3 4 5 6
4
1 2 5
2 1 4
0 5 4
1 1 6

Sample Output 1

2
2
4

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
int arr[100100];

struct node{
	int even=0,odd=0;
	// node(){
	// 	even=0;
	// 	odd=0;
	// }
};

node t[400400];
void build(int id,int l,int r){
	if(l==r){
		if(arr[l]%2){
			t[id].odd=1;
		}
		else{
			t[id].even=1;
		}
		return;
	}
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	t[id].even=t[id<<1].even+t[id<<1|1].even;
	t[id].odd=t[id<<1].odd+t[id<<1|1].odd;
}

void update(int id,int l,int r,int x,int val){
	if(l>x || r<x) return;
	if(l==r){
		if(val%2){
			t[id].even--;
			t[id].odd++;
		}
		else{
			t[id].even++;
			t[id].odd--;
		}
		arr[l]=val;
		return;
	}
	int mid=(l+r)>>1;
	update(id<<1,l,mid,x,val);
	update(id<<1|1,mid+1,r,x,val);
	t[id].even=t[id<<1].even+t[id<<1|1].even;
	t[id].odd=t[id<<1].odd+t[id<<1|1].odd;
}

int query(int id,int l,int r,int lq,int rq,int par){
	if(l>rq || r<lq) return 0;
	if(l>=lq and r<=rq){
		if(par) return t[id].odd;
		return t[id].even;
	}
	int mid=(l+r)>>1;
	return query(id<<1,l,mid,lq,rq,par)+query(id<<1|1,mid+1,r,lq,rq,par);
}

void solve(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	build(1,0,n-1);
	cin>>q;
	while(q--){
		int a,x,y; cin>>a>>x>>y;
		x--;
		if(a==0){
			if((arr[x]%2)==(y%2)) continue;
			update(1,0,n-1,x,y);
		}
		else if(a==1){
			y--;
			cout<<query(1,0,n-1,x,y,0)<<endl;
		}
		else{
			y--;
			cout<<query(1,0,n-1,x,y,1)<<endl;
		}
	}
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
	solve();
    return 0;
}
