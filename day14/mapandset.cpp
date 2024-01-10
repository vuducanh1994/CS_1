#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

// set
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

// map
void CountingOccurrences(int n, int arr[])
{

    map<int, int> sl_xuat_hien;

    for (int i = 0; i < n; i++)
    {
        sl_xuat_hien[arr[i]]++;
    }

    for (auto i : sl_xuat_hien)
    {
        cout << i.first << " xuất hiện " << i.second << " lần." << endl;
    }
}

void TotalByGroup(int n, int arr[])
{
    map<int, int> summp;

    for (int i = 0; i < n; i++)
    {
        int sum = arr[i] / 5;
        summp[sum]++;
    }

    for (auto i : summp)
    {
        cout << "Nhóm " << i.first + 1 << " có tổng " << i.second << endl;
    }
}

void SimpleDictionary(map<string, string> &tu_dien, string FindWords)
{
    cout << "Nhập từ để tìm: ";
    cin.ignore();
    cin >> FindWords;

    if (tu_dien.find(FindWords) != tu_dien.end())
    {
        cout << "Nghĩa của từ " << FindWords << " là: " << tu_dien[FindWords] << endl;
    }
    else
    {
        cout << "Không tìm thấy từ này." << endl;
    }
}

// input user
void inputVocabulary(map<string, string> &tu_dien)
{
    int n;
    string Newtext, Vocabulary;

    cout << "Nhập số lượng cần thêm từ: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Nhập từ: ";
        cin.ignore();
        cin >> Newtext;

        cout << "Nhập từ định nghĩa: ";
        cin >> Vocabulary;

        tu_dien[Newtext] = Vocabulary;
    }

    cout << "\nBạn đã thêm thành công\n";
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
    int choice, n;
    int arr[100];
    string Newtext, Vocabulary, FindWords;
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

            int n1;

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
        default:
            cout << "Invalid choice. Please enter 1-3." << endl;
            break;
        }
        case 2:
        {
            int n2;

            cout << "\n1. Đếm Số Lần Xuất Hiện\n";
            cout << "2. Tính Tổng Theo Nhóm\n";
            cout << "3. Từ Điển Đơn Giản\n";
            cout << "Enter your : ";
            cin >> n2;
            switch (n2)
            {
            case 1:
                input(n, arr);
                CountingOccurrences(n, arr);
                break;
            case 2:
                input(n, arr);
                TotalByGroup(n, arr);
                break;

            case 3:
            {
                int n3;
                map<string, string> tu_dien; // Create dictionary here

            try_again:
                cout << "1. Thêm từ\n";
                cout << "2. Tìm từ\n";
                cout << "Enter your: ";
                cin >> n3;

                while (n3)
                {
                    switch (n3)
                    {
                    case 1:
                        inputVocabulary(tu_dien);
                        goto try_again;
                    case 2:
                        SimpleDictionary(tu_dien, FindWords);
                        break;
                    default:
                        cout << "Invalid choice. Please enter 1-2." << endl;
                        break;
                    }
                }
            }
            default:
                cout << "Invalid choice. Please enter 1-3." << endl;
                break;
            }
        }
        case 3:
            cout << "Bạn đã thoát chương trình ";
            return 0;
        }

    } while (choice != 3);

    return 0;
}