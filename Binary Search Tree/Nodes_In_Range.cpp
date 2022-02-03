//Basically we will be given range ,e.g, k1=5 and k2=12 . So we have to print all those nodes whose data are
// between this range.
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

void printRange(Node *root, int k1, int k2)
{

    if (root == NULL)
        return;

    if (root->data >= k1 && root->data <= k2)
    {
        printRange(root->left, k1, k2);
        cout << root->data << " ";
        printRange(root->right, k1, k2);
    }
    else if (root->data > k2)
    {
        printRange(root->left, k1, k2);
    }
    else if (root->data < k1)
    {
        printRange(root->right, k1, k2);
    }
}

int main()
{
    Node *root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);

    printRange(root, 5, 12);

    return 0;
}