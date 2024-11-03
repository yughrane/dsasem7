#include <iostream>
using namespace std;

#define MAX_SIZE 5

class CircularQueue
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

bool CircularQueue::isFull()
{
    return (rear + 1) % MAX_SIZE == front;
}

bool CircularQueue::isEmpty()
{
    return front == -1;
}

void CircularQueue::Enqueue(int element)
{
    if (isFull())
    {
        cout << "Queue Full" << endl;
    }
    else
    {
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = element;
    }
}

void CircularQueue::Dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        cout << "Element removed: " << arr[front] << endl;
        if (front == rear)
        {
            // Queue has become empty
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
    }
}

void CircularQueue::Display()
{
    if (isEmpty())
    {
        cout << "Queue Empty" << endl;
    }
    else
    {
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % MAX_SIZE;
        }
        cout << endl;
    }
}

int main()
{
    int element = 0;
    int num = 0;
    int ch = 0;
    CircularQueue q;

    cout << "Enter the number of digits in the queue: ";
    cin >> num;
    cout << endl;

    while (ch != 4)
    {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose your option: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Please enter the value to be added: ";
            cin >> element;
            q.Enqueue(element);
            break;

        case 2:
            q.Dequeue();
            break;

        case 3:
            cout << "Displaying: ";
            q.Display();
            break;

        case 4:
            cout << "Exiting" << endl;
            break;

        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }

    return 0;
}
