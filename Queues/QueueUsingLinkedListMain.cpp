#include <iostream>
#include "QueueUsingLinkedListClass.cpp"
using namespace std;

int main()
{
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    cout << q.getSize() << endl;
    cout << q.front() << endl;
    //Expected Output 10 20 30 2 40
    return 0;
}