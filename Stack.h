#include <iostream>
#include <vector>
#ifndef STACK_H
#define STACK_H

class Node
{
private:
    double Operand;
    char Operator;

public:
    Node *next;

    Node()
    {
        next = nullptr;
    }

    Node(double _Operand) //Data for an Operand being pushed onto the Stack.
    {
        next = nullptr;
        Operand = _Operand;
        Operator = 'F';
    }

    Node(char _Operator) //Data for an Operator being pushed onto the Stack.
    {
        next = nullptr;
        Operator = _Operator;
    }

    ~Node() //Destructor Called whenever Node objects are deleted.
    {
        
    }

    void setOperand(double operandArg)
    {
        Operand = operandArg;
    }

    void setOperator(char operatorArg)
    {
        Operator = operatorArg;
    }
    double getOperand()
    {
        return Operand;
    }

    char getOperator()
    {
        return Operator;
    }
};

class Stack : public Node
{
    uint64_t size;
    size_t maxCapacity;
    Node *topOfStack;

public:
    Stack();
    ~Stack();
    void Clear();
    bool isEmpty();
    void pushOperator(char);
    void pushOperand(double);
    char getOperator();
    uint64_t getSize();
    void pop();
    void top();
    double evaluate(); //Passing 2 Operands and Operator.
    void setCapacity(size_t capacity);
    size_t getCapacity();
};


#endif