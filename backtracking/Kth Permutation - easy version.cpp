// https://www.learning.algozenith.com/problems/Kth-Permutation---easy-version-456

/*

Description

For the given n, consider the array A = {1, 2, …, n}. There exist n! unique permutations of the array. When we list all these n! permutations in lexicographically order, your task is to find kth permutation in that list.


Input Format

The first line contains two space-separated integers n and k.


Output Format

Print n space-separated integers, denoting the kth permutation.


Constraints

1 ≤ n ≤ 9
1 ≤ k ≤ n!


Sample Input 1

3 4

Sample Output 1

2 3 1

Sample Input 2

4 9

Sample Output 2

2 3 1 4

Note

Explanation 1: All 9 permutations in lexicographic order are

1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
The 4th one is {2, 3, 1}.

*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int mod= 1000000007;
const int N=100100;
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int power(int a, int b){
    int ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;     
}
int fact[N];
void fac(int n){
    fact[0]=1;
    for(int i=1;i<=n;i++) 
        fact[i]=(i*fact[i-1])%mod;
}
vector<int>v;
map<int,int>mp;
int ans=0;
char store[8][8];
bool check(int row,int col){
    if(store[row][col]=='*') return 0;
    if(store[row][col]=='.'){
        for(int prow=0;prow<row;prow++){
            int pcol=v[prow];
            if(pcol==col||(abs(pcol-col)==abs(prow-row)))
                return 0;
        }
    }
    return 1;
}
void rec(int level){
    if(level==8){
        ans++;
        return;
    }
    for(int col=0;col<8;col++){
        if(check(level,col)){
            v.push_back(col);
            rec(level+1);
            v.pop_back();
        }
    }
}
int freq[1001000];
void solve(){
    int n,k; cin>>n>>k;
    int a[n];
    for(int i=1;i<=n;i++) a[i-1]=i;
    k--;
    while(k--) next_permutation(a,a+n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}

signed main(){
    IOS
    int t=1;
    // cin>>t;
    // fac();
    while(t--) solve();
    return 0;
}
