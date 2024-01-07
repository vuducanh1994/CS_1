#include <iostream>
using namespace std;

// Create class stack
class Stack
{
public:
    int node[100];

    // Constructor
    Stack()
    {
        for (int i = 0; i < 100; i++)
        {
            node[i] = NULL;
        }
    }

    // Method check empty
    bool isEmpty()
    {
        if (node[0] == NULL)
        {
            cout << "Stack is empty" << endl;
            return true;
        }
        cout << "Stack is not empty" << endl;
        return false;
    }

    // Method print
    void printStack()
    {
        if (this->isEmpty())
        {
            return;
        }

        cout << "Stack node: ";
        for (int i = 0; i < 100; i++)
        {
            if (node[i] == NULL)
            {
                break;
            }
            cout << node[i] << " ";
        }
        cout << endl;
    }

    // Method push
    void push(int &n)
    {
        for (int i = 0; i < 100; i++)
        {
            if (node[i] == NULL)
            {
                node[i] = n;
                cout << "Push " << n << " is successfully!" << endl;
                return;
            }
        }
    }

    // Method pop
    void pop()
    {
        if (isEmpty())
        {
            return;
        }

        for (int i = 0; i < 100; i++)
        {
            if (node[i] == NULL)
            {
                cout << "Pop " << node[i - 1] << " is successfully!" << endl;
                node[i - 1] = NULL;
                return;
            }
        }
    }
};

int main()
{
    Stack stack;
    int process;
    int flag = 0;
    while (flag == 0)
    {
        cout << "***************\tCHECK STACK PROCESS***************\t" << endl;
        cout << "1. Check empty stack\t\t"
             << "2. Print stack" << endl;
        cout << "3. Push node in stack\t\t"
             << "4. Pop node from stack" << endl;
        cout << "5. Exit" << endl;
        cin >> process;
        switch (process)
        {
        case 1:
            stack.isEmpty();
            break;
        case 2:
            stack.printStack();
            break;
        case 3:
        {
            cout << "Enter number push in stack: ";
            int n;
            cin >> n;
            stack.push(n);
            break;
        }

        case 4:
            stack.pop();
            break;
        case 5:
            flag = 1;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
