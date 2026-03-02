/*
18. Alternate Node Merging Challenges
Question:
Write a C program to merge alternate nodes of two linked lists.

Sample data:
List1: 9 7 5
List2: 10 8 6

Expected output:
Merged list: 9 10 7 8 5 6
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

struct node* merge_alternate(struct node *l1,struct node *l2)
{
    struct node *head=l1;
    while(l1!=NULL&&l2!=NULL)
    {
        struct node *l1_next=l1->next;
        struct node *l2_next=l2->next;
        l1->next=l2;
        if(l1_next==NULL)
            break;
        l2->next=l1_next;
        l1=l1_next;
        l2=l2_next;
    }
    return head;
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

int main(){
    struct node *l1=NULL,*l2=NULL;
    int a[]={9,7,5};
    int b[]={10,8,6};
    int i;
    for(i=0;i<3;i++)
    {
        insert_end(&l1,a[i]);
        insert_end(&l2,b[i]);
    }
    struct node *merged=merge_alternate(l1,l2);
    printf("merged list: ");
    print_list(merged);
    return 0;
}