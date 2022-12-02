#include <bits/stdc++.h>
#include "treeNode.h"
using namespace std;

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
        cout << "Enter the Number of Children of " << front->data << " : " << endl;
        cin >> no_of_children;
        for (int i = 0; i < no_of_children; i++)
        {
            int childData;
            cout << "Enter the data of " << i + 1 << " child of " << front->data << " : " << endl;
            cin >> childData;
            treeNode<int> *child = new treeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void preOrderTraversal(treeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preOrderTraversal(root->children[i]);
    }
}

void postOrderTraversal(treeNode<int> *root)
{
    if (root->children.size() == 0)
    {
        cout << root->data << " ";
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        postOrderTraversal(root->children[i]);
    }
    cout << root->data << " ";
}

void deleteTree(treeNode<int> *root) //function implementation
{
    if (root == NULL)
        return;
    for (int i = 0; i < root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }
    delete root;
}

int main()
{
    // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
    treeNode<int> *root = takeInputLevelWise();
    // preOrderTraversal(root);
    postOrderTraversal(root);
    // deleteTree(root); //function method
    delete root; //destructor method
    return 0;
}