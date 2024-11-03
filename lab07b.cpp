#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    Node *right;
    Node *left;
    int data;

    Node(int element) : left(nullptr), right(nullptr), data(element) {}
};

class Tree
{
public:
    Node *root;

    Tree() : root(nullptr) {}

    void insert(int data);
    Node *findDeepestNode(Node *root);
    void deleteDeepestNode(Node *root, Node *deepest_node);
    void remove(int key);
    void display();
};

void Tree::insert(int data)
{
    Node *newnode = new Node(data);

    if (root == nullptr)
    {
        root = newnode;
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->left == nullptr)
        {
            temp->left = newnode;
            break;
        }
        else
        {
            q.push(temp->left);
        }

        if (temp->right == nullptr)
        {
            temp->right = newnode;
            break;
        }
        else
        {
            q.push(temp->right);
        }
    }
}

Node *Tree::findDeepestNode(Node *root)
{
    if (root == nullptr)
        return nullptr;

    queue<Node *> q;
    q.push(root);
    Node *temp = nullptr;

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->left != nullptr)
            q.push(temp->left);
        if (temp->right != nullptr)
            q.push(temp->right);
    }
    return temp;
}

void Tree::deleteDeepestNode(Node *root, Node *deepest_node)
{
    if (root == nullptr || deepest_node == nullptr)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->right)
        {
            if (temp->right == deepest_node)
            {
                delete temp->right;
                temp->right = nullptr;
                return;
            }
            else
            {
                q.push(temp->right);
            }
        }

        if (temp->left)
        {
            if (temp->left == deepest_node)
            {
                delete temp->left;
                temp->left = nullptr;
                return;
            }
            else
            {
                q.push(temp->left);
            }
        }
    }
}

void Tree::remove(int key)
{
    if (root == nullptr)
    {
        cout << "Tree is empty." << endl;
        return;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        if (root->data == key)
        {
            delete root;
            root = nullptr;
        }
        return;
    }

    queue<Node *> q;
    q.push(root);
    Node *key_node = nullptr;
    Node *temp = nullptr;

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->data == key)
            key_node = temp;

        if (temp->left != nullptr)
            q.push(temp->left);

        if (temp->right != nullptr)
            q.push(temp->right);
    }

    if (key_node != nullptr)
    {
        Node *deepest_node = findDeepestNode(root);
        key_node->data = deepest_node->data;
        deleteDeepestNode(root, deepest_node);
    }
}

void Tree::display()
{
    if (root == nullptr)
    {
        cout << "Tree is empty." << endl;
        return;
    }

    queue<Node *> q;
    q.push(root);

    cout << "Tree elements (Level order): ";
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if (temp->left != nullptr)
            q.push(temp->left);
        if (temp->right != nullptr)
            q.push(temp->right);
    }
    cout << endl;
}

int main()
{
    Tree tree;
    int choice, value;

    while (true)
    {
        cout << "\nMenu:\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insert(value);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            tree.remove(value);
            break;
        case 3:
            tree.display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
