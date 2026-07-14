// Reverse an integer -> +ve, -ve, 0

// Step 1: Initialize the reversed number as 0.
// Step 2: Extract the last digit using % 10.
// Step 3: Remove the last digit using / 10.
// Step 4: Before appending the digit, check if doing so would overflow.
// Step 5: If overflow/underflow occurs, return 0.
// Step 6: Append the digit to the reversed number.
// Step 7: Repeat until the original number becomes 0.
// Step 8: Return the reversed number.

// LEETCODE: 7. Reverse Integer
// https://leetcode.com/problems/reverse-integer

#include <iostream>
#include <climits>

using namespace std;

int reverseInteger(int n)
{
    int reversed = 0;

    while (n != 0)
    {
        // Extract the last digit
        int digit = n % 10;

        // Remove the last digit
        n /= 10;

        // Check for overflow
        if (reversed > INT_MAX / 10 ||
            (reversed == INT_MAX / 10 && digit > 7))
        {
            return 0;
        }

        // Check for underflow
        if (reversed < INT_MIN / 10 ||
            (reversed == INT_MIN / 10 && digit < -8))
        {
            return 0;
        }

        // Append the extracted digit
        reversed = reversed * 10 + digit;
    }

    return reversed;
}

int main()
{
    int n;
    cin >> n;

    cout << reverseInteger(n);

    return 0;
}