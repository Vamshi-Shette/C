/*
13. Reordering by Parity Challenges
Question:
Write a C program to place all even-numbered nodes after odd-numbered nodes.

Sample data:
List: 1 2 3 4 5 6

Expected output:
Reordered list: 1 3 5 2 4 6
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
void reorder_parity(struct node **head)
{
    struct node *odd_start=NULL,*odd_end=NULL;
    struct node *even_start=NULL,*even_end=NULL;
    struct node *current=*head;
    while(current!=NULL)
    {
        if(current->data%2!=0)
        {
            if(odd_start==NULL)
            {
                odd_start=current;
                odd_end=current;
            }
            else
            {
                odd_end->next=current;
                odd_end=current;
            }
        }
        else
        {
            if(even_start==NULL)
            {
                even_start=current;
                even_end=current;
            }
            else{
                even_end->next=current;
                even_end=current;
            }
        }
        current=current->next;
    }

    if(odd_start==NULL)
    {
        *head=even_start;
        return;
    }
    odd_end->next=even_start;
    if(even_end!=NULL)
        even_end->next=NULL;
    *head=odd_start;
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
    reorder_parity(&head);
    printf("reordered list: ");
    print_list(head);
    return 0;
}