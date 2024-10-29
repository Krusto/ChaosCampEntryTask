#pragma once
#include <functional>

template <typename T>
/**
 * A simple singly linked list class
 *
 * This class provides a basic implementation of a singly linked list.
 * It is designed to be used as a stack or a queue, and it provides
 * functions to insert, destroy, and iterate over the elements in the
 * list.
 *
 * @tparam T The type of the elements stored in the list
 */
class LinkedList
{
public:
    LinkedList() = default;
    ~LinkedList();

public:
    /**
     * Inserts a new element at the beginning of the list
     *
     * This function creates a new node containing the given data
     * and inserts it at the beginning of the linked list.
     *
     * @param data The data to be inserted into the list
     */
    void Insert(T data);
    /**
     * Destroys all elements in the list
     *
     * This function deletes all the nodes in the linked list and
     * resets the head of the list to nullptr.
     */
    void Destroy();
    /**
     * Iterates over the elements in the list and executes the given function
     *
     * This function iterates over the elements in the linked list and
     * executes the given function for each element. The function takes
     * a single argument of type `const T&` which is the current element
     * being processed.
     *
     * @param func The function to be executed for each element in the list
     */
    void ForEach(std::function<void(const T&)> func) const;

public:
    struct Node {
        T data;
        Node* next = nullptr;
    };

private:
    Node* m_Head = nullptr;
};

#include "LinkedList.impl.hpp"