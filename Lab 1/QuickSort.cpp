#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int start, int end)
{
    int i = start - 1;
    int pivot = arr[end];
    for (int j = start; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            idx++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }

    i++;
    int temp = arr[end];
    arr[end] = arr[i];
    arr[i] = temp;

    return i;
}

void QS(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int pivIndex = partition(arr, start, end);
        QS(arr, start, pivIndex - 1);
        QS(arr, pivIndex + 1, end);
    }
}

int main()
{
    vector<int> arr = {
        33,
        1,
        3,
        81,
        44,
        4,
    };
    QS(arr, 0, arr.size() - 1);

    for (int val : arr)
    {
        cout << val << " ";
    }
}
