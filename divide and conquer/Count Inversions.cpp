// https://www.learning.algozenith.com/problems/Count-Inversions-22

/*

Description

You have given an array A of N elements. An Inversion Count of the array is defined as the number of pairs (i, j) such that Ai > Aj and i < j.
Find the Inversion Count in A.


Input Format

The first line of input contains one integer T (1 ≤ T ≤ 105) — the number of test cases. Then T test cases follow.
The first line of each test case contains N (2 ≤ N ≤ 105), the number of elements in an array A.
The second line contains N space-separated integers A1, A2, …, AN, (0 ≤ Ai ≤ 109)
It is guaranteed that the sum of N over all test cases does not exceed 5 x 105.


Output Format

For each test case, print the answer on a new line denoting the Inversion Count.


Sample Input 1

3

4

8 4 2 1

3

3 1 2

6

1 2 3 4 5 5


Sample Output 1

6

2

0


Note

Explanation 1:
Inversion Pairs are (8, 4), (8, 2), (8, 1), (4, 2), (4, 1), (2, 1).

Explanation 2:
Inversion Pairs are (3, 1), (3, 2).

Explanation 3:
There are no Inversion Pairs. And hence, 0 Inversion Count.

*/


#include<bits/stdc++.h>
using namespace std;
const int mod= 10000007;
#define endl "\n"
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<
    int,
    null_type,
    less_equal<int>,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;
void solve(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    ordered_set st;
    st.insert(arr[0]);
    ll ans=0;
    for(ll i=1;i<n;i++){
        ll t=st.order_of_key(arr[i]+1);
        ans+=max(0ll,i-t);
        st.insert(arr[i]);
    }
    cout<<ans<<endl;
}

signed main(){
    IOS
    int t=1; cin>>t; while(t--) 
    solve();
    return 0;
}
