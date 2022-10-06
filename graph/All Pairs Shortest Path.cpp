// https://www.learning.algozenith.com/problems/All-Pairs-Shortest-Path-405

/*

Description

We have given an adjacency representation of a directed weighted graph and an array of vertices. At each iteration, a vertex is removed from the graph. Vertices are removed in the order given in the array. When the vertex is removed, all the edges that go in and out are also removed. 

Print the sum of all pairs shortest path just before each iteration.


Input Format

The first line contains integer n (1 ≤ n ≤ 500) — the number of vertices in the graph.
Next n lines contain n integers each — the graph adjacency matrix: the j-th number in the i-th line aij (1 ≤ aij ≤ 105, aii = 0) represents the weight of the edge that goes from vertex i to vertex j.
The next line contains n distinct integers: x1, x2, ..., xn (1 ≤ xi ≤ n) — the order of vertices removed from the graph.


Output Format

Print N space-separated numbers, where ith number represents the sum of all pairs shortest path just before ith removal.


Constraints

1 ≤ N ≤ 500


Sample Input 1

2
0 5
4 0
1 2

Sample Output 1

9 0

Sample Input 2

4
0 3 1 1
6 0 400 1
2 4 0 1
1 1 1 0
4 1 2 3

Sample Output 2

17 23 404 0 

*/


#include<bits/stdc++.h>
#define ll long long int
#define N 510
using namespace std;

ll inf=1e16;
int main()
{
    int n;
    ll A[N][N]; // the adjecency matrix
    scanf("%d",&n); // take n.
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%lld",&A[i][j]); // we take the graph in a 0 indexed manner.
    vector<ll> ans; // the final answer array.
    int x[N]; // the order of elements removed.
    for(int i=0;i<n;i++) scanf("%d",&x[i]),x[i]--;// take input, -- for 0 index
    for(int i=n-1;i>=0;i--) // move from backward [x[i],x[i+1]...x[n-1]] are the active edges.
    {
        for(int j=0;j<n;j++) 
            for(int k=0;k<n;k++) 
                A[j][k]=min(A[j][k],A[j][x[i]]+A[x[i]][k]); // relax the current node (Floyd washall)

        // After the ith iteration. The matrix has relaxed nodes x[i],x[i+1]...x[n-1].
        // So we these are the active nodes, and Floyd warshall ensures all those have correct shortest paths.
        ll temp=0;
        for(int j=i;j<n;j++) 
            for(int k=i;k<n;k++)
                temp+=A[x[j]][x[k]]; // get the all pair distnce for all active nodes.
        ans.push_back(temp); // add it to the ans.
    }
    for(int i=(int)ans.size()-1;i>=0;i--) printf("%lld ",ans[i]); // print in reverse order as we added instead of remove.
    return 0;
}
