#include <iostream>
#include <math.h>
using namespace std;

int decimalToBinary(int n);

int main()
{
    int n;
    cin >> n;

    cout << decimalToBinary(n);
    return 0;
}

int decimalToBinary(int n)
{
    int ans = 0;
    int place = 1;
    while (n != 0)
    {
        int bit = n & 1;
        ans += bit * place;
        place *= 10;
        n = n >> 1;
    }
    return ans;
}