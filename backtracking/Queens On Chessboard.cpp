// https://www.learning.algozenith.com/problems/Queens-On-Chessboard-254

/*

Description

Your task is to place eight queens on a chessboard so that no two queens are attacking each other. As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares. However, the reserved squares do not prevent queens from attacking each other.

How many possible ways are there to place the queens?


Input Format

The input has eight lines, and each of them has eight characters. Each square is either free (.) or reserved (*).


Output Format

Print one integer: the number of ways you can place the queens.


Sample Input 1

........
........
..*.....
........
........
.....**.
...*....
........

Sample Output 1

65

*/


#include<bits/stdc++.h>
using namespace std;
const int mod= 10000007;
#define endl "\n"
#define F first
#define S second
#define vi vector<int>
#define ii pair<int,int>
#define all(a) a.begin(),a.end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define tracearray(arr,n)  cout<<#arr<<endl;for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;

bool check(int i,int j,vector<int>&q){
    for(int row=0;row<q.size();row++){
        int col=q[row];
        if(abs(col-j)==abs(row-i) || col==j) return 0;
    }
    return 1;
}

int rec(int i,char arr[][8],vector<int>&q){
    if(i==8) return 1;

    int ans=0;
    for(int j=0;j<8;j++){
        if(arr[i][j]=='.' and check(i,j,q)){
            q.push_back(j);
            ans+=rec(i+1,arr,q);
            q.pop_back();
        }
    }

    return ans;
}

void solve(){
    char arr[8][8];
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++) 
            cin>>arr[i][j];
    vector<int>q;
    cout<<rec(0,arr,q)<<endl;
}

signed main(){
    IOS
    // int t=1; cin>>t; while(t--) 
    solve();
    return 0;
}
