#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <queue>
#include <climits>
using namespace std;

// TC: O(E.log(V))
// SC: O(V + E) = O(V + V^2) = O(V^2) // E = V^2
vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
{
    int V = adj.size();
    vector<int> dist(V, INT_MAX);

    // min heap of (dist, node) pairs
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            int wt = it.second;
            int nei = it.first;

            if (dis + wt < dist[nei])
            {
                dist[nei] = dis + wt;
                pq.push({dist[nei], nei});
            }
        }
    }

    return dist;
}

int main()
{
    srand(time(0));

    vector<int> sizes = {1000, 10000, 20000, 30000, 40000, 50000, 100000};

    for (int V : sizes)
    {
        vector<vector<pair<int, int>>> adj(V);

        for (int i = 0; i < V - 1; i++)
        {
            int w = rand() % 100 + 1;
            adj[i].push_back({i + 1, w});
            adj[i + 1].push_back({i, w});
        }

        for (int i = 0; i < V; i++)
        {
            int u = rand() % V;
            int v = rand() % V;
            if (u != v)
            {
                int w = rand() % 100 + 1;
                adj[u].push_back({v, w});
                adj[v].push_back({u, w});
            }
        }

        clock_t start = clock();
        dijkstra(adj, 0);
        clock_t end = clock();

        double time_taken = double(end - start) / CLOCKS_PER_SEC;

        cout << V << "\t" << time_taken << " sec" << endl;
    }

    return 0;
}