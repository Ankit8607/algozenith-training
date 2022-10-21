// https://www.learning.algozenith.com/problems/Good-Numbers-23

/*

Description

There are N students and ith student likes all numbers in the range [li ,ri ], both inclusive. A number is good if it is liked by at least K students.

You are even Q queries. Each query consists of two numbers L, R. You have to find how many numbers in the range [L,R] is good.


Input Format

The first line of input contains three integers, N, K (1 ≤ K ≤ N ≤ 1000000), and Q (1 ≤ Q ≤ 1000000).

The next N lines contain two integers li and ri (1 ≤ li ≤ ri≤ 1000000), describing that the i-th student likes all the numbers [li,ri].

The next Q lines contain L and R, (1 ≤ L ≤ R ≤ 1000000).


Output Format

For each query print how many numbers in the range [L,R] is good in a new line.


Sample Input 1

10 3 10
1 5
2 7
3 9
1 5
3 8
4 10
7 10
8 8
5 5
6 7
1 5
3 8
4 9
3 10
2 6
3 9
7 7
5 5
8 8
3 7

Sample Output 1

4
6
6
7
5
7
1
1
1
5

*/


#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k,q;
    cin>>n>>k>>q;
    int arr[N]; // note that N and n are different.
    for(int i=0;i<N;i++)
        arr[i] = 0;

    for(int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        // use the technique of Partial sum to build the value at each index.
        arr[l]++;
        arr[r+1]--;
    }
    // finally build the prefix sum.
    for(int i=1;i<N;i++)
        arr[i]+=arr[i-1];

    // keep the values 1 where values >=k or else 0.
    for(int i=1;i<N;i++)
        arr[i] = (arr[i]>=k);

    // now to answer query in O(1), we will build prefix sum on this 0/1 array to get count of positions.
    int prefixSum[N];
    prefixSum[0] = 0;
    for(int i=1;i<N;i++){
        prefixSum[i] = prefixSum[i-1]+arr[i];
    }

    while(q--){
        int l,r;
        cin>>l>>r;
        // gives the count of 1 positions in O(1).
        int ans = prefixSum[r]-prefixSum[l-1];
        cout<<ans<<"\n";
    }
}
