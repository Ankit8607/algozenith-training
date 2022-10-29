// https://www.learning.algozenith.com/problems/Remove-K-integers-59

/*

Description

Given an array N integers in nondecreasing order. Remove K integers such that the maximum difference between two consecutive elements is minimized.


Input Format

The first line contains T, the number of test cases (1<=T<=10).

The first line of each test case contains two integers N and K, 3<=N<=3*10^5, 1<=K<=N-2.

The second line of each test case contains N space-separated integers, -1e9<=A[I]<=1e9.


Output Format

For each test case print a single integer, representing the minimum-maximum difference between two consecutive elements after removing K integers in a new line.


Sample Input 1

2
5 1
1 5 6 8 9
5 2
1 5 6 7 1000

Sample Output 1

2
1

Note

For the first test case → remove 1.

For the second test case → remove 1 and 1000.




*/

#include <bits/stdc++.h>
using namespace std;
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int testcases;
   cin>>testcases;
   while(testcases--){
       int n,k;
       cin>>n>>k;
       int arr[n];
       int diff[n-1];
       for(int i=0;i<n;i++)
           cin>>arr[i];
       for(int i=1;i<n;i++)
           diff[i-1] = arr[i]-arr[i-1];
       int ans = 2e9;
       int window = n-k-1;
       deque < int > q;
       for(int i=0;i<n-1;i++){
           while(!q.empty() and i-q.front()+1>window)
               q.pop_front();
           while(!q.empty() and diff[i]>=diff[q.back()])
               q.pop_back();
           q.push_back(i);
           if(i>=window-1)
               ans = min(ans,diff[q.front()]);
       }
       cout<<ans<<"\n";
   }
}
