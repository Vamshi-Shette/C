/*
14. Pairwise Reversal Challenges
Question:
Write a C program to reverse nodes in pairs.

Sample data:
List: 1 2 3 4 5

Expected output:
Reversed in pairs: 2 1 4 3 5
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

void pairwise_reverse(struct node **head)
{
    struct node *current=*head;
    while(current!=NULL&&current->next!=NULL)
    {
        int temp=current->data;
        current->data=current->next->data;
        current->next->data=temp;
        current=current->next->next;
    }
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
    int arr[]={1,2,3,4,5};
    int i;
    for(i=0;i<5;i++)
        insert_end(&head,arr[i]);
    pairwise_reverse(&head);
    printf("reversed in pairs: ");
    print_list(head);
    return 0;
}