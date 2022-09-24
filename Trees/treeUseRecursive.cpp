#include <iostream>
using namespace std;
#include "treeNode.h"

void printTree(treeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ": ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << " ";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

treeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter Data : ";
    cin >> rootData;
    treeNode<int> *root = new treeNode<int>(rootData);
    int n;
    cout << "Enter the Number of Children of " << rootData << " : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        treeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

int main()
{
    treeNode<int> *root = takeInput();
    printTree(root);
    return 0;
}