#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
{
    int n = val.size();

    // Pair: (value/weight ratio, index)
    vector<pair<double, int>> ratio;
    for (int i = 0; i < n; i++)
    {
        double r = (double)val[i] / wt[i];
        ratio.push_back({r, i});
    }

    // Sort by ratio in descending order
    sort(ratio.begin(), ratio.end(), greater<pair<double, int>>());

    double maxValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        int idx = ratio[i].second;
        if (wt[idx] <= capacity)
        {
            // Take the whole item
            maxValue += val[idx];
            capacity -= wt[idx];
        }
        else
        {
            // Take fractional part
            maxValue += ratio[i].first * capacity;
            break;
        }
    }

    return maxValue;
}

int main()
{
    vector<int> sizes = {1000, 10000, 20000, 30000, 40000, 50000, 100000};
    int capacity = 10000;

    for (auto n : sizes)
    {
        vector<int> val(n);
        vector<int> wt(n);

        for (int i = 0; i < n; i++)
        {
            val[i] = abs(rand());
            wt[i] = abs(rand());
        }

        int start = clock();
        fractionalKnapsack(val, wt, capacity);
        int end = clock();
        int time = end - start;

        cout << "Time taken: " << time << endl;
    }

    return 0;
}