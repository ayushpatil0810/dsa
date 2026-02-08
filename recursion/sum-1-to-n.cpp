#include <iostream> 

using namespace std;

// paramatarized way
void print(int i, int sum)
{
    if (i < 0)
    {
        cout << sum << endl;
        return;
    }
    print(i - 1, sum + i);
}

// functional recursion

int sum_1_to_n(int n)
{
    if (n == 0)
        return 0;

    return n + sum_1_to_n(n - 1);
}

int main()
{
    int n;
    cin >> n;

    // print(n, 0);
    cout << sum_1_to_n(n);
}