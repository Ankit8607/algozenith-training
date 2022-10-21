// https://www.learning.algozenith.com/problems/Count-Good-Subsequences-185

/*

Description

You are given a sequence A1, A2, …, AN. Let's call a subsequence Ai1, Ai2, …, Aik (for any k > 0, 1 ≤ i1 < i2 < … < ik ≤ N) good if the median of this subsequence is an element of this subsequence. 
Find the number of good subsequences. Since this number may be large, compute it modulo 1000000007 (109+7).

Note:

The median of a set of data is the middlemost number in the set. The median is also the number that is halfway into the set. To find the median, the data should first be arranged in order from least to greatest.
For odd length sequence, the median is the middle element in the sorted sequence. While for even length sequence, it is the average of the middle two elements.

Input Format

The first line of input contains T - the number of test cases.
The first line of each test case contains a number N - the size of the array.
The second line of each test case contains N space-separated integers A1, A2, ..., AN. 


Output Format

For each test case, print the number of good subsequences on a new line.


Constraints

1 ≤ T ≤ 30
1 ≤ N ≤ 1000
1 ≤ Ai ≤ 2N


Sample Input 1

1
3
2 3 2

Sample Output 1

5

Note

The good subsequences are [2], [3], [2], [2,2], [2,3,2].

*/


//GMEDIAN on codechef
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
const int mod=1e9+7;
vector<ll> fact;
vector<ll> inv_fact;

inline ll mul(ll a,ll b){ return ((a%mod)*(b%mod))%mod;}
inline ll add(ll a,ll b){ return ((a%mod)+(b%mod))%mod;}
inline ll sub(ll a,ll b){ return (((a%mod)-(b%mod))%mod + mod)%mod;}

ll bin(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1){
			res=mul(res,a);
		}
		b>>=1;
		a=mul(a,a);
	}return res%mod;
}
ll pre(){
	fact[0]=fact[1]=1;
	for(ll i=2;i<fact.size();i++){
		fact[i]=mul(fact[i-1],i);
	}
	inv_fact[0]=1;
	inv_fact[fact.size()-1]=bin(fact[fact.size()-1],mod-2);
	for(int i=fact.size()-2;i>=1;i--){
		inv_fact[i]=mul(inv_fact[i+1],(i+1));
	}
}
ll ncr(ll n,ll r){
	if(n<r) return 0LL;
	//nCr= n!/(r!*(n-r)!)
	ll nrr=inv_fact[n-r];
	ll rr=inv_fact[r];
	return mul(fact[n],mul(nrr,rr));
}


void solve(){

	int n; cin>>n;
	vector<ll> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];

	//odd length subseq(s)
	ll ans=bin(2,n-1);
	
	//even length subseq(s)
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++){
		ll m1=arr[i];//left middle 
		int l=i;
		int r=n-1-i;

		auto it=upper_bound(arr.begin(),arr.end(),m1)-arr.begin()-i-1;
		

		if(it>0){		
			ll temp_ans=1;
			for(int j=0;j<=min(l,r);j++){
				temp_ans=mul(ncr(l,j),sub(ncr(r,j+1),ncr(r-it,j+1)));
				ans=add(ans,temp_ans);
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    fact.clear();fact.resize(9999); 
    inv_fact.clear();inv_fact.resize(9999); pre(); 
    int t; cin>>t; while(t--) 
    solve();
}
/*

        /*
        *   choosing the A[i] to be median m1 for left side
        *   fixing left A[i]=m1
        *   (.............)A[i] (.............)
        *   the left bracket contains j elements
        *   the right bracket must contain j+1 elements with at least one A[i]
        *   rc(j+1)-(r-k)c(j+1)
        */
