template <typename T>
class Node
{
    T val;
    Node *left;
    Node *right;

    Node(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }

    ~Node()
    {
        delete root;
    }
};