/*
8. List Rotation Challenges
Question:
Write a C program to rotate a linked list to the right by k places.

Sample data:
List: 1 3 4 7 9
k = 2

Expected output:
Rotated list: 4 7 9 1 3
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

void rotate_right(struct node **head,int k){
    if(*head==NULL||k==0)
        return;
    struct node *temp=*head;
    int length=1;
    while(temp->next!=NULL){
        temp=temp->next;
        length++;
    }
    temp->next=*head;
    k=k%length;
    int steps=length-k;
    struct node *new_tail=*head;
    int i;
    for(i=1;i<steps;i++)
        new_tail=new_tail->next;
    *head=new_tail->next;
    new_tail->next=NULL;
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
    int arr[]={1,3,4,7,9};
    int n=5;
    int i;
    for(i=0;i<n;i++)
        insert_end(&head,arr[i]);

    int k=2;
    rotate_right(&head,k);
    printf("rotated list: ");
    print_list(head);
    return 0;
}