// https://www.learning.algozenith.com/problems/XOR-and-AND-48

/*

Description

Given an array of N integers, find the sum of XOR of all pairs of numbers in the array, sum of XOR of all subset of numbers in the array, sum of AND of all pairs of numbers in the array, sum of AND of all subset of numbers in the array. Calculate it %1000000007. 
For pair you should select two index i, j such that i<j.


Input Format

The first line of the input contains a single integer T denoting the number of test cases, (1<=T<=100).

The first line of each test case contains a single integer N, (2<=N<=100000).

The second line contains N space-separated integers A1,A2,…,AN, (1<=Ai<=10^9).

Sum of N over all test cases does not exceed 10^6.


Output Format

For each test case output, 4 space-separated integers in a new line in the order the sum of XOR of all pairs of numbers in the array, sum of XOR of all subset of numbers in the array, sum of AND of all pairs of numbers in the array, sum of AND of all subset of numbers in the array. Since these numbers may be very large, compute them modulo 1000000007 (10^9+7)


Sample Input 1

6
5
1 2 3 4 5
5
1 1 2 3 5
3
1 2 3
4
1 2 2 4
10
989098 987656790 989098765 234543 3456543 234567543 1234567 5678 56789 8909876
10
123 1234543 2345 6776 8787 8765467 234567 98765444 1234 4561

Sample Output 1

42 112 9 25
32 112 8 25
6 12 3 9
23 56 2 11
378768679 755809533 328561458 769714220
962949537 271171227 9132543 118419489

Note

1st test case: all pairs and corresponding XOR and AND value:
(1,2) - 3, 0
(1,3) - 2, 1
(1,4) - 5, 0
(1,5) - 4, 1
(2,3) - 1, 2
(2,4) - 6, 0
(2,5) - 7, 0
(3,4) - 7, 0
(3,5) - 6, 1
(4,5) - 1, 4
Sum of XOR of all pairs = 42, Sum of AND of all pairs = 9

3rd test case: all subset XOR and AND values:
(1) - 1, 1
(1,2) - 3, 0
(1,3) - 2, 1
(2,3) - 1, 2
(2) - 2, 2
(3) - 3, 3
(1,2,3) - 0, 0
Sum of XOR of all subset =  12, Sum of AND of all subset = 9

*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
const ll N = 100001;
const ll BITS = 31;

ll addMod(ll a,ll b){
   a = a+b;
   if(a>=mod)
       a-=mod;
   return a;
}
ll nc2(ll x){
   return ((x*(x-1))/2)%mod;
}
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   ll powerOfTwo[N];
   powerOfTwo[0] = 1;
   for(ll i=1;i<N;i++){
       powerOfTwo[i] = addMod(powerOfTwo[i-1],powerOfTwo[i-1]);
   }

   ll testCase;
   cin>>testCase;
   while(testCase--){
       ll n;
       cin>>n;
       ll arr[n];
       for(ll i=0;i<n;i++)
           cin>>arr[i];

       ll sumPairXor = 0;
       ll sumSubsetXor = 0;
       ll sumPairAnd = 0;
       ll sumSubsetAnd = 0;

       for(ll i=0;i<BITS;i++){
           ll cnt = 0;
           for(ll j=0;j<n;j++){
               if(arr[j]&(1LL<<i))  
                   cnt++;
           }

           sumPairXor = addMod(sumPairXor , (1LL<<i)*cnt%mod*(n-cnt)%mod);
           if(cnt)
               sumSubsetXor = addMod(sumSubsetXor, (1LL<<i)*powerOfTwo[n-1]%mod);

           sumPairAnd = addMod(sumPairAnd, (1LL<<i)*nc2(cnt)%mod);
           sumSubsetAnd = addMod(sumSubsetAnd, (1LL<<i)*(powerOfTwo[cnt]-1+mod)%mod);

       }
       cout<<sumPairXor<<" "<<sumSubsetXor<<" "<<sumPairAnd<<" "<<sumSubsetAnd<<"\n";
   }

}
