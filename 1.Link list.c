#include<stdio.h>
#include<stdlib.h>
typedef struct Node node;
struct Node
{
    int value;
    node *next;
};
node *head;
void display();
void insert_last();
void insert_first();
void insert_pos();
void delete_last();
void delete_first();
void delete_in_position(int pos);
int size();


int main()
{
    int op;
    node *a=(node*)malloc(sizeof(node));
    node *b=(node*)malloc(sizeof(node));
    node *c=(node*)malloc(sizeof(node));
    node *d=(node*)malloc(sizeof(node));
    node *e=(node*)malloc(sizeof(node));

    head=a;
    a->value=1;
    a->next=b;
    b->value=2;
    b->next=c;
    c->value=3;
    c->next=d;
    d->value=4;
    d->next=e;
    e->value=5;
    e->next=NULL;

    while(1)
    {
        printf("\nSelect Linked List operation :\n\n");
        printf("1.Display list\n");
        printf("2.Insert in last\n");
        printf("3.Insert in first\n");
        printf("4.insert in position\n");
        printf("5.delete in last\n");
        printf("6.delete in  first\n");
        printf("7.delete in  position\n");
        printf("8.size of the list\n");
        printf("9.End the operation\n\n");
        printf("\nEnter what you want to do :");
        scanf("%d",&op);
        if (op==1)
        {
            display();

        }
        else if(op==2)
        {
            insert_last();
        }
        else  if(op==3)
        {
            insert_first();
        }
        else if(op==4)
        {

            insert_pos();

        }
        else if(op==5)
        {
            delete_last();
        }
        else  if(op==6)
        {
            delete_first();
        }
        else if(op==7)
        {
            int x;
            printf("\nEnter position for delete :");
            scanf("%d",&x);
            delete_in_position(x);

        }

        else if(op==8)
        {
            size(head);
        }

        else  if(op==9)
        {
            exit(0);
        }
        else
        {
            printf("Try again\n");
        }

    }

    return 0;
}
void display()
{
    printf("List is ");
    if(head==NULL)
    {
        printf("empty\n");
    }
    node *temp=head;

    while(temp!=NULL)
    {
        printf("%d ",temp->value);
        temp=temp->next;

    }
}


void insert_first()
{
    node *temp;

    temp=(node *)malloc(sizeof( node));
    if(temp==NULL)
    {
        printf("\nOut of Memory Space\n");
        return;
    }
    printf("\nInsert in first : " );
    scanf("%d",&temp->value);
    temp->next =NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}

void insert_last()
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    printf("Enter node value: ");
    scanf("%d",&temp->value);
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        node *list=head;
        while(list->next!=NULL)
        {
            list=list->next;
        }
        list->next=temp;
    }
}
void insert_pos()
{
    node *ptr,*temp;
    int i,pos,start;
    temp=(node *)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("\nOut of Memory Space:\n");
        return;
    }
    printf("\n position for  new node:\t");
    scanf("%d",&pos);
    printf("\nEnter value of the node:\t");
    scanf("%d",&temp->value) ;

    temp->next=NULL;
    if(pos==0)
    {
        temp->next=start;
        start=temp;
    }
    else
    {
        for(i=0,ptr=start; i<pos-1; i++)
        {
            ptr=ptr->next;
            if(ptr==NULL)
            {
                printf("\nPosition not found:\n");
                return;
            }
        }
        temp->next =ptr->next ;
        ptr->next=temp;
    }
}

void delete_first()
{
    if(head==NULL)
    {
        printf("Under Flow\n");
        return;
    }
    node *temp=head;
    head=head->next;
    free(temp);
}
void delete_last()
{
    if(head->next==NULL)
    {
        free(head);
        head=NULL;
        return;
    }
    node *temp=head;
    while(temp->next->next)
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}
void delete_in_position(int pos)
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return ;
    }
    node *temp=head,*prev;
    int i=0;
    if(pos==1)
    {
        head=head->next;
        free(temp);
        return;
    }
    i=1;
    while(temp->next!=NULL)

    {
        prev=temp;
        temp =temp->next;
        i++;
        if(pos==i)
        {
            prev->next=temp->next;
            free(temp);
            return ;
        }
    }
    printf("Index out of range\n");
}
int size(node *p)
{
    int count=0;

    while(p!=NULL)
    {
        count++;

        p=p->next;
    }
    printf("The size is : %d\n",count);
}



