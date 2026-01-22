#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int start, int mid, int end)
{
    vector<int> temp;
    int i = start;
    int j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= mid)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int index = 0; index < temp.size(); index++)
    {
        arr[index + start] = temp[index];
    }
}

void MergeSort(vector<int> &arr, int start, int end)
{
    if (start < end) /// run till just before start and end index become equal
    {
        int mid = start + (end - start) / 2;
        MergeSort(arr, start, mid);     // Left half
        MergeSort(arr, (mid + 1), end); // RIght Half

        merge(arr, start, mid, end);
    }
}

int main()
{
    vector<int> arr1 = {12, 11, 13, 5, 6, 7};
    MergeSort(arr1, 0, arr1.size() - 1);

    for (int i = 0; i < arr1.size(); i++)
    {
        cout << arr1[i] << " ";
    }

    cout << endl;

    vector<int> arr2 = {38, 27, 43, 3, 9, 82, 10};
    MergeSort(arr2, 0, arr2.size() - 1);

    for (int i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i] << " ";
    }

    return 0;
}