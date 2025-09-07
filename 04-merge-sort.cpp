#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void mergeArrays(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;

    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] < arr[right])
            temp.push_back(arr[left++]);
        else
            temp.push_back(arr[right++]);
    }

    while (left <= mid)
        temp.push_back(arr[left++]);

    while (right <= high)
        temp.push_back(arr[right++]);

    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}

void mS(vector<int> &arr, int left, int right)
{
    // base case
    if (left == right)
        return;

    int mid = left + (right - left) / 2;

    mS(arr, left, mid);
    mS(arr, mid + 1, right);

    mergeArrays(arr, left, mid, right);
}

void mergeSort(vector<int> &arr, int size)
{
    mS(arr, 0, size - 1);
}

int main()
{
    vector<int> sizes = {1000, 10000, 20000, 30000, 40000, 50000, 100000};
    for (auto n : sizes)
    {
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
            arr[i] = rand();

        int start = clock();
        mergeSort(arr, arr.size());
        int end = clock();
        int time = end - start;

        cout << "Time taken by merge sort: " << time << endl;
    }

    return 0;
}