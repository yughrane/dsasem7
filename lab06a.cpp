#include <iostream>

using namespace std;

class Node
{
public:
    Node *next;
    int data;

public:
    Node(int element) : next(nullptr), data(element) {}
};

class Queue
{
private:
    Node *front;
    Node *rear;
    int size;

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}
    ~Queue();
    void Enqueue(int data);
    void Dequeue();
    void Display();
};

// Destructor to free up the memory used by the queue
Queue::~Queue()
{
    while (front != nullptr)
    {
        Node *temp = front;
        front = front->next;
        delete temp;
    }
}

void Queue::Enqueue(int data)
{
    Node *newnode = new Node(data);
    if (front == nullptr)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
    size += 1;
}

void Queue::Dequeue()
{
    if (front == nullptr)
    {
        cout << "The Queue is empty" << endl;
        return;
    }

    cout << "Deleted element: " << front->data << endl;
    Node *temp = front;
    front = front->next;
    delete temp;

    // If the queue becomes empty, set rear to nullptr
    if (front == nullptr)
    {
        rear = nullptr;
    }

    size -= 1;
}

void Queue::Display()
{
    if (front == nullptr)
    {
        cout << "The Queue is empty" << endl;
    }
    else
    {
        Node *temp = front;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
    Queue Queue;
    int choice = 0;
    int data = 0;

    while (choice != 4)
    {
        cout << "\n1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter the data to be inserted: ";
            cin >> data;
            Queue.Enqueue(data);
            break;

        case 2:
            Queue.Dequeue();
            break;

        case 3:
            Queue.Display();
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
