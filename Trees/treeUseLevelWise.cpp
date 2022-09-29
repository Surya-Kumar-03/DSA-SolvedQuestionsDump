#include <iostream>
#include "treeNode.h"
#include <queue>

using namespace std;

void printTree(treeNode<int> *root)
{
    cout << root->data << " : ";
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

treeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter Root Data: ";
    cin >> rootData;
    treeNode<int> *root = new treeNode<int>(rootData);
    queue<treeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        treeNode<int> *front = pendingNodes.front();
        int no_of_children;
        pendingNodes.pop();
        cout << "Enter the Number of Children of " << front->data << " : ";
        cin >> no_of_children;
        for (int i = 0; i < no_of_children; i++)
        {
            int childData;
            cout << "Enter the data of " << i + 1 << " child of " << front->data << " : ";
            cin >> childData;
            treeNode<int> *child = new treeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int main()
{
    // treeNode<int>* root=new treeNode<int>(10);
    // treeNode<int>* child1=new treeNode<int>(20);
    // treeNode<int>* child2=new treeNode<int>(30);
    // treeNode<int>* child3=new treeNode<int>(40);

    // root->children.push_back(child1);
    // root->children.push_back(child2);
    // child1->children.push_back(child3);
    treeNode<int> *root = takeInputLevelWise();
    printTree(root);
}