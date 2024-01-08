#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> Set;
    int process;
    int flag = 0;
    while (flag == 0)
    {
        cout << "***********************\tMANAGER SET***********************\t" << endl;
        cout << "1. Input number in set\t\t"
             << "2. Check exist" << endl;
        cout << "3. Sum number in set\t\t"
             << "4. Exit" << endl;
        cin >> process;
        switch (process)
        {
        case 1:
            // Input number in set
            {
                // User input number in set
                int number;
                cout << "Enter the number in set (enter number negative to exit): ";
                while (true)
                {
                    cin >> number;
                    if (number < 0)
                    {
                        break;
                    }
                    Set.insert(number);
                }

                // Print number in Set
                cout << "Number in Set: ";
                for (auto &n : Set)
                {
                    cout << n << " ";
                }
                cout << endl;
                break;
            }

        case 2:
            // Check number user input exsit in set
            {
                // Check empty Set
                if (Set.size() == 0)
                {
                    cout << "Set is empty number!" << endl;
                    break;
                }

                int numberCheck;
                cout << "Enter number check exist in set: ";
                cin >> numberCheck;
                auto pos = Set.find(numberCheck);
                if (pos != Set.end())
                {
                    cout << numberCheck << " is in set!" << endl;
                }
                else
                {
                    cout << numberCheck << " is not in Set!" << endl;
                }
                break;
            }

        case 3:
            // Calculate sum number in set
            {
                // Check empty Set
                if (Set.size() == 0)
                {
                    cout << "Set is empty number!" << endl;
                    break;
                }

                int sum;
                for (auto &n : Set)
                {
                    sum += n;
                }
                cout << "Sum number in Set: " << sum << endl;
                break;
            }

        case 4:
            // Exit program
            flag = 1;
            break;
        default:
            cout << "Invalid choice please enter number again!" << endl;
        }
    }

    return 0;
}