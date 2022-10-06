// https://www.learning.algozenith.com/problems/Burn-them-All-596

/*

Description

You have given an undirected graph of N vertices and M edges. Edge weight d on edge between nodes u and v represents that u and v are connected by a thread of length d units. 
You set node A on to the fire. It takes to fire 1 unit of time to travel 1 unit of distance via threads.
Let T be the minimum time in which all the threads will be burned out. 

Your task is to find 10T. We can prove that 10T will always be an integer number.

See the sample test cases for more explanation.


Input Format

The first line of input contains N - the number of nodes in the graph.
The second line contains M - the number of edges in the graph.
Next M lines contain three integers u, v, d - there is a thread between node u and v of length d.
The last line of input contains A - the node on which we set fire.

It’s guaranteed that graph is connected.


Output Format

Print the value of 10T.


Constraints

1 ≤ N ≤ 2 x 105
1 ≤ M ≤ 2 x 105
1 ≤ u, v ≤ N
1 ≤ d ≤ 109


Sample Input 1

2
1
1 2 2
1

Sample Output 1

20

Sample Input 2

3
3
1 2 2
2 3 2
1 3 6
1

Sample Output 2

50

Sample Input 3

3
3
1 2 2
1 3 2
2 3 1
1

Sample Output 3

25

Note

Explanation 1:

At t = 0, node 1 is at fire.
At t = 1, thread 1-2 is half burned.
At t = 2, thread 1-2 is fully burned.
So T = 2. And 10T = 20.

Explanation 2:

At t = 0, node 1 is at fire.
At t = 2, thread 1-2 is fully burned, and thread 1-3 is 1/3rd burned.
At t = 4, threads 1-2 and 2-3 are fully burned, and 4 units of thread 1-3 are burned. For the remaining 2 units of thread 1-3, fire is approaching from both ends.
At t = 5, all threads are fully burned.
So T = 5. And 10T = 50.

Explanation 3:

At t = 0, node 1 is starting to burn.
At t = 2, threads 1-2 and 1-3 are fully burned. Now for thread 2-3, fire is approaching from both ends at equal speed.
At t = 2.5, thread 2-3 is fully burned.
So T = 2.5. And 10T = 25.

*/


#include <bits/stdc++.h>
using namespace std;

#define ll long long int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<pair<int, ll>> graph[n + 1];
    vector<pair<pair<int, int>, ll>> edges;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll d;
        cin >> u >> v >> d;
        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
        edges.push_back({{u, v}, d});
    }

    int st;
    cin >> st;

    ll dist[n + 1];

    for (int i = 1; i <= n; i++)
    {
        dist[i] = 1e18;
    }

    priority_queue<pair<ll, int>> q;

    q.push({0, st});
    dist[st] = 0;

    bool visited[n + 1];
    memset(visited, false, sizeof(visited));

    while (!q.empty())
    {
        auto it = q.top();
        q.pop();

        ll w = -it.first;
        int u = it.second;

        if (visited[u])
            continue;

        visited[u] = true;

        for (auto it : graph[u])
        {
            int v = it.first;
            ll d = it.second;

            if (dist[v] > w + d)
            {
                dist[v] = w + d;
                q.push({-dist[v], v});
            }
        }
    }

    ll ans = -1e18;

    for (int i = 1; i <= n; i++)
        assert(visited[i]);

    for (auto it : edges)
    {
        int u = it.first.first;
        int v = it.first.second;
        ll d = it.second;

        ans = max(ans, (dist[u] + dist[v] + d) * 5);
    }

    assert(ans > 0);

    cout << ans << "\n";
}
