// https://www.learning.algozenith.com/problems/Shortest-Subarray-55

/*

Description

Given an array of N integers, find the length of the smallest sub-array that contains all the distinct elements of the array.


Input Format

The first line contains T, the number of test cases (1<=T<=10).

The first line contains an integer N, 1<=N<=10^5.

Next line contains N space-separated integers (0<=Ai<=1e5).

 


Output Format

For each test case print length of the smallest sub-array that contains all the distinct elements of array in a newline.


Sample Input 1

6
5
1 1 3 2 3
5
1 2 3 4 5
6
1 2 2 3 3 4
6
1 2 1 3 2 4
5
1 1 1 1 1
1
1

Sample Output 1

3
5
6
4
1
1
 


Note

For first test case → smallest subarray -> (1,3,2).

For second test case → smallest subarray -> (1,2,3,4,5).

For third test case → smallest subarray -> (1 2 2 3 3 4).

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
int freq[100100];
void solve(){
    int n,d; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        freq[arr[i]]=0;
    }

    int head=-1, tail=0, cnt=0,cnts=0,ans=0;
    while(head+1<n){
        head++;
        // cout<<head<<" ";
        freq[arr[head]]++;
        if(freq[arr[head]]==1) cnt++;
        while(freq[arr[tail]]>1){
            freq[arr[tail]]--;
            tail++;
        }
        if(cnt==cnts){
            ans=min(ans,head-tail+1);
        }
        else if(cnt>cnts){
            ans=head-tail+1;
            cnts=cnt;
        }
        // cout<<ans<<" "<<endl;
        // cout<<"head= "<<head<<" tail= "<<tail<<endl;
    }
    cout<<ans<<endl;
    // while(tail<n){
    //     while(head+1<n&&(cnt<k || freq[arr[head+1]]>0)){
    //         head++;
    //         freq[arr[head]]++;
    //         if(freq[arr[head]]==1) cnt++;
    //     }
    //     ans+=(head-tail+1);
    //     if(tail<=head){
    //         freq[arr[tail]]--;
    //         if(freq[arr[tail]]==0) cnt--;
    //         tail++;
    //     }
    //     else{
    //         tail++;
    //         head=tail-1;
    //     }
    // }
}

signed main(){
    IOS
    int t=1;
    cin>>t;
    // fac();
    while(t--) solve();
    return 0;
}
