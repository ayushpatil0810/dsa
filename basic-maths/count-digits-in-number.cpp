#include <iostream>

using namespace std;

int countDigits(int n)
{
    int count = 0;
    while (n > 0)
    {
        int lDigit = n % 10;
        count++;
        n = n / 10;
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    cout << countDigits(n);
}