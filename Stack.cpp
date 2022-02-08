#include "Stack.h"
#define STACK_H
Stack::Stack() //Default Constructor, goes unused.
{
    topOfStack = nullptr;
    maxCapacity = 0;
    size = 0;
}

Stack::~Stack() //Destructor for the Stack. Lets the user know when it is empty.
{
    while (topOfStack != nullptr)
    {
        Stack::pop();
    }
}

void Stack::Clear() //Function to manually clear the Stack.
{
    while (isEmpty() == false)
    {
        Stack::pop();
    }
}

bool Stack::isEmpty() //Checks to see if the Stack is empty.
{
    if (topOfStack == nullptr)
    {
        return true;
    }
    else
        return false;
}

void Stack::pushOperator(char Arg) //Pushes an Operator onto the Stack as a Char.
{
    if (size == maxCapacity) //Checks to see if the user is attempting to push the Stack over capacity.
    {
        std::cout << "The Stack is at capacity when adding an operator, and cannot accept more elements. Returning to Main Function." << std::endl;
        return;
    }
    if (topOfStack == nullptr)
    {
        topOfStack = new Node(Arg);
    }
    else
    {
        Node *nodeData = new Node(Arg); //Creates a new node with the provided data
        nodeData->setOperator(Arg);     //Sets the Operand to the provided data.
        nodeData->next = topOfStack;    //Sets the new node's next pointer equal to the current top of the stack.
        topOfStack = nodeData;          //Sets the top of the stack equal to the new pointer.
        size++;
    }
}

void Stack::pushOperand(double Arg) //Pushes an Operand onto the Stack as a Double.
{

    if (size == maxCapacity) //Checks to see if the user is attempting to push the Stack over capacity.
    {
        std::cout << "The Stack is at capacity when adding an operand, and cannot accept more elements. Returning to Main Function." << std::endl;
        return;
    }
    if (topOfStack == nullptr)
    {
        topOfStack = new Node(Arg);
    }
    else
    {
        Node *nodeData = new Node(Arg); //Creates a new node with the provided data
        nodeData->setOperand(Arg);      //Sets the Operand to the provided data.
        nodeData->next = topOfStack;    //Sets the new node's next pointer equal to the current top of the stack.
        topOfStack = nodeData;          //Sets the top of the stack equal to the new pointer.
        size++;
    }
}

void Stack::pop()
{ //Redirects topOfStack to next, deletes the top of the stack,.
    if (isEmpty() == false)
    {
        Node *nodeToBeDeleted = topOfStack;
        if (topOfStack->next == nullptr) //deletes the final element of the Stack if there is only one element.
        {
            topOfStack = nullptr;
            delete nodeToBeDeleted;
            size--;
            return;
        }
        topOfStack = topOfStack->next;
        delete nodeToBeDeleted;
        size--;
        return;                                                                                                                                    //while Operators are printed in single quotes.
    }
    else
    {
        std::cout << "Attempting to pop an empty stack. " << std::endl;
        return;
    }
}

void Stack::top() //Prints the top of the Stack.
{ //
    std::cout << "Top Function Called" << std::endl;
    if (topOfStack->getOperator() == 'F')
    { //Test a sentinel value to determine whether to retrieve Operand or Operator.
        std::cout << "The top of the Stack in the TOP FUNCTION is an Operand: " << topOfStack->getOperand() << std::endl;
        return;
    }
    else
        std::cout << "The top of the Stack in the TOP FUNCTION is an Operator: " << topOfStack->getOperator() << std::endl;
        return;
}

uint64_t Stack::getSize() //Returns the size of the Stack.
{
    return size;
}

void Stack::setCapacity(size_t capacity) //Sets the Maximum Capacity of the Stack.
{
    maxCapacity = capacity;
}

size_t Stack::getCapacity() //Returns maxCapacity, used in checking if user attempts to push a node on a full Stack.
{
    return maxCapacity;
}

double Stack::evaluate() //Evaluates Operands and Operators on the Stack until Stack is Empty.
{
    double Solution;
    
    double Operand1 = topOfStack->getOperand(); //Sets Operands and Operators from the top of the Stack downwards.
    Stack::pop();
    double Operand2 = topOfStack->getOperand();
    Stack::pop();
	char Operator = topOfStack->getOperator();
    Stack::pop();

    if (Operator == '+') //Adding Two Operands Together
    { 

        Solution = Operand1 + Operand2; //Addition Step
        if (Stack::isEmpty() == false)
        {
            Stack::pushOperand(Solution);
            Solution = evaluate();
			std::cout << Solution << std::endl;
        }
        return Solution;
    }

    else if (Operator == '-') //Subtracting Two Operands
    {                                                             
        Solution = Operand1 - Operand2; //Subtraction Step
        if (Stack::isEmpty() == false)
        {
            Stack::pushOperand(Solution);
            Solution = evaluate();
			std::cout << Solution << std::endl;
        }
        return Solution;
    }
    else if (Operator == '*') //Multiplying Two Operands
    { 

        Solution = Operand1 * Operand2; //Multiplication Step
        if (Stack::isEmpty() == false)
        {
            Stack::pushOperand(Solution);
            Solution = evaluate();
			std::cout << Solution << std::endl;
        }
        return Solution;
    }
    else if (Operator == '/') //Dividing Two Operands
    { 

        Solution = Operand1 / Operand2; //Division Step

        if (Stack::isEmpty() == false)
        {
            Stack::pushOperand(Solution);
            Solution = evaluate();
			std::cout << Solution << std::endl;
        }
        
        return Solution;
    }
    else
        return 0;
}