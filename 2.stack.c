#include <stdio.h>
#include <stdlib.h>
#include <limits.h>+3
#define CAPACITY 200
typedef struct Node node;
struct Node
{
    int value;
    node*next;
} *top;


int size = 0;




int push(int element);
int  pop();


int main()
{
    int op, value;

    while(1)
    {


        printf("implement stack \n");

        printf("1. Push\n");
        printf("2. display\n");
        printf("3. pop\n");
        printf("4. Size\n");
        printf("5. Exit\n");

        printf("Enter what you want: ");

        scanf("%d", &op);

        switch(op)
        {
        case 1:
            printf("Enter data to push into stack: ");
            scanf("%d", &value);


            push(value);
            break;
          //case 2:

            void display(temp);

        case 3:
            value = pop();


            if (value != INT_MIN)
                printf("stack is => %d\n", value);
            break;

        case 4:
            printf("Stack size: %d\n", size);
            break;

        case 5:
            printf("Exiting from app.\n");
            exit(0);
            break;

        default:
            printf("please try again.\n");
        }

        printf("\n\n");
    }



    return 0;
}



push(int element)
{

    if (size >= CAPACITY)
    {
        printf("Overflow\n");
        return;
    }


    node* newNode = (node*) malloc(sizeof(node));


    newNode->value = element;


    newNode->next = top;


    top = newNode;


    size++;

    printf("value pushed to stack.\n");
}
void display()
{
    node*temp;
    temp=top;
    if(temp=-1)
    {
        printf("stack is empty");
    }
    while (temp!=NULL)
    {
        printf("%d",temp->value);
    }
    temp=temp->next;
}



int pop()
{
    int value = 0;
    node * topNode;

    if (size <= 0 || !top)
    {
        printf("Stack is empty.\n");


        return INT_MIN;
    }


    topNode = top;


    value = top->value;


    top = top->next;


    free(topNode);


    size--;

    return value;
}
