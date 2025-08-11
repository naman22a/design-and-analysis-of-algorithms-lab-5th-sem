#include <iostream>
using namespace std;

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

void bubble_sort(int arr[], int n)
{
    for (int i = n - 1; i >= 1; i--)
    {
        bool swapped = false;

        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swapped = true;
                swap(arr[j], arr[j + 1]);
            }
        }

        if (swapped == false)
            break;
    }
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
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

    cout << "===== Menu =====" << endl;
    cout << "1. Selection sort" << endl;
    cout << "2. Bubble sort" << endl;

    int option;
    cout << "Enter option: ";
    cin >> option;

    switch (option)
    {
    case 1:
        selection_sort(arr, n);
        break;
    case 2:
        bubble_sort(arr, n);
        break;

    default:
        cout << "Invalid option" << endl;
        break;
    }

    print_array(arr, n);

    delete[] arr;

    return 0;
}