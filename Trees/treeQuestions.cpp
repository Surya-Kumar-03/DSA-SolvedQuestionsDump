#include <bits/stdc++.h>
#include "treeNode.h"

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

int numberOfNode(treeNode<int> *root)
{
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += numberOfNode(root->children[i]);
    }
    return ans;
}

int sumOfNode(treeNode<int> *root)
{
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += sumOfNode(root->children[i]);
    }
    return sum;
}

int printLargest(treeNode<int> *root)
{
    int largest = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        int ans = printLargest(root->children[i]);
        if (ans > largest)
            largest = ans;
    }
    return largest;
}

int heightReturner(treeNode<int> *root) // more optimised
{
    treeNode<int> *temp = root;
    if (temp == NULL)
    {
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < temp->children.size(); i++)
    {
        int childHeight = heightReturner(temp->children[i]);
        if (childHeight > ans)
        {
            ans = childHeight;
        }
    }
    return ans + 1;
}

// int heightReturner(treeNode<int> *root)
// {
//     int height = 1;
//     if (root->children.size() == 0)
//         return height;

//     int arr[root->children.size()];
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         arr[i] = heightReturner(root->children[i]);
//     }
//     sort(arr, arr + root->children.size(), greater<int>());
//     return height + arr[0];
// }

void valueAtK(treeNode<int> *root, int k)
{
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        valueAtK(root->children[i], k - 1);
    }
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
    // cout << "Number of Nodes is : " << numberOfNode(root);
    // cout << "Sum of Nodes is: " << sumOfNode(root);
    // cout << "Largest of all Nodes is : " << printLargest(root);
    cout << "The Height of the tree is : " << heightReturner(root);
    // valueAtK(root, 1); // prints all value at kth depth // 4 is the depth in this case
}