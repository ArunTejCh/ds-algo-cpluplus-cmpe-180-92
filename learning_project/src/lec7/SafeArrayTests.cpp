/*
#include <iostream>
#include <string>

#include "SafeArray.h"
using namespace std;

template <typename T>
void print(SafeArray<T> a);

void test_int();
void test_string();

int main()
{
    test_int();
    cout << endl;
    test_string();
}

template <typename T>
void print(SafeArray<T> a)
{
    for (int i = 0; i < a.get_length(); i++)
    {
        cout << " " << a[i];
    }
    cout << endl;
}

void test_int()
{
    SafeArray<int> a1(10), a2, a3;

    for (int i = 0; i < 10; i++)
    {
        a1[i] = 10*i;
    }

    a1[4] = -a1[4];
    cout << "a1 ="; print(a1);

    a3 = a2 = a1;
    cout << "a2 ="; print(a2);
    cout << "a3 ="; print(a3);
}

void test_string()
{
    SafeArray<string> a1(4), a2, a3;

    a1[0] = "Fee";
    a1[1] = "Fie";
    a1[2] = "Foe";
    a1[3] = "Fum";
    cout << "a1 ="; print(a1);

    a3 = a2 = a1;
    cout << "a2 ="; print(a2);
    cout << "a3 ="; print(a3);
}
*/
