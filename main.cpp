#include <iostream>
#include <typeinfo>
#include <cstring>
#include "Stack.h"
#define STACK_H
int main(int argc, char **argv)
{
    Stack Stack1;
    

    Stack1.setCapacity(argc+1);
    for(int i = argc-1; i != 0; i--){
        if(strcmp(argv[i], "+") == 0){ //Pushs '+' onto the Stack.
                Stack1.pushOperator(argv[i][0]);
		}		 
		else if(strcmp(argv[i], "-") == 0) { //Pushes '-' onto the Stack.
                Stack1.pushOperator(argv[i][0]);
		}
		else if((strcmp(argv[i], "*") == 0)){ //Pushes '*' onto the Stack. '*' requires a '\' beforehand, due to termainal syntax.
                Stack1.pushOperator(argv[i][0]);
		}
		else if((strcmp(argv[i], "/") == 0)){ //Pushes '/' onto the Stack.
            {
                Stack1.pushOperator(argv[i][0]);
            }
		}
        else if(argv[i][0] > 0) //Pushes an Operand to the Stack.
			{
                double numberInDouble = atof(argv[i]); //Converts arguments to double.
                Stack1.pushOperand(numberInDouble);
            }
        }

		if(Stack1.isEmpty() == false){
        std::cout << "The result of the calculation is: ";
		Stack1.evaluate();
		}
		return 0;
}
