#include <iostream>
#include <climits> // For INT_MAX

using namespace std;

int smallestDigit(int n)
{
    int smallest = INT_MAX; // Initialize smallest to the maximum integer value
    while (n > 0)
    {
        int lDigit = n % 10;
        // if (lDigit < smallest)
        // {
        //     smallest = lDigit;
        // }
        smallest = min(smallest, lDigit); // Update smallest if lDigit is smaller
        n = n / 10;
    }
    return smallest;
}

int main()
{
    int n;
    cin >> n;
    cout << smallestDigit(n);
}