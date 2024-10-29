#include "LinkedList.hpp"

template <typename T>
LinkedList<T>::~LinkedList()
{
    Destroy();
}

template <typename T>
void LinkedList<T>::Insert(T data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = m_Head;
    m_Head = newNode;
}

template <typename T>
void LinkedList<T>::ForEach(std::function<void(const T&)> func) const
{
    Node* currentNode = m_Head;
    while (currentNode != nullptr)
    {
        func(currentNode->data);
        currentNode = currentNode->next;
    }
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

    m_Head = nullptr;
}
