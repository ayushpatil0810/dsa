#include <iostream>

using namespace std;

int sumOfDigits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        int lDigit = n % 10;
        sum += lDigit;
        n = n / 10;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    cout << sumOfDigits(n);
}