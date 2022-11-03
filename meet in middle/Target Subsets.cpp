// https://www.learning.algozenith.com/problems/Target-Subsets-135

/*

Description:

You have given an array of length N, and a number X. Find the number of subsets with the sum of elements less than equal to X.

Note:

The sum of elements in an empty subset is 0.
The set may contain duplicates elements.

Input Format

The first line of input contains T - the number of test cases.
The first line of each test case contains two space-separated numbers N and X.
The second line of each test case contains N space-separated integers A1, A2, ..., AN.  


Output Format

Print the number of subsets with a sum less than equal to X in a new line for each test case.


Constraints

1 ≤ T ≤ 5
1 ≤ N ≤ 35
0 ≤ Ai ≤ 104
0 ≤ X ≤ 106


Sample Input 1

2
2 1
1 2
3 8
2 2 6

Sample Output 1

2
7

Note

Explanation 1:
The subsets are {}, {1}, {2}, {1, 2}. The number of subsets with sum ≤ 1 is 2.

Explanation 2:
The subsets are {}, {2}, {2}, {6}, {2, 2}, {2, 6}, {2, 6}, {2, 2, 6} The number of subsets with sum ≤ 8 is 7.

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

int n; 
int a[18],b[18];
multiset<int>am,bm;

int power(int a,int b){
	int ans=1;
	while(b){
		if(b&1) ans*=a;
		a*=a;
		b>>=1;
	}
	return ans;
}

void rec1(int level,int sum){
	if(level==n/2){
		am.insert(sum);
		// cout<<sum<<" ";
		return;
	}
	rec1(level+1,sum);
	rec1(level+1,sum+a[level]);
	return;
}
void rec2(int level,int sum){
	if(level==(n-n/2)){
		bm.insert(sum);
		// cout<<sum<<" ";
		return;
	}
	rec2(level+1,sum);
	rec2(level+1,sum+b[level]);
	return;
}
void solve(){
	am.clear();
	bm.clear();
	int x;
	cin>>n>>x;
	for(int i=0;i<n/2;i++) cin>>a[i];
	for(int i=0;i<n-n/2;i++) cin>>b[i];
	if(n==1){
		if(b[0]<=x) cout<<2<<endl;
		else cout<<1<<endl;
		return;
	}
	rec1(0,0);
	rec2(0,0);
	// bm.erase(bm.begin());
	auto it=bm.end();
	it--;
	int ind=bm.size();
	int ans=0;
	// cout<<"am= ";
	// for(auto i:am) cout<<i<<" "; cout<<endl;
	// cout<<"bm= ";
	// for(auto i:bm) cout<<i<<" "; cout<<endl;
	for(auto i:am){
		if(i>x) break;
		while(x-i<*it){
			if(it==bm.begin()){
				ind--;
				break;
			}
			it--;
			ind--;
		}
		ans+=(ind);
	}
	cout<<ans<<endl;
}

signed main(){
    IOS
    int t; cin>>t; while(t--)
    solve();
    return 0;
}
