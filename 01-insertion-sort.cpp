#include <iostream>
using namespace std;

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// TC: O(N^2)
// SC: O(1)
void insertion_sort(int arr[], int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    print_array(arr, n);
    insertion_sort(arr, n);
    print_array(arr, n);

    delete[] arr;

    return 0;
}