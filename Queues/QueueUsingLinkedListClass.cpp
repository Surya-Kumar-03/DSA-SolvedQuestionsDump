#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Queue
{
public:
    Node<T> *head;
    Node<T> *tail;
    int size;
    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(T element)
    {
        Node<T> *newNode = new Node<T>(element);
        if (tail == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    T front()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty";
            return 0;
        }
        return head->data;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            return 0;
        }
        T tempdata = head->data;
        Node<T> *tempDeAllocate = head;
        head = head->next;
        delete tempDeAllocate;
        size--;
        return tempdata;
    }
};