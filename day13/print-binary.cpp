#include <iostream>
using namespace std;

// Create class Binary Tree
class BinaryTree
{
public:
    int number;
    BinaryTree *left, *right;

    // Constructor
    BinaryTree()
    {
        number = 0;
        left = right = NULL;
    }

    BinaryTree(int &n)
    {
        number = n;
        left = right = NULL;
    }

    // Method add node
    BinaryTree *addNode(BinaryTree *root, int &n)
    {
        // Check empty binary tree
        if (!root)
        {
            return new BinaryTree(n);
        }

        // Check value > root
        if (n > root->number)
        {
            root->right = addNode(root->right, n);
        }

        // Check value < root
        else if (n < root->number)
        {
            root->left = addNode(root->left, n);
        }

        return root;
    }

    // Print binary tree
    void printPreorder(BinaryTree *root)
    {
        if (root == NULL)
            return;

        cout << root->number << " ";

        printPreorder(root->left);

        printPreorder(root->right);
    }
};

int main()
{
    int input;
    BinaryTree tree;
    BinaryTree *root = NULL;

    cout << "Enter numbers (enter a negative number to stop): ";
    while (cin >> input)
    {
        if (input < 0)
            break;

        if (root == NULL)
        {
            root = tree.addNode(root, input);
        }
        else
        {
            tree.addNode(root, input);
        }
    }

    cout << "Number of binary tree: ";
    tree.printPreorder(root);

    return 0;
}