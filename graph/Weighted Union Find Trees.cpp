// https://www.learning.algozenith.com/problems/Weighted-Union-Find-Trees-41

/*

Description

There is a sequence A = a0, a1, ..., an-1. You are given the following information and questions.

relate(x, y, z): ay is greater than ax by z.
diff(x, y): report the difference between ax and ay i.e. ay - ax.

Input Format

The first line contains two space-separated integers n and q, (1 ≤ n ≤ 104, 1 ≤ q ≤ 2 x 105).
Then, q queries are given in the form either 0 x y z or 1 x y (0 ≤ x, y < n, x != y, 0 ≤ z ≤ 10000). '0' denotes the relate information and '1' denotes diff question.
It is guaranteed that there is no inconsistency in the given information.


Output Format

For each diff question, print the difference between ax and ay i.e. ay - ax. If we don't have any information for the current diff query, print '?'.


Sample Input 1

5 6
0 0 2 5
0 1 2 3
1 0 1
1 1 3
0 1 4 8
1 0 4
 


Sample Output 1

2
?
10
 


Note

Query 1: a2 - a0 = 5
Query 2: a2 - a1 = 3
Query 3: We can find the difference between a1 and a0 as a1 - a0 = 2
Query 4: We don't have any information about a3. That's why we print '?'
Query 5: a4 - a1 = 8
Query 6: We can find the difference between a4 and a0 as a4 - a0 = 10

*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int mod= 1000000007;
const int N=100100;
#define endl "\n"
#define F first
#define S second
#define MP make_pair
#define ii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n,m;

int parent[N],diff[N];
ii find(int x){
    if(parent[x]==x){ 
        return {x,0};
    }
    else{
        ii temp=find(parent[x]);
        parent[x]=temp.F;
        diff[x]+=temp.S;
        return {parent[x],diff[x]};
    }
}

void merge(int x, int y, int dist){
    ii xroot=find(x);
    ii yroot=find(y);
    if(parent[xroot.F]==parent[yroot.F]) return;
    diff[yroot.F]=xroot.S+dist-yroot.S;
    parent[yroot.F]=xroot.F;
}

void print(int x, int y){
    ii xroot=find(x);
    ii yroot=find(y);
    if(xroot.F!=yroot.F) cout<<"?"<<endl;
    else cout<<yroot.S-xroot.S<<endl;
}

void solve(){
    int q;
    cin>>n>>q;
    for(int i=0;i<=n;i++){
        diff[i]=0;
        parent[i]=i;
    }
    for(int i=0;i<q;i++){
        int ch,a,b,c;
        cin>>ch;
        if(ch==0){
            cin>>a>>b>>c;
            merge(a,b,c);
        }
        else{
            cin>>a>>b;
            print(a,b);
        }
    }
}

signed main(){
    IOS
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}
