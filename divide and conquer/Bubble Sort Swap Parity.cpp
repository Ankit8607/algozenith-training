// https://www.learning.algozenith.com/problems/Bubble-Sort-Swap-Parity-24

/*

Description

You all know the Bubble Sort! The classical sorting algorithm.

In this problem, you have to find the parity of the number of swaps that will perform in the standard bubble sort algorithm on the given input array.

For more details about Bubble Sort refer this: https://en.wikipedia.org/wiki/Bubble_sort


Input Format

The first line of input contains one integer T (1 ≤ T ≤ 105) — the number of test cases. Then T test cases follow.
The first line of each test case contains N (2 ≤ N ≤ 105), the number of elements in an array A.
The second line contains N space-separated integers A1, A2, ..., AN, (0 ≤ Ai ≤ 109).
It is guaranteed that the sum of N does not exceed 5 x 105.


Output Format

For each test case, print the answer on a new line denoting the parity of number swaps in the Bubble Sort.


Sample Input 1

3

4

8 4 2 1

3

2 1 3

6

1 2 3 4 5 5


Sample Output 1

0

1

0

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

int merge(int arr[],int tmp[],int l,int mid,int r){
	int ans=0;
	int i=l,j=mid,k=l;
	while(i<mid and j<=r){
		if(arr[i]<=arr[j]) tmp[k++]=arr[i++];
		else{
			ans+=(j%2)+(k%2);
			tmp[k++]=arr[j++];
		}
	}
	while(i<mid) tmp[k++]=arr[i++];
	while(j<=r) tmp[k++]=arr[j++];
	for(int i=l;i<=r;i++) arr[i]=tmp[i];
	return ans%2;
}

int merge_sort(int arr[],int tmp[],int l,int r){
	if(l>=r) return 0;
	int mid=(l+r)/2;
	int ans=merge_sort(arr,tmp,l,mid)+merge_sort(arr,tmp,mid+1,r);
	ans+=merge(arr,tmp,l,mid+1,r);
	return ans%2;
}

void solve(){
	int n; cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int tmp[n];
	cout<<merge_sort(arr,tmp,0,n-1)<<endl;
}

signed main(){
    IOS
    int t; cin>>t; while(t--)
    solve();
    return 0;
}
