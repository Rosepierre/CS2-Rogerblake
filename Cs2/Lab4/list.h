#pragma once
#include "node.h"
#include <iostream>

using namespace std;

template <class T1>
class List
{
    private:
        Node<T1> *_head;
        Node<T1> *_tail;
        size_t listSize;

    public:
        List();
        ~List();

        bool empty();
        size_t size();

        void push_front(T1);
        T1 pop_front();
        T1 front();
        void push_back(T1);
        T1 pop_back();
        T1 back();

        bool operator==(const List<T1>&);
        // Have to declare a template for friend functions using a different template variable
        template <class T2>
        friend ostream &operator<<(ostream &, const List<T2> &);
};

// set to nullptr and initialize listSize
template <class T1>
List<T1>::List()
{
   _head = nullptr;
   _tail = nullptr;
   listSize = 0;
}

// iteratively delete the list starting at _head
template <class T1>
List<T1>::~List()
{
    Node<T1>* current = _head;

    while (current != nullptr)
    {   
        Node<T1>* nextNode = current->getNext();

        delete current;

        current = nextNode;
    }
    _head = nullptr;
    _tail = nullptr;
    listSize = 0;

}

// return true if the list is empty, false otherwise.
// Do not just check listSize, should actually check _head and _tail
template <class T1>
bool List<T1>::empty()
{
    if (_head == nullptr && _tail == nullptr) 
    {
        return true;
    }

    return false;
}

// return number of elements in list
template <class T1>
size_t List<T1>::size()
{
    return listSize;
}

// add an element to the beginning of the list, updating _head
template <class T1>
void List<T1>::push_front(T1 data)
{
    Node<T1>* newNode = new Node<T1>;
    
    newNode->setData(data);

    if(empty())
    {
        _head = newNode;
        _tail = newNode;
        listSize++;
        return;
    }
    newNode->setNext(_head);

    _head->setPrev(newNode);
    _head = newNode;
    listSize++;
}
// return the first element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::front()
{
    if(empty())
    {
        cout << "Empty List" << endl;
        return 0;
    }
    return _head->getData();
}

// remove the first element from the list and return its data
// if the list is empty, print that out and return 0;
template <class T1>
T1 List<T1>::pop_front()
{
    if(empty())
    {
        cout << "Empty List" << endl;
        return 0;
    }
    if(listSize == 1)
    {
        T1 removedData = _head->getData();

        delete _head;

        _head = nullptr;
        _tail = nullptr;
        listSize--;
        return removedData;
    }

    Node<T1>* oldHead = _head;
    T1 removedData = oldHead->getData();
    _head = _head->getNext();
    _head->setPrev(nullptr);
    delete oldHead;
    listSize--;
    return removedData;
}

// add an element to the end of hte list, updating _tail
template <class T1>
void List<T1>::push_back(T1 data)
{
    Node<T1>* newNode = new Node<T1>;
    
    newNode->setData(data);

    if(empty())
    {
        _head = newNode;
        _tail = newNode;
        listSize++;
        return;
    }
    newNode->setPrev(_tail);

    _tail->setNext(newNode);
    _tail= newNode;
    listSize++;

}

// return the last element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::back()
{
    if(empty())
    {
        cout << "Empty List" << endl;
        return 0;
    }
    return _tail->getData();
}

// remove the last element from the list and return its data
// if the list is empty, print that out and return 0;
template <class T1>
T1 List<T1>::pop_back()
{
    if(empty())
    {
        cout << "Empty List" << endl;
        return 0;
    }
    if(listSize == 1)
    {
        T1 removedData = _tail->getData();

        delete _tail;

        _head = nullptr;
        _tail = nullptr;
        listSize--;
        return removedData;
    }

    Node<T1>* oldTail = _tail;
    T1 removedData = oldTail->getData();
    _tail = _tail->getPrev();
    _tail->setNext(nullptr);
    delete oldTail;
    listSize--;
    return removedData;
}

// overloading <<, should return a space separated stream of all of the elements
template <class T2>
ostream &operator<<(ostream &os, const List<T2> &list)
{
    Node<T2>* current = list._head;

    while (current != nullptr)
    {
        os << current->getData() << " ";
        current = current->getNext();
    }

    return os;
}

// should iterate through each list to check that they are exactly the same
template <class T1>
bool List<T1>::operator==(const List<T1>& rhs)
{   
    if (listSize != rhs.listSize)
    {
        return false;
    }
    Node<T1>* current = _head;
    Node<T1>* otherCurrent = rhs._head;
    while(current != nullptr){
    if(current->getData() != otherCurrent->getData())
    {
        return false;
    }
    current = current->getNext();
    otherCurrent = otherCurrent->getNext();
}
return true;
}