#ifndef NODE_H_
#define NODE_H_

/***** Convert this to a class template to handle
 ***** multiple types of data stored in the nodes. */

using namespace std;

template <typename T>
class Node
{
public:
    Node(T value);
    ~Node();

    T data;
    Node<T> *next;
};

template <typename T>
Node<T>::Node(T value) : data(value), next(NULL)
{
}

template <typename T>
Node<T>::~Node()
{
}

#endif /* NODE_H_ */
