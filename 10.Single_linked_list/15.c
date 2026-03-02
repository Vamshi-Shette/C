/*
15. Block Reversal Variants
Question:
Write a C program to reverse nodes in blocks of size k.

Sample data:
List: 1 2 3 4 5 6
k = 3

Expected output:
Reversed: 3 2 1 6 5 4
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

struct node* reverse_k(struct node *head,int k)
{
    struct node *prev=NULL,*current=head,*next=NULL;
    int count=0;

    while(current!=NULL&&count<k)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        count++;
    }
    if(next!=NULL)
        head->next=reverse_k(next,k);
    return prev;
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
    struct node *head=NULL;
    int arr[]={1,2,3,4,5,6};
    int i;
    for(i=0;i<6;i++)
        insert_end(&head,arr[i]);
    int k=3;
    head=reverse_k(head,k);
    printf("reversed: ");
    print_list(head);
    return 0;
}