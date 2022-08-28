#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.pop();

    /* enqueue = push
    dequeue = pop
    empty()
    pop won't return anything
    use front() function to access first element in queue
    */
    cout << q.front() << endl;
    cout << q.empty();
    return 0;
}