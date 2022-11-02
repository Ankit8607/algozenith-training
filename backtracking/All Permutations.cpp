// https://www.learning.algozenith.com/problems/All-Permutations-455

/*

Description

Given an array of numbers, that might contain duplicates, print all possible unique permutations in lexicographically increasing order.


Input Format

The first line of input contains n - the size of the array.
The second line contains n space-separated integers denoting the elements of the array - a1, a2, …, an.


Output Format

Print all permutations in lexicographically increasing order. See the sample output for more clarity.


Constraints

1 ≤ n ≤ 8
0 ≤ ai ≤ 109


Sample Input 1

3
1 1 1

Sample Output 1

1 1 1

Sample Input 2

3
1 2 1

Sample Output 2

1 1 2
1 2 1
2 1 1

Sample Input 3

3
2 1 3

Sample Output 3

1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

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
vector<int>ans;
map<int,int>mp;
int n;
void rec(int level){
    if(level==n){
        for(auto i:ans) cout<<i<<" ";
        cout<<endl;
        return;
    }
    for(auto i:mp){
        if(i.second!=0){
            mp[i.first]--;
            ans.push_back(i.first);
            rec(level+1);
            ans.pop_back();
            mp[i.first]++;
        }
    }
}
int freq[1001000];
void solve(){
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }
    rec(0);
}

signed main(){
    IOS
    int t=1;
    // cin>>t;
    // fac();
    while(t--) solve();
    return 0;
}
