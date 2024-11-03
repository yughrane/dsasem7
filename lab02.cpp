// Write a program in C++ to perform stack operations:
// i.	Push, pop, peek, isEmpty(), isFull()
// ii.	To sort data in stack using recursion ( Do not use secondary stack


#include<iostream>
#include<string>

using namespace std;

class Stack {

    public:
    static const int MAX_SIZE = 100; //Maximum size of the array
    int stackarr[MAX_SIZE]; //defining the stack to be implemented as the array
    int top; //the topmost index of the stack

    Stack(); //constructor
    void push(int element); //pushes an element onto the stack
    int pop(); //pops the topmost element
    int peek(); //returns the topmost element from the stack
    bool isEmpty(); //checks if the stack is empty, i.e., if it's in the underflow state
    bool isFull(); //checks if the stack is full, i.e., if it's in the overflow state
    int get(int index); //returns an element from the specified position
    int topindex();
    void sortedInsert(int element);
    void sortStack();
};

Stack::Stack() {
    top=-1;
}

bool Stack::isEmpty() {
    return (top==-1);
}

bool Stack::isFull() {
    return (top==MAX_SIZE-1);
}

void Stack::push(int element) {
    if(isFull())
    {
        cout<<"Stack is in Overflow!";
        return;
    }
    stackarr[++top] = element;
}

int Stack::pop() {
    if (isEmpty())
    {
        cout<<"Stack is in Underflow!";
        return -1;
    }
    return stackarr[top--];
}

int Stack::peek() {
    if(isEmpty())
    {
        cout<<"Stack is in Underflow!";
        return -1;
    }
    return stackarr[top];
}

int Stack::get(int index) {
    if(isEmpty())
    {
        cout<<"Stack is in Underflow!";
        return -1;
    }
    return stackarr[index];
}


int Stack::topindex() {
    return top;
}

void Stack::sortedInsert(int element) {
    if (isEmpty() || element > peek()) {
        push(element);
        return;
    }

    int temp = pop();
    sortedInsert(element);
    push(temp);
}

void Stack::sortStack() {
    if (!isEmpty()) {
        int temp = pop();
        sortStack();
        sortedInsert(temp);
    }
}

int main() {
    Stack stack;
    int choice, element;

    do {
        cout << "\nStack Operations Menu:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Check if Empty" << endl;
        cout << "5. Check if Full" << endl;
        cout << "6. Sort Stack" << endl;
        cout << "7. Display Stack" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice (1-8): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter an element to push: ";
                cin >> element;
                stack.push(element);
                break;
            case 2:
                cout << "Popped element: " << stack.pop() << endl;
                break;
            case 3:
                cout << "Top element: " << stack.peek() << endl;
                break;
            case 4:
                cout << (stack.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
                break;
            case 5:
                cout << (stack.isFull() ? "Stack is full." : "Stack is not full.") << endl;
                break;
            case 6:
                stack.sortStack();
                cout << "Stack sorted." << endl;
                break;
            case 7:
                cout << "Elements in the stack: ";
                for (int i = stack.topindex(); i >= 0; i--) {
                    cout << stack.get(i) << " ";
                }
                cout << endl;
                break;
            case 8:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 8);

    return 0;
}