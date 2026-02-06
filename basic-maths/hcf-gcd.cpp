#include <iostream>

using namespace std;

int gcd1(int a, int b)
{
    int gcd = 0;
    for (int i = 1; i <= min(a, b); i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }
    return gcd;
}

int gcd2(int a, int b)
{
    int gcd = 0;
    for (int i = min(a, b); i >= 1; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
            break;
        }
    }
    return gcd;
}

// optimized
int gcd(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    if (a == 0)
        return b;
    else
        return a;
}

int main()
{
    int a, b;

    cin >> a >> b;

    cout << gcd(a, b) << endl;
    cout << gcd1(a, b) << endl;
    cout << gcd2(a, b) << endl;
}