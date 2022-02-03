//Basically we will be given a sorted array and we will have to form a BST which is of minimum height.
//Here the root node will be the middle element for min height of tree.
//CHECKOUT  LEVEL UP BST COURSE.

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
};

void inorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

Node *makeBST(int arr[], int start, int end)
{

    //When no element is left or present
    if (start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);

    //We should link nodes to parent node while nodes return;
    root->left = makeBST(arr, start, mid - 1);
    root->right = makeBST(arr, mid + 1, end);

    return root;
}

int main()
{
    int arr[8] = {1, 2, 3, 4, 5, 6, 7};

    //Arguments are array,start,end;
    Node *root = makeBST(arr, 0, 6);
    inorderTraversal(root);

    return 0;
}