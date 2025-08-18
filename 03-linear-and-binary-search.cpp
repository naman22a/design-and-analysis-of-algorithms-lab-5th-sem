#include <iostream>
using namespace std;

int linear_search(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int binary_search(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void selection_sort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int mini = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[mini])
                mini = j;
        }
        swap(arr[i], arr[mini]);
    }
}

int main()
{
    // input array
    int n;
    cout << "Enter n: ";
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    print_array(arr, n);

    // input target
    int target;
    cout << "Enter target: ";
    cin >> target;

    cout << "===== Menu =====" << endl;
    cout << "1. Linear search" << endl;
    cout << "2. Binary search" << endl;

    int option;
    cout << "Enter option: ";
    cin >> option;

    switch (option)
    {
    case 1:
        cout << "Element found at index: " << linear_search(arr, n, target) << endl;
        break;
    case 2:
        selection_sort(arr, n);
        cout << "Element found at index: " << binary_search(arr, n, target) << endl;
        break;

    default:
        cout << "Invalid option" << endl;
        break;
    }

    delete[] arr;

    return 0;
}