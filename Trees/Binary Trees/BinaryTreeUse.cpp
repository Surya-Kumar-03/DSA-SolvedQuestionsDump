#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

void printBinaryTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << ":";
    if (root->left)
        cout << "L" << root->left->data;
    if (root->right)
        cout << " R" << root->right->data;
    cout << endl;
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}

BinaryTreeNode<int> *takeInput() // complicated method
{
    int rootData;
    cout << "Enter Data: ";
    cin >> rootData;
    if (rootData == -1)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *left = takeInput();
    BinaryTreeNode<int> *right = takeInput();
    root->left = left;
    root->right = right;
    return root;
}

BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter Root Data : ";
    cin >> rootData;
    if (rootData == -1)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data << ": ";
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *left = new BinaryTreeNode<int>(leftChildData);
            front->left = left;
            pendingNodes.push(left);
        }
        cout << "Enter right child of " << front->data << ": ";
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *right = new BinaryTreeNode<int>(rightChildData);
            front->right = right;
            pendingNodes.push(right);
        }
    }
    return root;
}

int countNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void inorderTraversal(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}


void printBinaryTreeLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<BinaryTreeNode<int> *> pending;
    pending.push(root);
    while (!pending.empty())
    {
        int size = pending.size();
        for (int i = 0; i < size; i++)
        {
            BinaryTreeNode<int> *front = pending.front();
            pending.pop();
            if (front->left)
                pending.push(front->left);
            if (front->right)
                pending.push(front->right);
            cout << front->data << " ";
        }
        cout << endl;
    }
}

int main()
{
    // BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int> *left = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int> *right = new BinaryTreeNode<int>(3);

    // root->left = left;
    // root->right = right;
    // BinaryTreeNode<int> *root = takeInput();
    BinaryTreeNode<int> *root = takeInputLevelWise(); // level wise
    // printBinaryTree(root);
    // cout << "The number of Nodes are : " << countNodes(root);
    // inorderTraversal(root);
    printBinaryTreeLevelWise(root);
    delete root;
    return 0;
}