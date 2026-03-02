/*
16. Alternate K-Node Reversal Challenges
Question:
Write a C program to reverse alternate k nodes.

Sample data:
List: 1 2 3 4 5 6 7 8
k = 2

Expected output:
Reversed: 2 1 3 4 6 5 7 8
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

struct node* reverse_alternate_k(struct node *head,int k)
{
    struct node *current=head,*prev=NULL,*next=NULL;
    int count=0;
    while(current!=NULL&&count<k)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        count++;
    }
    if(head!=NULL)
        head->next=current;
    count=0;
    while(current!=NULL&&count<k-1)
    {
        current=current->next;
        count++;
    }
    if(current!=NULL)
        current->next=reverse_alternate_k(current->next,k);
    return prev;
}

void print_list(struct node *head)
{
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

int main()
{
    struct node *head=NULL;
    int arr[]={1,2,3,4,5,6,7,8};
    int i;
    for(i=0;i<8;i++)
        insert_end(&head,arr[i]);
    int k=2;
    head=reverse_alternate_k(head,k);
    printf("reversed: ");
    print_list(head);
    return 0;
}