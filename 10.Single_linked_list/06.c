/*
6. Partitioning with Dual Pivots
Question:
Write a C program to partition a linked list around a value x.

Sample data:
List: 3 5 7 5 9 2 1
x = 5

Expected output:
Reordered list: 3 2 1 5 7 5 9
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

void insert_end(struct node **head,int value){
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

void partition_list(struct node **head,int x){
    struct node *before_start=NULL,*before_end=NULL;
    struct node *after_start=NULL,*after_end=NULL;
    struct node *current=*head;

    while(current!=NULL){
        struct node *next=current->next;
        current->next=NULL;

        if(current->data<x){
            if(before_start==NULL){
                before_start=current;
                before_end=current;
            }
            else{
                before_end->next=current;
                before_end=current;
            }
        }
        else{
            if(after_start==NULL){
                after_start=current;
                after_end=current;
            }
            else{
                after_end->next=current;
                after_end=current;
            }
        }
        current=next;
    }

    if(before_start==NULL){
        *head=after_start;
        return;
    }

    before_end->next=after_start;
    *head=before_start;
}

void print_list(struct node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

int main(){
    struct node *head=NULL;

    int arr[]={3,5,7,5,9,2,1};
    int n=7;
    int i;

    for(i=0;i<n;i++)
        insert_end(&head,arr[i]);

    int x=5;

    partition_list(&head,x);

    printf("reordered list: ");
    print_list(head);

    return 0;
}