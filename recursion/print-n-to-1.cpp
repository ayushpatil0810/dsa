#include <iostream>

using namespace std;

void printNToOne(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << endl;
    printNToOne(n - 1);
}

int main()
{
    int n;
    cin >> n;
    printNToOne(n);
}