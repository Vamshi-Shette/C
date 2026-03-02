/*
17. Halving the List Challenges
Question:
Write a C program to split a list into two halves.

Sample data:
List: 1 2 3 4 5 6

Expected output:
First half: 1 2 3
Second half: 4 5 6
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

void split_half(struct node *head,struct node **first,struct node **second)
{
    struct node *slow=head,*fast=head->next;
    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
    }
    *first=head;
    *second=slow->next;
    slow->next=NULL;
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
    struct node *first=NULL,*second=NULL;
    split_half(head,&first,&second);
    printf("first half: ");
    print_list(first);
    printf("second half: ");
    print_list(second);
    return 0;
}