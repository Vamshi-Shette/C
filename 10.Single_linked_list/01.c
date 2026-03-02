
/*
1. Merge Sorted Lists Challenges
Question:
Write a C program to merge two sorted singly linked lists into a single sorted linked list.

Sample data:
List 1: 1 3 5 7
List 2: 2 4 6

Expected output:
Merged list: 1 2 3 4 5 6 7
*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* create(int arr[],int n)
{
    struct node *head=NULL,*temp=NULL,*newnode=NULL;
    int i;
    for(i=0;i<n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=arr[i];
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
    return head;
}

struct node* merge(struct node *l1,struct node *l2)
{
    struct node dummy;
    struct node *tail=&dummy;
    dummy.next=NULL;
    while(l1&&l2)
    {
        if(l1->data<l2->data)
        {
            tail->next=l1;
            l1=l1->next;
        }
        else
        {
            tail->next=l2;
            l2=l2->next;
        }
        tail=tail->next;
    }

    if(l1)
        tail->next=l1;
    else
        tail->next=l2;

    return dummy.next;
}

void display(struct node *head)
{
    while(head)
    {
        printf("%d ",head->data);
        head=head->next;
    }
}

int main()
{
    int a[]={1,3,5,7};
    int b[]={2,4,6};
    struct node *l1=create(a,4);
    struct node *l2=create(b,3);
    struct node *result=merge(l1,l2);
    printf("merged list: ");
    display(result);
    return 0;
}