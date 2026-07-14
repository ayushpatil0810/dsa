// Leetcode Problem: 231. Power of Two => https://leetcode.com/problems/power-of-two

#include <iostream>

using namespace std;

int isPowerOfTwo(int n)
{
    if (n <= 0)
    {
        return 0; // Not a power of 2
    }

    // A number is a power of 2 if it has exactly one bit set in its binary representation.
    return (n & (n - 1)) == 0;
}

int main()
{
    int n;
    cin >> n;

    if (isPowerOfTwo(n))
    {
        cout << "The number is a power of 2." << endl;
    }
    else
    {
        cout << "The number is not a power of 2." << endl;
    }

    return 0;
}