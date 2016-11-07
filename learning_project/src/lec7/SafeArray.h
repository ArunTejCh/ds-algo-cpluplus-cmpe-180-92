/*
#ifndef SAFEARRAY_H_
#define SAFEARRAY_H_

#include <cassert>

template <typename T>
class SafeArray
{
public:
    SafeArray();
    SafeArray(int len);
    SafeArray(const SafeArray<T>& other);  // copy constructor
    ~SafeArray();

    int get_length() const;

    SafeArray<T>& operator =(const SafeArray<T>& rhs);
    T& operator [](int i) const;

private:
    T *elements;
    int length;
};

template <typename T>
SafeArray<T>::SafeArray() : elements(nullptr), length(0)
{
}

template <typename T>
SafeArray<T>::SafeArray(int len) : elements(nullptr), length(len)
{
    elements = new T[length];
}

template <typename T>
SafeArray<T>::SafeArray(const SafeArray<T>& other) : elements(nullptr), length(0)
{
    length = other.length;
    elements = new T[length];

    for (int i = 0; i < length; i++)
    {
        elements[i] = other.elements[i];
    }
}

template <typename T>
SafeArray<T>::~SafeArray()
{
    if (elements != nullptr) delete[] elements;
}

template <typename T>
int SafeArray<T>::get_length() const { return length; }

template <typename T>
SafeArray<T>& SafeArray<T>::operator =(const SafeArray<T>& rhs)
{
    if (this == &rhs) return *this;
    if (elements != nullptr) delete[] elements;

    length = rhs.length;
    elements = new T[length];

    for (int i = 0; i < length; i++)
    {
        elements[i] = rhs.elements[i];
    }

    return *this;
}

template <typename T>
T& SafeArray<T>::operator [](int i) const
{
    assert((i >= 0) && (i < length));
    return elements[i];
}

#endif  SAFEARRAY_H_
*/
