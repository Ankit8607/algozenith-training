// https://www.learning.algozenith.com/problems/Subarrays-with-xor-less-than-k-393

/*

Description

Given an array of positive integers you have to print the number of subarrays whose XOR is less than K. Subarrays are defined as a sequence of continuous elements Ai, Ai+1, ..., Aj . XOR of a subarray is defined as Ai ^ Ai+1 ^ ... ^ Aj. 


Input Format

The first line contains an integer T ( 1 ≤ T ≤ 10), the number of test cases.

The first line of each test case contains 2 space-separated integers N,k 1 ≤ N ≤ 10^5, 1 ≤ k ≤ 10^6.

The second line of each test case contains N space-separated integers, 1≤ Ai ≤ 10^5


Output Format

For each test case print the number of subarray with XOR less than k in a new line.


Sample Input 1

2
5 3
1 2 3 4 5
10 472156
645 45 8 6 45564 46868 89797 4566 65546 65467

Sample Output 1

8
55

*/


#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

struct node{
    node *child[2]={0};
    int cnt=0;
};

void insert(int x, node *root){
    node *cur=root;
    for(int i=31;i>=0;i--){
        int bit=(x>>i)&1;
        if(cur->child[bit]==NULL) cur->child[bit]=new node;
        cur=cur->child[bit];
        cur->cnt++;
    }
}

int k;
int fmax(int a, node * root){
    node *cur=root;
    int ans=0;
    for(int i=31;i>=0;i--){
        if(cur==NULL) break;
        int abit=(a>>i)&1;
		int kbit=(k>>i)&1;
        if(kbit==0 and abit){
                cur=cur->child[1];
        }
        else if(kbit and abit){
            if(cur->child[1])
                ans+=cur->child[1]->cnt;
            cur=cur->child[0];
        }
        else if(!kbit and !abit){
            cur=cur->child[0];
        }
        else{
            if(cur->child[0])
                ans+=cur->child[0]->cnt;
            cur=cur->child[1];
        }
    }
    return ans;
}
void solve(){
    int n; cin>>n>>k;
    node *root = new node;
    insert(0,root);
    int pre=0,ans=0;
    for(int i=0;i<n;i++){
        int a; cin>>a;
        pre^=a;
        ans+=fmax(pre,root);
        insert(pre,root);
    }
    cout<<ans<<endl;
}

signed main()
{
    #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
}
