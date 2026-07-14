// Try not to use the modulus operator (%) as its a  heavy operation. Instead, use bitwise operators to determine if a number is odd or even.

#include <iostream>

using namespace std;

int odd_even(int num)
{
    // if (num % 2 == 0)
    // {
    //     cout << num << " is even." << endl;
    // }
    // else
    // {
    //     cout << num << " is odd." << endl;
    // }
    // return 0;

    if (num & 1) // Using bitwise AND to check if the least significant bit is 0 (even)
    // num & 1 = 1 means the number is odd, num & 1 = 0 means the number is even
    {
        cout << num << " is odd." << endl;
    }
    else
    {
        cout << num << " is even." << endl;
    }
}

int main()
{
    int number;
    cout << "Enter an integer: ";
    cin >> number;
    odd_even(number);
    return 0;
}