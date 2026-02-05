#include <iostream>

using namespace std;

int count = 0;

void print()
{

    if (count == 6)
        return; // Base Case

    cout << count << endl;
    count++;
    print();
}

int main()
{
    print();
    return 0;
}