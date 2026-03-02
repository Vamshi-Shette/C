/*
19. Alternate Interleaving Challenges
Question:
Write a C program to interleave two lists alternatively.

Sample data:
List1: 1 3 5
List2: 2 4 6

Expected output:
Result: 1 2 3 4 5 6
*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* create_node(int value)
{
    struct node *new_node=malloc(sizeof(struct node));
    new_node->data=value;
    new_node->next=NULL;
    return new_node;
}

void insert_end(struct node **head,int value)
{
    struct node *new_node=create_node(value);
    if(*head==NULL)
    {
        *head=new_node;
        return;
    }
    struct node *temp=*head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=new_node;
}

struct node* interleave(struct node *l1,struct node *l2)
{
    struct node dummy;
    struct node *tail=&dummy;
    dummy.next=NULL;
    while(l1!=NULL||l2!=NULL)
    {
        if(l1!=NULL)
        {
            tail->next=l1;
            tail=tail->next;
            l1=l1->next;
        }
        if(l2!=NULL)
        {
            tail->next=l2;
            tail=tail->next;
            l2=l2->next;
        }
    }
    return dummy.next;
}

void print_list(struct node *head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

int main()
{
    struct node *l1=NULL,*l2=NULL;
    int a[]={1,3,5};
    int b[]={2,4,6};
    int i;
    for(i=0;i<3;i++)
    {
        insert_end(&l1,a[i]);
        insert_end(&l2,b[i]);
    }
    struct node *result=interleave(l1,l2);
    printf("result: ");
    print_list(result);
    return 0;
}