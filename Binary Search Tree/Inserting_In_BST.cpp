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
// Recursive Method
Node *insert(Node *root, int key)
{

    if (root == NULL)
        return new Node(key);

    else if (root->data > key)
        root->left = insert(root->left, key);

    else if (root->data < key)
        root->right = insert(root->right, key);

    return root;
}

//Iterative Method

Node *insertIteratively(Node *root, int key)
{
    Node *temp = new Node(key);
    Node *parent = NULL, *curr = root;

    while (curr != NULL)
    {
        parent = curr;

        if (curr->data < key)
            curr = curr->right;

        else if (curr->data > key)
            curr = curr->left;

        else
            return root;
    }

    if (parent == NULL)
        return temp;

    else if (parent->data > key)
        parent->left = temp;

    else if (parent->data < key)
        parent->right = temp;

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

    Node *ans1 = insert(root, 23);
    inorder(ans1);
    cout << endl;
    Node *ans2 = insertIteratively(root, 1);
    inorder(ans2);

    return 0;
}

//Notes
//Time Complexity varies from O(logn){In case of self balancing BST} to O(n){In case of unbalanced BST}

//FOR GENERAL BST
//1. Time Complexity: O(h), h->height of the tree
//2. Auxilliary Space in Recusive Solution: O(h), h->height of the tree
//3. Auxilliary Space in Iterative Solution: O(1)