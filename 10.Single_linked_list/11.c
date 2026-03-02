/*
11. Nth Node from End Variants
Question:
Write a C program to retrieve the nth node from the end.

Sample data:
List: 1 3 5 11
n = 3

Expected output:
Result: 3
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
    if(*head==NULL){
        *head=new_node;
        return;
    }
    struct node *temp=*head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=new_node;
}

int nth_from_end(struct node *head,int n)
{
    struct node *first=head,*second=head;
    int i;
    for(i=0;i<n;i++){
        if(first==NULL)
            return -1;
        first=first->next;
    }
    while(first!=NULL){
        first=first->next;
        second=second->next;
    }
    return second->data;
}

int main()
{
    struct node *head=NULL;
    int arr[]={1,3,5,11};
    int i;
    for(i=0;i<4;i++)
        insert_end(&head,arr[i]);
    int n=3;
    printf("result: %d\n",nth_from_end(head,n));
    return 0;
}