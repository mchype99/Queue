//******************************************************
//                S Q U E U E _ D R I V E R . C P P

/*******************************************************************************************************************************
Name: McKerlton Hyppolite    Z#: Z23590874
Course: Data Structures and Algorithm Analysis (COP3530) Professor: Dr. Lofton Bullard
Due Date: 07/06/2021    Due Time: 11:59
Total Points: 25    Assignment: Module 8 Programming Assignment   Date: 07/04/2021

Description: Program that implements a queue using two stacks.
********************************************************************************************************************************/

#include<iostream>
#include "squeue.h"
#include "stack.h"
using namespace std;

int main()
{
    squeue k;
    
    k.enqueue(60);
    k.print();
    k.enqueue(20);
    k.enqueue(30);
    k.print();
    k.enqueue(10);
    k.print();
    k.enqueue(50);
    k.enqueue(40);
    k.print();
    
    squeue j = k;

    j.dequeue();
    j.print();
    j.dequeue();
    j.dequeue();
    j.dequeue();
    j.print();
    j.dequeue();
    j.dequeue();
    j.print();
    j.dequeue();
    j.dequeue();
    
    return 0;
}
