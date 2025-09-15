#include <iostream>
#include <vector>
#include <queue>
#include <ctime>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<int> visited(V, 0);

    // { wt, node }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 0});

    int sum = 0;

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        int wt = it.first;
        int node = it.second;

        if (visited[node])
            continue;

        visited[node] = 1;
        sum += wt;

        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edW = it[1];

            if (!visited[adjNode])
                pq.push({edW, adjNode});
        }
    }

    return sum;
}

int main()
{
    srand(time(0));

    vector<int> sizes = {1000, 10000, 20000, 30000, 40000, 50000, 100000};

    for (int V : sizes)
    {
        vector<vector<int>> *adj = new vector<vector<int>>[V];

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
        int mstWeight = spanningTree(V, adj);
        clock_t end = clock();

        double time_taken = double(end - start) / CLOCKS_PER_SEC;

        cout << V << "\t" << time_taken << " sec" << endl;

        delete[] adj;
    }

    return 0;
}