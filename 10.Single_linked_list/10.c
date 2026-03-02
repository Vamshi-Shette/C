/*
10. Linked List Sorting Challenges
Question:
Write a C program to sort a singly linked list using merge sort.

Sample data:
List: 2 3 1 7 5

Expected output:
Sorted list: 1 2 3 5 7
*/
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* create_node(int value){
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

struct node* merge(struct node *a,struct node *b){
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    struct node *result=NULL;
    if(a->data<=b->data)
    {
        result=a;
        result->next=merge(a->next,b);
    }
    else
    {
        result=b;
        result->next=merge(a,b->next);
    }
    return result;
}

void split(struct node *source,struct node **front,struct node **back){
    struct node *slow=source;
    struct node *fast=source->next;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
    }
    *front=source;
    *back=slow->next;
    slow->next=NULL;
}

void merge_sort(struct node **head){
    if(*head==NULL||(*head)->next==NULL)
        return;
    struct node *a,*b;
    split(*head,&a,&b);
    merge_sort(&a);
    merge_sort(&b);
    *head=merge(a,b);
}

void print_list(struct node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

int main()
{
    struct node *head=NULL;
    int arr[]={2,3,1,7,5};
    int n=5;
    int i;
    for(i=0;i<n;i++)
        insert_end(&head,arr[i]);
    merge_sort(&head);
    printf("sorted list: ");
    print_list(head);
    return 0;
}