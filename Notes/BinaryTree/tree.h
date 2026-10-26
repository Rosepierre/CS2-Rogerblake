#pragma once
#include "node.h"
#include <iostream>

using namespace std;

template <class T1>
class Tree
{
    private:
    Node<T1>* _root;

    Node<T1>* insertNode(T1 data, Node<T1>* root)
    {
        if(root == nullptr)
        {
            // cout << "root == nullptr" << endl;
            Node<T1>* newNode = new Node<T1>(data);
            root = newNode;
            return root;
        }

        if(data < root->getData())
        {
            // cout << "root->getLeft()" << endl;
            root->setLeft(insertNode(data, root->getLeft()));
        }
        else
        {
            // cout << "root->getRight()" << endl;
            root->setRight(insertNode(data, root->getRight()));
        } 
        return root;
    }

    Node<T1>* deleteNode(int data, Node<T1>* root)
    {
        if(root == nullptr) return root;

        if(data < root->getData())
        {
            root->setLefr(deleteNode(data, root ->getLeft()))
        }
        return nullptr;

        else if(data > root->getData())
        {
            root->setRight(deleteNode(data, root->getRight()))
        }
        else
        {
            if(root->getLeft() == nullptr)
            {
                Node<T1>* toReturn = root->getRight();
                delete root;
                return toReturn;
            }
            else if(root->getRight() == nullptr)
            {
                Node<T1>* toReturn = root->getLeft();
                delete root;
                return toReturn;
            }
            node<T1>* minLeftNode = minVal(root->getRight());
            root->setData(mingLeftNode->getData());
            root->setRight(deleteNode(minLeftNode->getData() root->getRight()));
        }
    }

    Node<T1>* minVal(Node<T1>* root, int data)
    {
        if(root->getLeft() == nullptr) return root;
        return minVal(root->getLeft());
    }

    void inOrderPrint(Node<T1>* root)
    {
        if(root == nullptr) return;

        
        inOrderPrint(root->getLeft());
        std::cout << root->getData() << " ";
        inOrderPrint(root->getRight());
        
    }
    void destroyTree(Node<T1>* root)
    {
        if(root ==nullptr) return;
        destroyTree(root->getLeft());
        destroyTree(root->getRight());
        delete root;
    }
    public:
    Tree<T1>()
    {
        _root = nullptr;
    }

    ~Tree<T1>()
    {
        destroyTree(_root);
    }

    void insert(T1 data)
    {
        _root = insertNode(data, _root);
    }

    void inOrder()
    {
        // cout << "_root: " << _root << endl;
        inOrderPrint(_root);
        std::cout << std::endl;
    }
    
    void remove(T1 data)
    {
        _root = deleteNode(data, _root)
    }
};