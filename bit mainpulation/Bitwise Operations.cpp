// https://www.learning.algozenith.com/problems/Bitwise-Operations-50

/*

Description

Given an array of N positive integers. You can perform this operation any number of times, choose two indices x and y. If array[x] = a and array[y] = b, then after the operation

1. array[x] = a OR b, array[y] = a AND b.

Perform the operations optimally such that ∑array[i]*array[i] for all 1<=i<=n is maximum. Print the largest sum of squares you can get after performing the operations greater than equal to zero times.


Input Format

The first line of the input contains a single integer T denoting the number of test cases, (1<=T<=100).

The first line of each test case contains a single integer N, (2<=N<=100000).

The second line contains N space-separated integers A1,A2,…,AN, (1<=Ai<=10^6).

Sum of N over all test cases does not exceed 10^6.


Output Format

For each test case output a single integer representing the largest possible sum of squares that can be achieved after several (possibly zero) operations.


Sample Input 1

5
2
2 5
3
1 2 3
5
1 2 3 4 5
1
1234
10
2 5 234 3454 3423 34545 65433 654345 9876 76567

Sample Output 1

49
18
99
1522756
448865876262

*/


//One of the another approach in which I am simulating the whole process.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

   int testcases;
   cin>>testcases;
   while(testcases--){

       vector < ll > bit[20];
       ll n;
       cin>>n;
       vector < ll > arr(n);
       for(int i=0;i<n;i++)cin>>arr[i];
       vector < ll > done(n+1,0);
       for(int i=0;i<n;i++){
           for(int j=0;j<20;j++){
               if(arr[i]&(1<<j))
                   bit[j].push_back(i);  // push in bit[i] all the index which have ith bit on.
           }
       }
       ll k = 19;  
       while(k>=0){   // Greedily increasing the value of every number, starting from the most significant digit
           if(bit[k].size()){
               ll x = bit[k][bit[k].size()-1]; // taking a element which may or may not have the kth bit set as it might be changed.
               bit[k].pop_back();
               if(done[x] or !((1<<k)&arr[x])) // if it is already done or bit is not set then continue
                   continue;
               done[x] = 1;  // trying to increase the value as much as I can using the lower bits.
               for(int i = 0;i<k+1;i++){
                   if(arr[x]&(1<<i)) // it bit is already set then continue
                       continue;
                   while(bit[i].size()){  // find a index which has this bet set, then apply the operation to increase the value of x.
                       ll y = bit[i][bit[i].size()-1];
                       bit[i].pop_back();
                       if(done[y] or !((1<<i)&arr[y]))
                           continue;

                       ll temp = arr[y];
                       arr[y] = arr[y]&arr[x];  // because of this operation the set bit of arr[y] can be unset.
                       arr[x]|=temp;
                       break;
                   }
               }
           }
           else
               k--;

       }
       ll ans=0;
       for(int i=0;i<n;i++)ans+=arr[i]*arr[i];
       cout<<ans<<"\n";
   }
}
