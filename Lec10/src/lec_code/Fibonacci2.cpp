#include <iostream>
#include <iomanip>
using namespace std;

long fibonacciTwo(int n);

int fibonacci2()
{
    for (int i = 1; i <= 50; i++) {
        cout << "fibonacci(" << setw(2) << i << ") = "
        	 << setw(11) << fibonacciTwo(i) << endl;
    }
    return 0;
}

long fibonacciTwo(int n)
{
    if (n <= 2) return 1;
    else        return fibonacciTwo(n-2) + fibonacciTwo(n-1);
}
