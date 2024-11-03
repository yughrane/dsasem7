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

Insertion Sort:
#include <iostream>
using namespace std;

int main()
{
    int arr[5];
    int j, temp;

    // Take input from user
    cout << "Enter 5 integers: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    // Insertion sort algorithm
    for (int i = 1; i < 5; i++)
    {
        temp = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    // Display sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

include <iostream>
using namespace std;

// Function to merge two subarrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int leftArray[n1], rightArray[n2];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArray[i] = arr[mid + 1 + i];

    // Merge the temp arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArray[], if any
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArray[], if any
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

// Function to implement merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Recursively sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is: ";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "Sorted array is: ";
    printArray(arr, arr_size);

}
