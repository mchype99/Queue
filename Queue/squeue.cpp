//******************************************************
//                S Q U E U E  . C P P

#include "squeue.h"
#include "stack.h"
#include <iostream>
using namespace std;

//*************************************************************************************
//Name: Default constructor
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state of the object has been initailized
//Description:   This is the default constructor which will be called automatically when
//               an object is declared. It will initialize the state of the class.
//*************************************************************************************
squeue::squeue()
{
    s1.s_top = NULL;
    s2.s_top = NULL;
}

//*************************************************************************************
//Name: Destructor
//Precondition: s_top is initialized
//Postcondition: Nodes are detroyed
//Description:   Destroys all nodes of both stacks.
//*************************************************************************************
squeue::~squeue()
{
    s1.~stack();
    s2.~stack();
}

//*************************************************************************************
//Name: Print
//Precondition: The stacks s1 and s2 has been initialized
//Postcondition: Display contents of the queue
//Description:   Displays the contents of the queue
//*************************************************************************************
void squeue::print()
{
   if (s1.isEmpty() && s2.isEmpty())
   {
       cout << "Queue is Empty!" << endl;
   }
   else
   {
       s1.print();
   }
}

//*************************************************************************************
//Name: enqueue
//Precondition: Stack s1 has been initialized
//Postcondition: Adds item to stack s1
//Description:   Adds item to queue by pushing item into stack s1
//*************************************************************************************
void squeue::enqueue(int item)
{
    s1.push(item);
}

//*************************************************************************************
//Name: dequeue
//Precondition: stacks s1 and s2 are initialized
//Postcondition: Item from queue gets deleted
//Description: Removes item from queue using both s1 and s2
//*************************************************************************************
void squeue::dequeue()
{
    int x, y;

    if (s1.isEmpty())
    {
        cout << "Underflow!";
        exit(0);
    }

    while (!s1.isEmpty())
    {
        x = s1.pop();
        s2.push(x);
    }

    y = s2.pop();

    while (!s2.isEmpty())
    {
        x = s2.pop();
        s1.push(x);
    }
}

//*************************************************************************************
//Name: Copy constructor
//Precondition: The stacks s1 and s2 has been initialized
//Postcondition: A deep copy of the queue is performed
//Description: Performs a deep copy of a queue
//*************************************************************************************
squeue::squeue(squeue& other)
{
    if (other.s1.s_top == nullptr) return;

    stack_node* dummyHead = new stack_node;
    stack_node* curr = dummyHead;
    stack_node* othcurr = other.s1.s_top;

    for (; othcurr != nullptr; othcurr = othcurr->next)
    {
        curr->next = new stack_node;
        curr = curr->next;
        curr->data = othcurr->data;
        curr->next = nullptr;
    }

    s1.s_top = dummyHead->next;
    delete dummyHead;
}