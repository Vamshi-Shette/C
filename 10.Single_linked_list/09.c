/*
9. Kth Node Swapping Variants
Question:
Write a C program to swap Kth node from beginning and end.

Sample data:
List: 1 2 3 4 5
k = 2
Expected output:
Swapped list: 1 4 3 2 5
*/
#include<stdio.h>
#include<stdlib.h>

struct node{
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

int get_length(struct node *head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}

void swap_kth(struct node *head,int k){
    int n=get_length(head);
    if(k>n)
        return;
    struct node *first=head;
    int i;
    for(i=1;i<k;i++)
        first=first->next;
    struct node *second=head;
    for(i=1;i<n-k+1;i++)
        second=second->next;
    int temp=first->data;
    first->data=second->data;
    second->data=temp;
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
    int arr[]={1,2,3,4,5};
    int n=5;
    int i;
    for(i=0;i<n;i++)
        insert_end(&head,arr[i]);
    int k=2;
    swap_kth(head,k);
    printf("swapped list: ");
    print_list(head);
    return 0;
}