#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct Cell
{
    double item;
    struct Cell *next;
};

struct Cell *stack;
int stackInUse;

// Initialize the count of stackInUse
void initStack() {
    stackInUse = 0;
}

// Check is stack empty or not.
int isStackEmpty()
{
    if (stackInUse == 0)
        return 1;
    return 0;
}

// Add value to stack.
void push(double num)
{
    struct Cell *pointer = malloc(sizeof(struct Cell));
    pointer->item = num;
    pointer->next = stack;
    stack = pointer;
    stackInUse++;
}

// Get and free value from stack
double pop()
{
    double num;
    struct Cell *next;
    if (isStackEmpty())
    {
        fprintf(stderr, "##### Stack is empty.\n");
        return 0;
    }
    num = stack->item;
    next = stack->next;
    free(stack);
    stack = next;
    stackInUse--;
    return num;
}

// Get value from stack
double top()
{
    return stack->item;
}

// Show detail of stack.
void checkStack()
{
    struct Cell *pointer = stack;
    printf("Stack: ");
    while (pointer != NULL)
    {
        printf("%.2lf ", pointer->item);
        pointer = pointer->next;
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    char *input = argv[1]; // Argument from command line.
    char carryString[100]; // Buffer to store argument.

    if (argc <= 1)
    {
        fprintf(stderr, "##### Input RPN as a command line argumet.\n");
        return 1;
    }

    while (strlen(input) > 0)
    {
        int ret = sscanf(input, "%s", carryString);
        if (ret == EOF)
            break;
        input += strlen(carryString);
        while (input[0] == ' ')
        {
            // Skip blank.
            input++;
        }

        // In case of digit.
        if (isdigit(carryString[0]))
        {
            // Extract num fron carryString, then store to stack
            double num = atof(carryString);
            push(num);
            printf("<- %.2lf (number)\n", num);
        }
        // In case of operator.
        else
        {
            double num1, num2, answer;
            switch (carryString[0])
            {
            case '+':
                num1 = pop();
                num2 = pop();
                answer = num2 + num1;
                push(answer);
                printf("<- + (operator)\n");
                break;
            case '-':
                num1 = pop();
                num2 = pop();
                answer = num2 - num1;
                push(answer);
                printf("<- - (operator)\n");
                break;
            case '*':
                num1 = pop();
                num2 = pop();
                answer = num2 * num1;
                push(answer);
                printf("<- * (operator)\n");
                break;
            case '/':
                num1 = pop();
                num2 = pop();
                answer = num2 / num1;
                push(answer);
                printf("<- / (operator)\n");
                break;
            default:
                fprintf(stderr, "##### '%c' is unknown operator.\n", carryString[0]);
                break;
            }
        }
        checkStack();
    }

    printf("Result: %.2lf", top());

    return 0;
}
