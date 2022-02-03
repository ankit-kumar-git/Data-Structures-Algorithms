//Basically we are gicven a BST, we have to return the sorted Linked List. We don't have to create a linked list , rather we have to point the right pointer of every node to the next node for linked list. We will basically return head and tail from everynode. We will get head and tail for a linkedlist from left subtree and from right subtree and we will combine it with root node and rturn final head and tail. So this head will be the head of our entire cinverted linked list.

//CHECKOUT LEVLE UP COURSE OF BST (TREE TO LINKED LIST)

//Basically we will be given root  So we have to print paths for all leaf nodes ,i.e, from root to all leaf nodes.

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
class LinkedList
{
public:
    Node *head;
    Node *tail;
};

LinkedList flattenTree(Node *root)
{
    // We basically have to return pair. So craeted a class for pair separately above.
    LinkedList l;

    //Base case
    if (root == NULL)
    {
        l.head = l.tail = NULL;
        return l;
    }

    //4 cases posssible

    if (root->left == NULL and root->right == NULL)
    {
        l.head = l.tail = root;
    }
    else if (root->left != NULL and root->right == NULL)
    {
        LinkedList leftLL = flattenTree(root->left);
        leftLL.tail->right = root;

        l.head = leftLL.head;
        l.tail = root;
    }
    else if (root->left == NULL and root->right != NULL)
    {
        LinkedList rightLL = flattenTree(root->right);
        root->right = rightLL.head;

        l.head = root;
        l.tail = rightLL.tail;
    }
    else
    {
        LinkedList leftLL = flattenTree(root->left);
        LinkedList rightLL = flattenTree(root->right);

        leftLL.tail->right = root;
        root->right = rightLL.head;

        l.head = leftLL.head;
        l.tail = rightLL.tail;
    }

    return l;
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    LinkedList ll = flattenTree(root);

    Node *temp = ll.head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->right;
    }

    return 0;
}