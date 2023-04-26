#include <bits/stdc++.h>
using namespace std;

// No of subsets
int sumOfSubsets(vector<int> arr, int x, int i)
{
    if (i == arr.size())
    {
        if (x == 0)
            return 1;
        return 0;
    }
    int inc = sumOfSubsets(arr, x - arr[i], i + 1);
    int exc = sumOfSubsets(arr, x, i + 1);
    return inc + exc;
}

// find first subset
bool subsetSum(vector<int> &arr, int x, int i, vector<int> &subset)
{
    if (x == 0)
        return true;

    if (i == arr.size())
        return false;

    bool include = subsetSum(arr, x - arr[i], i + 1, subset);
    if (include)
    {
        subset.push_back(arr[i]);
        return true;
    }

    bool exclude = subsetSum(arr, x, i + 1, subset);
    if (exclude)
        return true;

    return false;
}

auto main() -> int
{
    vector<int> arr{1, 2, 3, 4, 5};
    int x = 10;
    vector<int> subset;
    cout << sumOfSubsets(arr, x, 0) << endl
         << endl;
    if (subsetSum(arr, x, 0, subset))
    {
        for (auto i : subset)
        {
            cout << i << " ";
        }
    }
}