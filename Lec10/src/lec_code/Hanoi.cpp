#include <iostream>
using namespace std;

typedef char Pin;

const static char A = 'A';
const static char B = 'B';
const static char C = 'C';

void solve(const int n, const Pin source, const Pin temp, const Pin dest);
void move(const Pin from, const Pin to);

int hanoi()
{
    int n = 5;

    cout << "Solve for " << n << " disks:" << endl << endl;
    solve(n, A, B, C);

    return 0;
}

void move(Pin from, Pin to)
{
    cout << "Move disk from " << from << " to " << to << endl;
}

void solve(const int n, const Pin source, const Pin temp, const Pin dest)
{
    if (n > 0)
    {
        solve(n-1, source, dest, temp);
        move(source, dest);
        solve(n-1, temp, source, dest);
    }
}
