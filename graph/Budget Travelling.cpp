// https://www.learning.algozenith.com/problems/Budget-Travelling-593

/*

Description

You want to visit the country of wonderland. There are N cities in the country. Not all cities are connected by roads. You know which cities are connected. 

You landed in city A, and you want to visit city B. You already booked your car, but it doesn’t have any petrol. The capacity of the tank of the car is C. You know the Per Liter cost of petrol in each city, and you also have the map of the country, i.e., you know the length of road between two cities. To travel one unit of distance, you need one liter of petrol.

Find the minimum cost to travel from city A to city B.


Input Format

The first line of input contains N - the number of cities in the country of wonderland.
The second line contains M - the number of roads in the country.
Next M lines contain three integers u, v, d - there is a road between city u and v of length d.
The next lines contain N space-separated integers P[1], P[2], …., P[N] - P[i] is the per liter cost of petrol in the city i.
The last line of input contains A, B, and C - the starting city, the destination city, and the capacity of the tank of car you booked.
It’s guaranteed that it’s always possible to reach city B from A.


Output Format

Print the minimum cost to reach city B on a new line.


Constraints

1 ≤ N ≤ 10000
1 ≤ M ≤ 100000
1 ≤ C ≤ 100
1 ≤ u, v ≤ N
1 ≤ d ≤ C
1 ≤ A, B ≤ N
1 ≤ P[i] ≤ 100
 


Sample Input 1

5
5
1 2 1
2 3 1
3 4 1
4 5 1
1 4 6
1 10 10 10 1
1 5 8

Sample Output 1

4

Sample Input 2

6
6
1 2 1
2 3 1
3 4 1
4 5 1
1 6 1
6 5 5
10 10 10 10 1 1
1 5 8

Sample Output 2

15

Note

Explanation 1:

Fill petrol of 4 liters in city 1, and travel via path 1 → 2 → 3 → 4 → 5.

Explanation 2:

Fill 1 liter of petrol in city 1 of cost 10, travel to city 6. Fill 5 liters of petrol at city 6 of cost 5 x 1 = 5. Travel to city 5. Total cost = 10 + 5 = 15. The path took 1 → 6 → 5.

*/



#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define MP make_pair
using ii = pair<int, int>;

int n, m, C;
vector<ii> g[10010];
int P[10010];

int dist[10001][101];
int vis[10001][101];

int dijk(int st, int en)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= C; j++)
        {
            dist[i][j] = 1e9;
            vis[i][j] = 0;
        }
    }

    priority_queue<pair<int, ii>> pq;
    
    pq.push(MP(0, MP(st, 0)));
    dist[st][0] = 0;
    
    while (!pq.empty())
    {
        pair<int, ii> cur = pq.top();
        pq.pop();
        
        int node = cur.S.F;
        int fuel = cur.S.S;
        int dis = -cur.F;

        if (vis[node][fuel] == 1)
            continue;
        
        vis[node][fuel] = 1;

        if (fuel < C && dis + P[node] < dist[node][fuel + 1])
        {
            dist[node][fuel + 1] = dis + P[node];
            pq.push(MP(-dist[node][fuel + 1], MP(node, fuel + 1)));
        }
        
        for (auto v : g[node])
        {
            if (fuel >= v.S && dist[v.F][fuel - v.S] > dis)
            {
                dist[v.F][fuel - v.S] = dis;
                pq.push(MP(-dist[v.F][fuel - v.S], MP(v.F, fuel - v.S)));
            }
        }
    }
    
    int mini = 1e9;
    
    for (int i = 0; i <= C; i++)
    {
        mini = min(mini, dist[en][i]);
    }

    assert(mini < 1e9);
    
    return mini;
}

void solve()
{

    cin >> n;
    cin >> m;
    
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        
        cin >> u >> v >> w;
        
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    
    for (int i = 1; i <= n; i++)
    {
        cin >> P[i];
    }
    
    int st, en;
    
    cin >> st >> en >> C;

    cout << dijk(st, en) << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //int _t;cin>>_t;while(_t--)
    solve();
}
