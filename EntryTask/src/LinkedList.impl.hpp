#include "LinkedList.hpp"
#include <iostream>

template <typename T>
void LinkedList<T>::Insert(T data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = m_Head;
    m_Head = newNode;
}

template <typename T>
void LinkedList<T>::Print()
{
    Node* currentNode = m_Head;
    while (currentNode != nullptr)
    {
        std::cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    std::cout << std::endl;
}

template <typename T>
inline void LinkedList<T>::Destroy()
{
    Node* currentNode = m_Head;
    while (currentNode != nullptr)
    {
        Node* nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    Destroy();
}