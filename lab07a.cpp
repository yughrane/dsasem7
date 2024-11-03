#include <iostream>

using namespace std;

bool binarySearch(int low, int high, int key, int arr[])
{
    if (low > high)
    {
        return false;
    }

    int mid = low + (high - low) / 2;
    if (key > arr[mid])
    {
        return binarySearch(mid + 1, high, key, arr);
    }
    else if (key < arr[mid])
    {
        return binarySearch(low, mid - 1, key, arr);
    }
    else
    {
        return true;
    }
}

int main()
{
    int num;
    int temp;
    int element;

    cout << "Enter the size of the array: ";
    cin >> num;

    int arr[num];

    cout << endl
         << "Enter the elements in the array: ";
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << "Enter an element to search: ";
    cin >> element;

    int low = 0;
    int high = num - 1;
    bool flag = binarySearch(low, high, element, arr);

    if (flag)
    {
        cout << endl
             << "element found";
    }
    else
    {
        cout << endl
             << "element not found";
    }
}