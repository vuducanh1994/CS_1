#include <iostream>
#include <set>
#include <map>
using namespace std;

void RemoveDuplicateSet(int n, int arr[])
{

    set<int> number;
    for (int i = 0; i < n; i++)
    {
        number.insert(arr[i]);
    }
    cout << "Kết quả : ";
    for (int numbers : number)
    {
        cout << numbers << " ";
    }
}
void ExistenceCheck(int n, int arr[])
{

    int x;
    cout << "Nhập số để kiểm tra : ";
    cin >> x;

    set<int> number;
    for (int i = 0; i < n; i++)
    {
        number.insert(arr[i]);
    }

    if (number.find(x) != number.end())
    {
        cout << "Số nguyên tồn tại trong dãy" << endl;
    }
    else
    {
        cout << "Số nguyên không tồn tại trong dãy" << endl;
    }
}
void SumSet(int n, int arr[])
{

    set<int> number;
    for (int i = 0; i < n; i++)
    {
        number.insert(arr[i]);
    }

    int sum = 0;
    for (int numbers : number)
    {
        sum += numbers;
    }

    cout << "Tổng của dãy : " << sum << endl;
}
void input(int &n, int arr[])
{

    cout << "Nhập số lượng phần tử : ";
    cin >> n;

    cout << "Nhập dãy số nguyên : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\nSet and Map\n";
        cout << "1. Set\n";
        cout << "2. Map\n";
        cout << "3. Exits\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {

            int n, n1;
            int arr[100];
            cout << "\n1. Loại bỏ các phần tử trùng lặp và in ra dãy số mới\n";
            cout << "2. Kiểm Tra Tồn Tại\n";
            cout << "3. Tính Tổng\n";
            cout << "Enter your : ";
            cin >> n1;

            switch (n1)
            {
            case 1:
                input(n, arr);
                RemoveDuplicateSet(n, arr);
                break;
            case 2:
                input(n, arr);
                ExistenceCheck(n, arr);
                break;
            case 3:
                input(n, arr);
                SumSet(n, arr);
            }
            break;
        }
        case 2:
        {
        }
        case 3:
            cout << "Bạn đã thoát chương trình ";
            return 0;
        }
    } while (choice != 3);

    return 0;
}