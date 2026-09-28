#include <iostream>

using namespace std;

struct Node
{
    int _data;
    Node* _next;
};

void addNode(Node**, int);
void printList(Node*);
void deleteList(Node*);

int main(int argc, char* argv[])
{
    Node* head = 0;

    addNode(&head, 42);
    addNode(&head, 15);
    addNode(&head, 23);
    
    printList(head);

    deleteList(head);
    
    return 0;
}

void deleteList(Node* head)
{
    Node* tobedeleted = head;

    while(head != nullptr)
    {
        head = head -> _next;
        delete tobedeleted;
        tobedeleted = head;
    }
}

void printList(Node* head)
{
    while (head != nullptr)
    {
        cout << head->_data << " ";
        head = head->_next;
    }
}

void addNode(Node** head, int data)
{
    Node* newNode = new Node;
    newNode->_data = data;
    newNode->_next = nullptr;

    if(*head == nullptr)
    {
        *head = newNode;
        return;
    }

    Node* curNode = *head;

    while(curNode->_next != nullptr)
    {
        curNode = curNode->_next;
    }
    curNode->_next = newNode;
    return;
}