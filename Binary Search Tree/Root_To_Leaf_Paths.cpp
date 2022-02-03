//Basically we will be given root  So we have to print paths for all leaf nodes ,i.e, from root to all leaf nodes.

#include <iostream>
#include <vector>
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

void printPaths(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (root->left == NULL and root->right == NULL)
    {
        for (auto data : ans)
        {
            cout << data << "->";
        }
        //Not pushing leaf node to ans. Just printing at last.
        cout << root->data << endl;
        return;
    }

    ans.push_back(root->data);
    printPaths(root->left, ans);
    printPaths(root->right, ans);

    //Backtracking
    ans.pop_back();
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
    vector<int> ans;

    printPaths(root, ans);

    return 0;
}