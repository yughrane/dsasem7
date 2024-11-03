#include <iostream>

using namespace std;

#define MAX_SIZE 100

class Queue
{
private:
    int arr[MAX_SIZE];
    int front = -1;
    int rear = -1;

public:
    void Enqueue(int element);
    void Dequeue();
    void Display();
    bool isFull();
    bool isEmpty();
};

bool Queue::isFull()
{
    return rear == MAX_SIZE - 1;
}

bool Queue::isEmpty()
{
    return rear == -1 && front == -1;
}

void Queue::Enqueue(int element)
{
    if (isEmpty())
    {
        front = rear = 0;
    }
    if (isFull())
    {
        cout << endl
             << "Queue Full";
    }
    else
    {
        arr[rear] = element;
        rear += 1;
    }
}

void Queue::Dequeue()
{
    if (isEmpty())
    {
        cout << endl
             << "Queue is Empty";
    }
    else
    {
        cout << "Element removed: " << arr[front] << endl;
        front += 1;
    }
}

void Queue::Display()
{
    if (isEmpty())
    {
        cout << endl
             << "Queue Empty";
    }
    else
    {
        for (int i = front; i < rear; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int element = 0;
    int num = 0;
    int ch = 0;
    Queue q;

    cout << "Enter the number of digits in the queue: ";
    cin >> num;
    cout << endl;

    while (ch != 4)
    {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "Choose your option: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\nPlease enter the value to be added: ";
            cin >> element;

            q.Enqueue(element);
            break;

        case 2:
            q.Dequeue();
            break;

        case 3:
            cout << "\nDisplaying: ";

            q.Display();
            break;

        default:
            cout << "\nInvalid Choice";
        }
    }
}
