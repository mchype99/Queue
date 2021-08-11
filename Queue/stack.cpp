//******************************************************
//                S T A C K . C P P

#include "stack.h"
#include <iostream>
#include<string>

//*************************************************************************************
//Name: Default constructor
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state of the object has been initailized
//Description:   This is the default constructor which will be called automatically when
//               an object is declared. It will initialize the state of the class.
//*************************************************************************************
stack::stack()
{
    s_top = NULL;
}

//*************************************************************************************
//Name: Explicit-value constructor
//Precondition: 
//Postcondition:
//Description:
//*************************************************************************************
stack::stack(const stack& Org)
{
      
    cout << "Inside the Copy Constructor\n";

    if (Org.s_top == nullptr) return;
    stack_node* dummyHead = new stack_node;
    stack_node* curr = dummyHead;
    stack_node* othcurr = Org.s_top;
    for (; othcurr != nullptr; othcurr = othcurr->next)
    {
        curr->next = new stack_node;
        curr = curr->next;
        curr->data = othcurr->data;
        curr->next = nullptr;
    }
    s_top = dummyHead->next;
    delete dummyHead;
}

//*************************************************************************************
//Name: Destructor
//Precondition: List is initialized.
//Postcondition: Memory for list is de-allocated.
//Description: De-allocates all memory allocated for the list.
//*************************************************************************************
stack::~stack()
{
    while (s_top != NULL)
    {
        pop();
    }
}

//*************************************************************************************
//Name: pop()
//Precondition: Stack is initialized
//Postcondition: Value at top of stack has been removed
//Description: Remove value at top of stack
//*************************************************************************************
int stack::pop()
{
    stack_node* p;
    int s = 0 ;
    if (s_top != NULL)
    {
        p = s_top;
        s = p->data;
        s_top = s_top->next;
        delete p;
    }
    return s;
}

//*************************************************************************************
//Name: push()
//Precondition: value is to be added to stack
//Postcondition: value is added at top of stack
//Description: Add value to a stack
//*************************************************************************************
void stack::push(const stack_element& value)
{
    stack_node* p = new stack_node;
    p->data = value;
    p->next = s_top;
    s_top = p;
}

//*************************************************************************************
//Name: top()
//Precondition: Stack is initialized
//Postcondition: Value at top of stack is returned
//Description: Retrieve value at top of stack
//*************************************************************************************
stack_element stack::top()
{
    if (s_top == NULL)
    {
        exit(0);
    }
    else
    {
        return s_top->data;
    }
}

//*************************************************************************************
//Name: isEmpty()
//Precondition: None
//Postcondition: Returns true if stack is empty and false otherwise
//Description: Check if stack is empty
//*************************************************************************************
bool stack::isEmpty()
{
    if (s_top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//*************************************************************************************
//Name: size()
//Precondition: Stack is initialzed
//Postcondition: Return size of stack
//Description: Returns the size of the stack
//*************************************************************************************
int stack::size()
{
    int s = 0;
    for (stack_node* p = s_top; p != NULL; p = p->next)
    {
        s++;
    }
    return s;
}

//*************************************************************************************
//Name: Print
//Precondition: The stack has been initialized
//Postcondition: Display contents of the stack
//Description:   Displays the contents of the stack
//*************************************************************************************
void stack::print()
{
    stack_node* p = s_top;
    while (p != NULL)
    {
        // Print node data
        cout << p->data << endl;

        // Assign temp link to temp
        p = p->next;
    }
    cout << endl;
}
