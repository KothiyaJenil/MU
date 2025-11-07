#include <stdio.h>

int stack[100], choice, n, top = -1, x, i;

void push(void);
void pop(void);
void display(void);
void update(void);
void peek(void);
void peep(void);

int main()
{
    printf("Enter size of stack: ");
    scanf("%d", &n);
    printf("Stack operations using array:");
    printf("\n\t");
    printf("\n\t 1.push \n\t 2. pop \n\t 3. display \n\t 4. Update \n\t 5. Peek \n\t 6.peep\n\t 7. exit");

    do
    {
        printf("\nEnter choice: ");
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
            display();
            break;
        case 4:
            update();
            break;
        case 5:
            peek();
            break;
        case 6:
            peep();
            break;
        case 7:
            printf("\nExiting program.\n");
            exit(0);
        default:
            printf("\nEnter a valid choice.");
        }
    }
    while (choice != 7);

    return 0;
}

void push()
{
    if (top >= n - 1)
    {
        printf("Stack overflow.\n");
    }
    else
    {
        printf("Enter number to push: ");
        scanf("%d", &x);
        stack[++top] = x;
    }
}

void pop()
{
    if (top <= -1)
    {
        printf("Stack underflow.\n");
    }
    else
    {
        printf("Popped element is %d\n", stack[top--]);
    }
}

void display()
{
    if (top >= 0)
    {
        printf("Elements in stack:\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
    else
    {
        printf("Stack is empty.\n");
    }
}

void update()
{
    int pos, val;
    printf("Enter position from top (1 to %d) to update: ", top + 1);
    scanf("%d", &pos);
    if (pos <= 0 || pos > top + 1)
    {
        printf("Invalid position.\n");
    }
    else
    {
        printf("Enter new value: ");
        scanf("%d", &val);
        stack[top - pos + 1] = val;
        printf("Value updated.\n");
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Top element is %d\n", stack[top]);
    }
}

void peep()
{
    int pos;
    printf("Enter position from top (1 to %d): ", top + 1);
    scanf("%d", &pos);
    if (pos <= 0 || top - pos + 1 < 0)
    {
        printf("Invalid position (underflow).\n");
    }
    else
    {
        printf("Element at position %d from top is %d\n", pos, stack[top - pos + 1]);
    }
}
