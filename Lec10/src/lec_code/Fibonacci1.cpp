#include <iostream>
#include <iomanip>
using namespace std;

long fibonacci(int n);

int fibonacci1()
{
    for (int i = 1; i <= 50; i++) {
        cout << "fibonacci(" << setw(2) << i << ") = "
             << setw(11) << fibonacci(i) << endl;
    }

    return 0;
}

long fibonacci(int n)
{
    if (n <= 2) return 1;
    else {
        long older = 1;
        long old   = 1;
        long next  = 1;

        for (int i = 3; i <= n; i++) {
            next = older + old;
            older = old;
            old   = next;
        }

        return next;
    }
}
