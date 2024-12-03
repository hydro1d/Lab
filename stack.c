#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int top = -1, inp_array[SIZE];
void push();
void pop();
void show();
void peek(); // Function declaration for peek

int main()
{
    int choice;

    while (1)
    {
        printf("\nPerform operations on the stack:\n");
        printf("1.Push the element\n2.Pop the element\n3.Show\n4.Peek\n5.End\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            show();
            break;
        case 4:
            peek();
            break;
        case 5:
            exit(0);

        default:
            printf("\nInvalid choice!\n");
        }
    }
}

void push()
{
    int x;
    if (top == SIZE - 1)
    {
        printf("Overflow!\n");
    }
    else
    {
        printf("\nEnter the element to be added onto the stack: ");
        scanf("%d", &x);
        top++;
        inp_array[top] = x;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nPopped element: %d", inp_array[top]);
        top--;
    }
}

void show()
{
    if (top == -1)
    {
        printf("\n there is no element!");
    }
    else
    {
        printf("\nElements present in the stack: \n");
        for (int i = top; i >= 0; i--)
            printf("%d\n", inp_array[i]);
    }
}

void peek()
{
    if (top == -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nTop element of the stack: %d\n", inp_array[top]);
    }
}
