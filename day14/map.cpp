#include <iostream>
#include <map>
using namespace std;

int main()
{
    int process;
    int flag = 0;
    while (flag == 0)
    {
        cout << "*****************************************MANAGER MAP*****************************************" << endl;
        cout << "1. Input string and count char in string\t\t"
             << "2. Input integer in map and sum element" << endl;
        cout << "3. Dictionary from map\t\t\t\t\t"
             << "4. Exit" << endl;
        cin >> process;
        switch (process)
        {
        case 1:
            // Input string and count char in string
            {
                string str;
                map<char, int> mp;
                cout << "Enter string in map: ";
                cin >> str;

                // Create map
                for (char &c : str)
                {
                    if (mp.find(c) != mp.end())
                    {
                        mp[c] = mp[c] + 1;
                    }
                    else
                    {
                        mp[c] = 1;
                    }
                }

                // Iterator map
                for (auto itr = mp.begin(); itr != mp.end(); itr++)
                {
                    cout << "Count character " << itr->first << " is: " << itr->second << endl;
                }
                break;
            }

        case 2:
            // Input integer in map and sum element
            {
                // Create map
                map<int, int> mp;
                int number = 0;
                cout << "Enter number integer (enter negative to exit): ";
                while (number >= 0)
                {
                    cin >> number;
                    mp[number] = number;
                }

                // Calculate sum number in map mod 5 = 0
                int sum = 0;
                for (auto itr = mp.begin(); itr != mp.end(); itr++)
                {
                    if (itr->first % 5 == 0)
                    {
                        sum += itr->second;
                    }
                }

                cout << "Sum number mod 5 == 0 in map is: " << sum << endl;
                break;
            }

        case 3:
            //  Dictionary from map
            {
                map<string, string> mp;
                int process1;
                int flag1 = 0;
                while (flag1 == 0)
                {
                    cout << "1. Enter word and definition\t"
                         << "2. Input word and print definition\t"
                         << "3. Exit" << endl;
                    cin >> process1;
                    switch (process1)
                    {
                    // Enter word and definition
                    case 1:
                    {
                        string word = "";
                        string definition = "";

                        // Input word
                        cout << "Enter word: ";
                        cin.ignore();
                        getline(cin, word);

                        // Input definition
                        cout << "Enter definition: ";
                        getline(cin, definition);
                        mp[word] = definition;

                        break;
                    }

                    case 2:
                        // Input word and print definition
                        {
                            string word = "";
                            cout << "Enter word wants translate: ";
                            cin.ignore();
                            getline(cin, word);
                            if (mp.find(word) != mp.end())
                            {
                                cout << word << " definition: " << mp[word] << endl;
                            }
                            else
                            {
                                cout << word << " is not in dictionary!" << endl;
                            }
                            break;
                        }

                    case 3:
                        flag1 = 1;
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                    }
                }
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