#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int BinarySearch(vector<int> &arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {
        int middle = (start + end) / 2;
        if (arr[middle] == target)
        {
            return middle;
        }
        if (arr[middle] < target)
        {
            start = middle + 1;
        }
        else
        {
            end = middle - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 23;
    int index = BinarySearch(arr, target);
    cout << index;
}