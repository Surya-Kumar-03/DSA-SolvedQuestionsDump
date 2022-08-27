// Header file implementation of Queue using Dynamic Array
template <typename T>
class QueueUsingArray
{
public:
    T *data;
    int nextIndex;
    int firstIndex;
    int size;     // Size represents elements in queue
    int capacity; // capacity represents total capacity of queue

    QueueUsingArray()
    {
        data = new T[5]; // default size of array is 5
        nextIndex = 0;   // NextIndex is where the Next Element should be added
        firstIndex = -1; // FirstIndex is -1 denoting there are no elements in the Queue,
        // first element to be removed from queue
        size = 0;
        capacity = 5; // Default Capacity is 5, it is dynamic
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
            T *newData = new T[capacity * 2];
            for (int i = firstIndex, j = 0; j < capacity; i = (i + 1) % capacity, j++) // we copy in order of removal
            {
                newData[j] = data[i];
            }
            delete[] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
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
