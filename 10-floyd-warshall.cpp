#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <climits>
using namespace std;

void shortestDistance(vector<vector<int>> &mat)
{
    int n = mat.size();

    // Replace -1 with a large number, and set diagonal to 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == -1)
                mat[i][j] = 1e9;
            if (i == j)
                mat[i][j] = 0;
        }
    }

    // Floyd–Warshall Algorithm
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][k] < 1e9 && mat[k][j] < 1e9)
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }

    // Convert unreachable back to -1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1e9)
                mat[i][j] = -1;
        }
    }
}

int main()
{
    srand(time(0));

    vector<int> sizes = {100, 200, 300, 400, 500};

    for (int V : sizes)
    {
        vector<vector<int>> adj(V, vector<int>(V, -1));

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (i != j && (rand() % 100) < 10)
                {
                    int w = rand() % 100 + 1;
                    adj[i][j] = w;
                }
            }
        }

        clock_t start = clock();
        shortestDistance(adj);
        clock_t end = clock();

        double time_taken = double(end - start) / CLOCKS_PER_SEC;

        cout << V << "\t" << time_taken << " sec" << endl;
    }

    return 0;
}
