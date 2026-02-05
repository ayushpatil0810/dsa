#include <bits/stdc++.h>
using namespace std;

void printDivisors(int n)
{
    vector<int> result;
    for (int i = 1; i * i < n; i++)
    {
        if (n % i == 0)
        {
            // cout << i << endl;
            result.push_back(i);

            if ((n / i) != i)
            {
                // cout << n / i << endl;
                result.push_back(n / i);
            }
        }
    }
    sort(result.begin(), result.end());

    for (const auto &element : result)
    {
        cout << element << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    printDivisors(n);
}