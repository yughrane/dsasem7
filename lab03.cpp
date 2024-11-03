#include <iostream>
#include <string>

using namespace std;

#define MAX_SIZE 100

class Stack
{
private:
    char arr[MAX_SIZE];
    int top = -1;

public:
    void push(char data);
    void pop();
    void peek();
    void check(char element);
    bool isFull();
    bool isEmpty();
};

bool Stack::isFull()
{
    return (top == MAX_SIZE - 1);
}

bool Stack::isEmpty()
{
    return (top < 0);
}

void Stack::push(char data)
{
    top++;
    arr[top] = data;
}

void Stack::pop()
{
    top--;
}

void Stack::peek()
{
    cout << "Element at the top: " << arr[top] << endl;
}

void Stack::check(char element)
{
    if(arr[top] == '(' && element == ')')
        pop();
    else if(arr[top] == '{' && element == '}')
        pop();
    else if(arr[top] == '[' && element == ']')
        pop();
}

int main()
{
    Stack s;
    string input;
    int size = 0;
    int ch = 0;

    cout << "Enter the sentence: ";
    cin >> input;

    size = input.size();

    for(int i = 0; i < size; i++)
    {
        if(input[i] == '(' || input[i] == '{' || input[i] == '[')
        {
            s.push(input[i]);
        }
        else if(input[i] == ')' || input[i] == '}' || input[i] == ']')
        {
            s.check(input[i]);
        }
        else
            continue;
    }


    if(!s.isEmpty())
        cout << endl << "There is an open bracket";
    else if(s.isEmpty())
        cout << endl << "All brackets closed properly";
    else
        cout << endl << "Error";
}
