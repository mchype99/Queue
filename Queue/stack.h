//******************************************************
//                S T A C K . H

#ifndef STACK_H
#define STACK_H
#include <string>
using namespace std;

typedef int stack_element;

class stack_node
{
public:
    stack_element data;
    stack_node* next;
};

class stack
{
public:
    stack();//Default constructor
    ~stack();//Destructor
    stack(const stack&);//Copy constrcutor
    stack_element top();//Retrieve value at top of stack (if any).
    int pop();//Remove value at top of stack (if any).
    void push(const stack_element&);//Add a value to a stack.
    void print();//display items of a stack
    bool isEmpty();//Checks if stack is empty
    int size();//Checks for stack size
private:
    stack_node* s_top;
    friend class squeue;//friend squeue class with stack class
};

#endif
