#include <iostream>

using namespace std;

int res = 0;
void sum(int i, int n)
{
    if (i > n)
    {
        return;
    }
    res += i;
    sum(i + 1, n);
}

int main()
{
    int n;
    cin >> n;

    sum(1, n);
    cout << res;
}