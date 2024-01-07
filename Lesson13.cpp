// Lesson 1,2
#include <iostream>
using namespace std;

struct BinaryTree
{
    int key;
    BinaryTree *left, *right;

    BinaryTree(int key)
    {
        this->key = key;
        left = right = NULL;
    }
};

void insert(BinaryTree *root, int x)
{

    if (root == NULL)
        return;
    else if (root->key == x)
        return;

    if (root->left == NULL && root->key > x)
        root->left = new BinaryTree(x);
    else if (root->right == NULL && root->key < x)
        root->right = new BinaryTree(x);
    else if (root->key > x)
        insert(root->left, x);
    else
        insert(root->right, x);
}
// hàm Search cây
bool search(BinaryTree *root, int key)
{
    if (root == nullptr)
        return false;

    if (root->key == key)
        return true;

    if (key < root->key)
        return search(root->left, key);

    return search(root->right, key);
}

BinaryTree *insert_iterative(BinaryTree *root, int x)
{
    BinaryTree *temp = new BinaryTree(x);

    BinaryTree *parent = NULL, *cur = root; // biến để theo dõi nút cha và nút hiện tại trong quá trình duyệt

    // Duyệt cây để tìm vị trí chèn thích hợp
    while (cur != NULL)
    {
        parent = cur;

        if (cur->key > x) // Di chuyển sang trái nếu giá trị x nhỏ hơn giá trị nút hiện tại
            cur = cur->left;
        else if (cur->key < x) // Di chuyển sang phải nếu giá trị x lớn hơn giá trị nút hiện tại
            cur = cur->right;
        else // Nếu giá trị x đã tồn tại, không cần chèn
            return root;
    }

    if (parent == NULL)
        return temp;
    if (parent->key > x)
        parent->left = temp;
    else
        parent->right = temp;

    return root;
}

BinaryTree *get_successor(BinaryTree *cur) // tìm nút kế tiếp theo thứ tự của một nút
{
    cur = cur->right;

    while (cur != NULL && cur->left != NULL)
        cur = cur->left;

    return cur;
}

BinaryTree *del_node(BinaryTree *root, int x)
{
    if (root == NULL) // check Empty
        return root;

    if (root->key > x) // root->key > x, nút cần xóa nằm ở cây con bên trái
        root->left = del_node(root->left, x);
    else if (root->key < x) // root->key < x, nút cần xóa nằm ở cây con bên phải
        root->left = del_node(root->right, x);
    else
    {
        if (root->left == NULL) // Nếu root->left == NULL, nghĩa là root chỉ có con bên phải, hàm thay thế root bằng con bên phải của nó và xóa root.
        {
            BinaryTree *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) //  tương tự đảo ngược trường hợp trêntrên
        {
            BinaryTree *temp = root->left;
            delete root;
            return temp;
        }
        else // ttrường hợp 2: root có cả hai con
        {
            // sao chép giá trị của succ vào root rồi đệ quy del_node(root->right, succ->key)
            BinaryTree *succ = get_successor(root);
            root->key = succ->key;
            root->right = del_node(root->right, succ->key);
        }
    }

    return root; // nút gốc cập nhật
}

// Hàm in cây theo phương pháp inorder
void print_inorder(BinaryTree *root)
{
    if (root != NULL)
    {
        print_inorder(root->left);
        cout << root->key << " ";
        print_inorder(root->right);
    }
}

int main()
{
    BinaryTree *root = nullptr; // key root phải rỗng

    int choice, key;
    do
    {
        cout << "\nBinaryTree\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. PrintInorder\n";
        cout << "4. Delete\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "nhập cây: ";
            cin >> key;
            root = insert_iterative(root, key);
            cout << "cây đã được chèn \n";
            break;
        case 2:
            cout << "nhập cây để tìm kiếm : ";
            cin >> key;
            if (search(root, key))
            {
                cout << "Đã tìm thấy key\n";
            }
            else
            {
                cout << "key rỗng\n";
            }
            break;
        case 3:
            cout << "Duyệt cây theo phương thức inorder: ";

            print_inorder(root);
            cout << endl;
            break;
        case 4:
            cout << "nhập để xóa: ";
            cin >> key;
            root = del_node(root, key);
            cout << "cây đã được xóa\n";
            break;
        case 5:
            cout << "Bạn đã thoát chương trình ";
            return 0;
        }
    } while (choice != 5);

    return 0;
}
