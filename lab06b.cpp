#include <iostream>

using namespace std;

class Node
{
public:
    Node *next;
    int data;

    Node(int elem) : data(elem), next(nullptr) {}
};

class Stck
{
private:
    int size = 0;
    Node *head;

public:
    Stck() : head(nullptr), size(0) {}
    ~Stck();
    void push(int elem);
    void pop();
    void peek();
};

Stck::~Stck()
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void Stck::push(int val)
{
    Node *newnode = new Node(val);
    if (head == nullptr)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
    size += 1;
}

void Stck::pop()
{
    if (size == 0)
    {
        cout << endl
             << "Stack is empty";
    }
    else
    {
        Node *temp = head;
        head = head->next;
        cout << endl
             << "Element Popped: " << temp->data;
        delete temp;
        size -= 1;
    }
}

void Stck::peek()
{
    if (size == 0)
    {
        cout << endl
             << "Stack is empty";
    }
    else
    {
        cout << endl
             << "Element at the top: " << head->data;
    }
}

int main()
{
    Stck Stack;
    int choice = 0;
    int data = 0;

    while (choice != 4)
    {
        cout << "\n1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter the data to be inserted: ";
            cin >> data;
            Stack.push(data);
            break;

        case 2:
            Stack.pop();
            break;

        case 3:
            Stack.peek();
            break;

        case 4:
            break;

        default:
            cout << "\nInvalid choice!!" << endl;
            break;
        }
    }

    return 0;
}
