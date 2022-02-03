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

void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//Get Successor function (Works only for a node whose right child is not NULL)
Node *getSuccessor(Node *root)
{
    root = root->right;
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

// Recursive Method
Node *deleteNode(Node *root, int key)
{

    if (root == NULL)
        return root;

    else if (root->data > key)
        root->left = deleteNode(root->left, key);

    else if (root->data < key)
        root->right = deleteNode(root->right, key);

    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        else
        {
            Node *succ = getSuccessor(root);
            root->data = succ->data;

            root->right = deleteNode(root->right, succ->data);
        }
    }
    return root;
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

    Node *ans1 = deleteNode(root, 23);
    inorder(ans1);

    return 0;
}

//Notes
//Time Complexity varies from O(logn){In case of self balancing BST} to O(n){In case of unbalanced BST}

//FOR GENERAL BST
//1. Time Complexity: O(h), h->height of the tree
//2. Auxilliary Space in Recusive Solution: O(h), h->height of the tree