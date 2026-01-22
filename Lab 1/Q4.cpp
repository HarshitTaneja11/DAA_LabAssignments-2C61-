#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubarraySum(vector<int> &arr)
{
    int max_current = arr[0];
    int max_global = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        max_current = max(arr[i], arr[i] + max_current);

        max_global = max(max_global, max_current);
    }
    return max_global;
}

int main()
{
    vector<int> arr = {-2, -5, 6, -2, -3, 1, 5, -6};

    int max = maxSubarraySum(arr);
    cout << max;
}