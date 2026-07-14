#include <iostream>

using namespace std;

int is_palindrome_number(int n)
{
    int original = n;
    int reversed = 0;

    while (n != 0)
    {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }

    return (original == reversed);
}

int main()
{
    int n;
    cin >> n;

    if (is_palindrome_number(n))
    {
        cout << "The number is a palindrome." << endl;
    }
    else
    {
        cout << "The number is not a palindrome." << endl;
    }

    return 0;
}