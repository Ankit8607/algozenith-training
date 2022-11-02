// https://www.learning.algozenith.com/problems/Modulo-Subsequences-264

/*

Description

You are given an array a consisting of n integers, and additionally an integer m. You have to choose some sequence of indices b1, b2, ..., bk (1 ≤ b1 < b2 < ... < bk ≤ n) in such a way that the value of (a[b1] + a[b2] + ... + a[bk]) mod m is maximized. The chosen sequence can be empty.

Print the maximum possible value of (a[b1] + a[b2] + ... + a[bk]) mod m.


Input Format

The first line contains two integers n and m (1 ≤ n ≤ 35, 1 ≤ m ≤ 109).
The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 109).


Output Format

Print the maximum possible value of (a[b1] + a[b2] + ... + a[bk]) mod m.


Sample Input 1

4 4
5 2 4 1

Sample Output 1

3

Note

You can choose a sequence b = {1, 2}, so the sum (5 + 2) is equal to 7 (and that's 3 after taking it modulo 4).

*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int mod= 1000000007;
const int N=400010;
#define endl "\n"
#define F first
#define S second
#define MP make_pair
#define ii pair<int,int>
#define all(a) a.begin(),a.end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<int> generate(vector<int> &a,int n){
	// cout<<"generate= "<<endl;
	vector<int> ans;
	for(int i=0;i<(1<<n);i++){
		int sum=0;
		for(int j=0;j<n;j++){
			if((1<<j)&i){
				sum+=a[j];
			}
		}
		// cout<<"sum= "<<sum<<endl;
		ans.push_back(sum%mod);
	}
	sort(all(ans));
	return ans;
}

void solve(){
    int n,m; cin>>n>>m;
	mod=m;
	vector<int>a,b;
	for(int i=0;i<n;i++){
		int x; cin>>x;
		if(i&1) b.push_back(x);
		else a.push_back(x);
	}
	vector<int> asub=generate(a,a.size());
	vector<int> bsub=generate(b,b.size());
	int ans=0;
	// cout<<"asub= "<<" ";
	// for(auto i:asub) cout<<i<<" "; cout<<endl;
	// cout<<"bsub= "<<" ";
	// for(auto i:bsub) cout<<i<<" "; cout<<endl;
	// sort(all(bsub));
	for(auto i:asub){
		auto it=upper_bound(all(bsub),m-1-i);
		it--;
		ans=max(ans,i+*it);
	}
	cout<<ans<<endl;
}

signed main(){
    IOS
    // int t; cin>>t; while(t--)
    solve();
    return 0;
}
