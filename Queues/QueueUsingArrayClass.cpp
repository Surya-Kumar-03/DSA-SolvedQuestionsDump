// Header file implementation of Queue using Array
template <typename T>
class QueueUsingArray
{
public:
    T *data;
    int nextIndex;
    int firstIndex;
    int size;     // Size represents elements in queue
    int capacity; // capacity represents total capacity of queue

    QueueUsingArray(int s)
    {
        data = new T[s];
        nextIndex = 0;   // NextIndex is where the Next Element should be added
        firstIndex = -1; // FirstIndex is -1 denoting there are no elements in the Queue
        size = 0;
        capacity = s;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(int element)
    {
        if (size == capacity)
        {
            cout << "Queue Full! " << endl;
            return;
        }
        if (firstIndex == -1)
        {
            firstIndex = 0;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity; // to use circular queue
        size++;
    }

    int front()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty! ";
            return 0;
        }
        return data[firstIndex];
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty! ";
            return 0;
        }
        int temp = data[firstIndex];
        size--;
        firstIndex = (firstIndex + 1) % capacity;
        return temp;
    }
};
