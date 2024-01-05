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

    // Search value in binary tree
    void searchValue(BinaryTree *root, int &value)
    {
        // Check binary tree empty
        if (root == NULL)
        {
            cout << value << " is not in binary tree" << endl;
            return;
        }

        // Check value = root
        if (value == root->number)
        {
            cout << value << " is in binary tree" << endl;
            return;
        }

        // Check value > root
        else if (value > root->number)
        {
            searchValue(root->right, value);
        }
        else
        {
            searchValue(root->left, value);
        }
    }
};

int main()
{
    int process;
    int flag = 0;
    int input;
    BinaryTree tree;
    BinaryTree *root = NULL;

    while (flag == 0)
    {
        cout << "*******************************\tENTER NUMBER TO CHECK HOMEWORK*******************************\t" << endl;
        cout << "1. Build binary tree\t\t"
             << "2. Search value in binary tree\t\t"
             << "3. Exit" << endl;
        cin >> process;
        switch (process)
        {
        case 1:
        {
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
            break;
        }
        case 2:
        {
            // Check search value into user
            cout << "Enter number search in binary tree: ";
            int value;
            cin >> value;
            tree.searchValue(root, value);
            break;
        }
        case 3:
            flag = 1;
            break;
        default:
            cout << "Invalid number to choice " << endl;
        }
    }

    return 0;
}