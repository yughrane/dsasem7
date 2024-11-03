#include <iostream>

using namespace std;

class Node
{
public:
    Node *next;
    int data;

    Node(int element) : next(nullptr), data(element) {}
};

class List
{
private:
    Node *head;
    int size;

public:
    List() : head(nullptr), size(0) {}
    void insertStart(int element);
    void insertEnd(int element);
    void insertPos(int element, int pos);
    void deleteStart();
    void deleteEnd();
    void deletePos(int pos);
    void display();
};

void List::insertStart(int element)
{
    Node *newnode = new Node(element);
    if (head == nullptr)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
    size++;
}

void List::insertEnd(int element)
{
    Node *newnode = new Node(element);
    if (head == nullptr)
    {
        head = newnode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    size++;
}

void List::insertPos(int element, int pos)
{
    if (pos < 0 || pos > size)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    Node *newnode = new Node(element);
    if (pos == 0)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    size++;
}

void List::deleteStart()
{
    if (head == nullptr)
    {
        cout << "The List is empty" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    size--;
}

void List::deleteEnd()
{
    if (head == nullptr)
    {
        cout << "The list is empty" << endl;
        return;
    }
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        Node *temp = head;
        Node *prev = nullptr;
        while (temp->next != nullptr)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = nullptr;
        delete temp;
    }
    size--;
}

void List::deletePos(int pos)
{
    if (head == nullptr)
    {
        cout << "The Linked List is empty!!" << endl;
        return;
    }
    if (pos < 0 || pos >= size)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    if (pos == 0)
    {
        deleteStart();
        return;
    }
    Node *temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    Node *todelete = temp->next;
    temp->next = todelete->next;
    delete todelete;
    size--;
}

void List::display()
{
    if (head == nullptr)
    {
        cout << "The Linked List is empty!!" << endl;
    }
    else
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\nThe size of the linked list is " << size << endl;
    }
}

int main()
{
    List list;
    int choice = 0;
    int data = 0;
    int pos = 0;

    while (choice != 4)
    {
        cout << "1. Insert in the single linked list" << endl;
        cout << "2. Delete from the single linked list" << endl;
        cout << "3. Display the single linked list" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter the data to be inserted: ";
            cin >> data;

            cout << "\n1. Insert at the start";
            cout << "\n2. Insert at the end";
            cout << "\n3. Insert at a given position";
            cout << "\nEnter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                list.insertStart(data);
                break;

            case 2:
                list.insertEnd(data);
                break;

            case 3:
                cout << "\nEnter the position: ";
                cin >> pos;
                list.insertPos(data, pos);
                break;

            default:
                cout << "\nInvalid choice!!" << endl;
                break;
            }
            break;

        case 2:
            cout << "\n1. Delete at the start";
            cout << "\n2. Delete at the end";
            cout << "\n3. Delete at a given position";
            cout << "\nEnter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                list.deleteStart();
                break;

            case 2:
                list.deleteEnd();
                break;

            case 3:
                cout << "\nEnter the position: ";
                cin >> pos;
                list.deletePos(pos);
                break;

            default:
                cout << "\nInvalid choice!!" << endl;
                break;
            }
            break;

        case 3:
            list.display();
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
