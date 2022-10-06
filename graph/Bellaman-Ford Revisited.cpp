// https://www.learning.algozenith.com/problems/Bellaman-Ford-Revisited-194

/*

Description

You have given a graph G with n nodes and m edges. Each edge has an integer weight associated with. The weight of an edge may negative, positive or zero. If the graph contains a cycle with total weight > 0, print -1. Otherwise, find the weight of the highest weighted path from node 1 to n.


Input Format

The first input line has two integers n and m: the number of nodes and edges. The nodes are numbered 1, 2, …, n.
Then, there are m lines describing the edges. Each line has three integers a, b and x: the edge starts at node a, ends at node b, and weight of the edge is x. All edges are unidirectional edges.
You can assume that it is possible to get from node 1 to node n.


Output Format

Print the answer on a new line.


Constraints

1 ≤ 2500 ≤ n
1 ≤ 5000 ≤ m
1 ≤ a, b ≤ n
−109 ≤ x ≤ 109


Sample Input 1

4 5
1 2 3
2 4 -1
1 3 -2
3 4 7
1 4 4

Sample Output 1

5

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int mod = 1e9 + 7;

const int N = 100010;

struct edge {
	int u, v, w;
};

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	edge E[m];
	for(int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		E[i].u = a;
		E[i].v = b;
		E[i].w = -c;
	}

	ll dist[n + 1];
	for(int i = 1; i <= n; i++) {
		dist[i] = 1e18;
	}
	dist[1] = 0;

	for(int i = 1; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int u = E[j].u;
			int v = E[j].v;
			int w = E[j].w;
			dist[v] = min(dist[v], dist[u] + w);
		}
	}

	bool neg = false;
	for(int i = 0; i < m; i++) {
		int u = E[i].u;
		int v = E[i].v;
		int w = E[i].w;
		if(dist[v] > dist[u] + w) {
			neg = true;
			break;
		}
	}

	if(neg) cout << "-1\n";
	else {
		assert(dist[n] != 1e18);
		cout << -dist[n] << "\n";
	}
}
