#include <iostream>
#include <iomanip>
using namespace std;

long fibonacciThree(int n);

int fibonacci3()
{
    fibonacciThree(6);

    return 0;
}

long fibonacciThree(int n)
{
    cout << "Called fibonacci(" << n << ")" << endl;

    long f;
    if (n <= 2) f = 1;
    else        f = fibonacciThree(n-2) + fibonacciThree(n-1);

    cout << "Returning fibonacci(" << n << ") = " << f << endl;
    return f;
}
