#include <iostream>
using namespace std;
#include "QueueUsingDynamicArrayClass.cpp"

int main()
{
    QueueUsingArray<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(20);
    q.enqueue(20);
    q.enqueue(20);
    q.enqueue(20);
    q.enqueue(20);
    q.enqueue(20);
    q.enqueue(20);
    cout << q.getSize();
    return 0;
}
