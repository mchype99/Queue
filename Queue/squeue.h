//******************************************************
//                S Q U E U E . H

#ifndef SQUEUE_H
#define SQUEUE_H
#include "stack.h"

class squeue : stack
{
public:
    squeue();//default constructor
    ~squeue();//destructor
    squeue(squeue& );//copy constructor
    void enqueue(int);//add element to queue
    void dequeue();//remove elment from the queue
    void print();//print each element in the queue from front to back on a separate line
private:
    stack s1, s2;//stacks use for queue data
};

#endif