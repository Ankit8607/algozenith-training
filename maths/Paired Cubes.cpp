// https://www.learning.algozenith.com/problems/Paired-Cubes-211

/*

Description

You have given n positive integers A1, A2, …, An. Your task is to find the number of pairs (i, j) such that Ai * Aj is a cube number.


Input Format

The first line of input contains n - the size of the array.
The second line of input contains n space-separated integers A1, A2, …, An.


Output Format

Print the answer on a new line.


Constraints

1 ≤ n ≤ 105
1 ≤ Ai ≤ 106


Sample Input 1

5
1 2 4 8 27

Sample Output 1

4

Note

The pairs are (1, 8), (2, 4), (1, 27), (8, 27).

*/


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

   int n; cin >> n;

   map <ll,int> M;

   ll ans = 0;

   for(int i = 0; i < n; i++) {
      int x; cin >> x;
      ll norm = 1;
      ll tar = 1;
      for(int j = 2; j * j <= x; j++) {
         int cnt = 0;
         while(x % j == 0) {
            x /= j;
            cnt++;
         }
         cnt %= 3;
         for(int k = 0; k < cnt; k++) {
            norm *= j;
         }
         if(cnt) {
            for(int k = 0; k < 3 - cnt; k++) {
               tar *= j;
            }
         }
      }
      if(x > 1) {
         norm *= x;
         tar *= (x * x);
      }
      ans += M[tar];
      M[norm]++;
   }

   cout << ans << "\n";
}
