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

Node *findCeil(Node *root, int key)
{
    Node *res = NULL;
    while (root != NULL)
    {
        if (root->data == key)
            return root;

        else if (root->data < key)
        {
            root = root->right;
        }
        else
        {
            res = root;
            root = root->left;
        }
    }
    return res;
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(78);
    root->right->left->left = new Node(55);
    root->right->left->right = new Node(65);

    Node *ans = findCeil(root, 75);
    cout << ans->data << endl;

    return 0;
}

//Above solution is an efficient solution with following time and space complexity.
//1. Time Complexity: O(h), h->height of the tree
//2. Auxilliary Space : O(1)