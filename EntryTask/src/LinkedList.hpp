#pragma once

template <typename T>
class LinkedList
{
public:
    LinkedList() = default;
    ~LinkedList();

    void Insert(T data);
    void Print();

    void Destroy();

private:
    struct Node {
        T data;
        Node* next = nullptr;
    };

    Node* m_Head = nullptr;
};

#include "LinkedList.impl.hpp"