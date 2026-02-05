#include <iostream>

using namespace std;

int reverseNumber(int n);

int main()
{
    int num;

    cin >> num;

    cout << reverseNumber(num);
}

int reverseNumber(int n)
{
    int revNum = 0;
    while (n != 0)
    {
        int lDigit = n % 10;
        revNum = (revNum * 10) + lDigit;
        n /= 10;
    }
    return revNum;
}