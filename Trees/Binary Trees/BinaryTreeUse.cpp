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

int main()
{
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *left = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *right = new BinaryTreeNode<int>(3);

    root->left = left;
    root->right = right;
    printBinaryTree(root);
    delete root;
    return 0;
}