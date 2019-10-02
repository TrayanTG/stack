#include<iostream>
#include<exception>
using namespace std;

template <typename T>
class Stack
{
    struct Node
    {
        T value;
        Node *next;
        Node(const T &val):value(val), next(nullptr) {}
    };
    Node *start;

    void copyStack(const Node* &);
    void deleteStack();
public:
    Stack();
    Stack(const Stack<T> &other);
    Stack<T>& operator=(const Stack<T> &other);
    ~Stack();

    void push(const T&);
    void pop();
    T top()const;
    bool isEmpty()const;

};

template<typename T>
void Stack<T>::copyStack(const Node* &other)
{
    if(other==nullptr)return;
    copyStack(other->next);
    push(other->value);
}

template<typename T>
void Stack<T>::deleteStack()
{
    while(!isEmpty())pop();
    start=nullptr;
}

template<typename T>
Stack<T>::Stack(): start(nullptr) {}

template<typename T>
Stack<T>::Stack(const Stack<T> &other)
{
    copyStack(other->start);
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T> &other)
{
    if(this == &other) return *this;
    deleteStack();
    copyStack(other->start);
    return *this;
}

template<typename T>
void Stack<T>::push(const T& val)
{
    Node *node = new Node(val);
    node->next = start;
    start = node;
}

template<typename T>
void Stack<T>::pop()
{
    if(isEmpty())return;
    Node *node = start;
    start = start->next;
    delete node;
}

template<typename T>
T Stack<T>::top()const
{
    if(isEmpty())throw std::runtime_error("Stack is empty!");
    return start->value;
}

template<typename T>
bool Stack<T>::isEmpty()const
{
    return start == nullptr;
}

int main()
{

    return 0;
}
