#include <vector>
using namespace std;

template <typename T>
class treeNode
{
public:
    T data;
    vector<treeNode<T> *> children;

    treeNode(T data)
    {
        this->data = data;
    }
};