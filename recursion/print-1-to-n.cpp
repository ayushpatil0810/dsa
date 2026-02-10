#include <iostream>

using namespace std;

// with +1
// function call after printing
void printOneToN(int i, int n)
{
    if (i > n)
    {
        return;
    }
    cout << i << endl;
    printOneToN(i + 1, n);
}

// backtracking
// function call before printing
// make sure that the last fn call is executed first
void printOneToN_2(int i, int n)
{
    if (i < 1)
    {
        return;
    }
    printOneToN_2(i - 1, n);
    cout << i << endl;
}

int main()
{
    int n;
    cin >> n;

    printOneToN(1, n);
    // printOneToN_2(n, n);
}