#include <iostream>
#include <iomanip>
using namespace std;

long multiply(int i, int j);

int multiplyThis()
{
    int n1 = 8;
    int n2 = 12;
    long product = multiply(n1, n2);

    cout << "The product of " << n1 << " and " << n2 << " is " << product << endl;

    return 0;
}

long multiply(int i, int j)
{
    switch (i)
    {
        case 0:  return 0;
        case 1:  return j;
        default: return j + multiply(i-1, j);
    }
}
