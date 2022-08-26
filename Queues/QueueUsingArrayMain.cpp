#include <iostream>
using namespace std;
#include "QueueUsingArrayClass.cpp"

int main()
{
    QueueUsingArray<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    cout << q.dequeue() << endl;
    cout << q.getSize();
    return 0;
}
