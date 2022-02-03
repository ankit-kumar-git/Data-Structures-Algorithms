#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// Recursive Method
bool search(Node *root, int key)
{
    if (root == NULL)
        return false;

    else if (root->data == key)
        return true;

    else if (root->data > key)
        return search(root->left, key);

    else
        return search(root->right, key);
}

//Iterative Method

bool searchIteratively(Node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
            return true;

        else if (root->data > key)
            root = root->left;

        else
            root = root->right;
    }

    return false;
}
int main()
{
    Node *root = new Node(15);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->right->left = new Node(18);
    root->right->right = new Node(80);
    root->right->left->left = new Node(16);

    cout << search(root, 19) << endl;
    cout << searchIteratively(root, 80) << endl;

    return 0;
}

//Notes
//Time Complexity varies from O(logn){In case of self balancing BST} to O(n){In case of unbalanced BST}

//FOR GENERAL BST
//1. Time Complexity: O(h), h->height of the tree
//2. Auxilliary Space in Recusive Solution: O(h), h->height of the tree
//3. Auxilliary Space in Iterative Solution: O(1)