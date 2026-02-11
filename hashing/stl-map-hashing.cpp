#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // unordered map can also be used here for better average time complexity O(1) for insert and search operations instead of O(log n) in map but it does not store the values in sorted order like map does.
    map<int, int> mpp; // stores all the values in sorted order
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    int q;
    cin >> q;

    while (q--)
    {
        int number;
        cin >> number;
        cout << mpp[number] << endl;
    }

    return 0;
}