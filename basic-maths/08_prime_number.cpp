#include <iostream>

using namespace std;

bool isPrime(int n)
{
    // finding the no. of factors
    int count = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
            if ((n / i) != i)
            {
                count++;
            }
        }
    }
    if (count == 2) // a prime no. has only two factors
        return true;
    return false;
}

int main()
{
    int n;
    cin >> n;

    if (isPrime(n))
    {
        cout << "Prime" << endl;
    }
    else
        cout << "Not Prime" << endl;
}