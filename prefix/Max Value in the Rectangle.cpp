// https://www.learning.algozenith.com/problems/Max-Value-in-the-Rectangle-27

/*

Description

Given a 2d-array of dimension N*M and Q queries. In each query five integers x1, y1, x2, y2, C is given, you have to increase the value of each cell in the submatrix with (x1,y1) be the leftmost corner and (x2,y2) be the rightmost corner by C. Initially the value of all the cell of the 2d-array is 0.

After all the query is performed, print the maximum value present in the 2d-array and the number of the cell with the maximum value.


Input Format

The first line contains three space-separated integers N, M, Q where 1<=N, M<=10^3, 1<=Q<=10^6.

The next Q lines contains five space separated integers x1, y1, x2, y2, C where 1<=x1<=x2<=N, 1<=y1<=y2<=M, -10^9<=C<=10^9.


Output Format

After all the query is performed, print 2 space-separated integers representing the maximum value present in the 2d-array and the number of the cell with the maximum value.


Sample Input 1

5 5 5
1 1 2 2 -8
1 2 3 4 9
2 3 3 3 -2
4 4 4 4 -4
2 3 2 4 0

Sample Output 1

9 5

*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,m,q;
    cin>>n>>m>>q;
    ll arr[n+1][m+1];
    memset(arr,0,sizeof(arr));
    for(int i=0;i<q;i++){
        ll x1,y1,x2,y2,c;
        cin>>x1>>y1>>x2>>y2>>c;
        arr[x1][y1]+=c;
        if(x2<n and y2<m)
            arr[x2+1][y2+1]+=c;
        if(y2<m)
            arr[x1][y2+1]-=c;
        if(x2<n)
            arr[x2+1][y1]-=c;
    }

    for(int i=1;i<=n;i++){  // row wise prefix sum
        for(int j=2;j<=m;j++)
            arr[i][j]+=arr[i][j-1];
    }
    for(int i=1;i<=m;i++) // column wise prefix sum
        for(int j=2;j<=n;j++)
            arr[j][i]+=arr[j-1][i];
    ll ans = -1e18;  // minimum value possible is -Q*1e9 = -1e16
    int cnt = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i][j]>ans)
                ans = arr[i][j],cnt = 1;
            else if(arr[i][j]==ans)
                cnt++;
        }
    }
    cout<<ans<<" "<<cnt<<"\n";
}
