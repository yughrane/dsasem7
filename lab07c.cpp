#include <iostream>

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
    void preorder(Node *root);  // Preorder traversal (DFS)
    void inorder(Node *root);   // Inorder traversal (DFS)
    void postorder(Node *root); // Postorder traversal (DFS)
    void displayDFS();          // Function to display all three traversals
};

void Tree::insert(int data)
{
    Node *newnode = new Node(data);

    if (root == nullptr)
    {
        root = newnode;
        return;
    }

    Node *temp = root;
    Node *parent = nullptr;

    // Traverse the tree to find the appropriate place for the new node
    while (temp != nullptr)
    {
        parent = temp;
        if (data < temp->data)
            temp = temp->left; // Go to left subtree
        else
            temp = temp->right; // Go to right subtree
    }

    // Insert the new node in the correct position
    if (data < parent->data)
        parent->left = newnode;
    else
        parent->right = newnode;
}

// Preorder traversal: Root -> Left -> Right
void Tree::preorder(Node *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " "; // Visit root node
    preorder(root->left);      // Traverse left subtree
    preorder(root->right);     // Traverse right subtree
}

// Inorder traversal: Left -> Root -> Right
void Tree::inorder(Node *root)
{
    if (root == nullptr)
        return;

    inorder(root->left);       // Traverse left subtree
    cout << root->data << " "; // Visit root node
    inorder(root->right);      // Traverse right subtree
}

// Postorder traversal: Left -> Right -> Root
void Tree::postorder(Node *root)
{
    if (root == nullptr)
        return;

    postorder(root->left);     // Traverse left subtree
    postorder(root->right);    // Traverse right subtree
    cout << root->data << " "; // Visit root node
}

// Function to display all three DFS traversals
void Tree::displayDFS()
{
    cout << "\nDFS Traversals:\n";
    cout << "Preorder: ";
    preorder(root);
    cout << "\nInorder: ";
    inorder(root);
    cout << "\nPostorder: ";
    postorder(root);
    cout << endl;
}

int main()
{
    Tree tree;
    int choice, value;

    while (true)
    {
        cout << "\nMenu:\n1. Insert\n2. Display DFS (Preorder, Inorder, Postorder)\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insert(value);
            break;
        case 2:
            tree.displayDFS();
            break;
        case 3:
            exit(0);
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
