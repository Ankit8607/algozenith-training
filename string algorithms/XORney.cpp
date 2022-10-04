// https://www.learning.algozenith.com/problems/XORney-416

/*

Description

Given are two sequences a={a0,…,aN−1} and b={b0,…,bN−1} of N non-negative integers each.

You will choose an integer k such that 0≤k<N and an integer x not less than 0, to make a new sequence of length N, a′={a′0,…,a′N−1}, as follows:

a′i=a(i+k)modN XOR x
Find all pairs (k,x) such that a′ will be equal to b.


Input Format

First line contains an integer N, 1 ≤ N ≤ 2*10^5.

Second line contains N space-separated integers,  0≤ ai < 2^30.

Third line contains N space-separated integers,  0≤ bi < 2^30.


Output Format

Print all pairs (k,x) such that a′ and b will be equal, using one line for each pair, in ascending order of k (ascending order of x for pairs with the same k).

If there are no such pairs, the output should be empty.


Constraints

1 ≤ N  ≤ 2*10^5.
0 ≤ ai < 2^30.
0 ≤ bi < 2^30.

Sample Input 1

5
1 4 2 3 0
6 7 4 5 0

Sample Output 1

2 4

Sample Input 2

6
0 1 3 7 6 4
1 5 4 6 2 3

Sample Output 2

2 2
5 5

Sample Input 3

2
1 2
0 0

Note

For Sample 1,

The array a = 1 4 2 3 0

The array b = 6 7 4 5 0

Convert a such that , a′i=a(i+2)mod5 ^ 4

The converted array : (2 3 0 1 4)

Taking xor with 4 , the array finally becomes :- 6 7 4 5 0

This is the same as array b. Hence only one pair is obtained.

*/

# include <bits/stdc++.h>
#include <string>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using lli =  int long long;
using ii = pair<int,int>;
#define F first
#define S second
//#define ld long double;

const int tot = 1e6+100;
const lli mod = 1e9+7;
int n;

vector<lli> Z;

//Code for Z algo
void Zalgo(vector<lli> &s){

  int n = s.size();
  Z.assign(n,0);

  int l = 0, r = 0;
  for (int i = 1; i < n; i++){

    if (i > r){

      l = r = i;
      while (r<n && s[r-l] == s[r]){
        r++;
      }
      Z[i] = r-l; 
      r--;
    } 
    else{
      int k = i-l;
      if (Z[k] < r-i+1){
        Z[i] = Z[k];
      } 
      else{
        l = i;
        while (r < n && s[r-l] == s[r]){
          r++;
        }
        Z[i] = r-l; 
        r--;
      }
    }
  }

}

int main(){
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    IOS

    cin >> n;
    vector<lli> a(n);
    vector<lli> b(n);

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    for(int i=0;i<n;i++){
        cin >> b[i];
    }

    vector<lli> c(n,0); //stores adjacent xor of a
    vector<lli> d(n,0); //stores adjacent xor of b

    for(int i=0;i<n;i++){
        c[i] = a[i]^a[(i+1)%n]; 
    }

    for(int i=0;i<n;i++){
        d[i] = b[i]^b[(i+1)%n]; 
    }

    // form the string S = (d)+(-1)+(c)+(c)
    vector<lli> s;
    s.insert(s.end(),d.begin(),d.end());
    s.push_back(-1);
    s.insert(s.end(),c.begin(),c.end());
    s.insert(s.end(),c.begin(),c.end());


    Zalgo(s);

    lli x;

    //find the values of k and x.
    for(int k=0;k<n;k++){
      if(Z[k+n+1]==n){
        x = b[0]^a[k];
        cout << k << " " << x << "\n";
      }
    }

    return 0;
}
