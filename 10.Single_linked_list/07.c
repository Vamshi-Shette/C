/*
7. Linked List Addition Variants
Question:
Write a C program to add two numbers represented by linked lists.

Sample data:
List 1: 8 7 9 2
List 2: 2 1 2 3

Expected output:
Result: 0 9 1 6 (carry handled)
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

void reverse(struct node **head){
    struct node *prev=NULL,*current=*head,*next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *head=prev;
}

struct node* add_lists(struct node *l1,struct node *l2){
    int carry=0;
    struct node *result=NULL;
    while(l1!=NULL||l2!=NULL||carry){
        int sum=carry;
        if(l1!=NULL){
            sum+=l1->data;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum+=l2->data;
            l2=l2->next;
        }
        insert_end(&result,sum%10);
        carry=sum/10;
    }
    return result;
}

void print_list(struct node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

int main(){
    struct node *l1=NULL;
    struct node *l2=NULL;
    int arr1[]={8,7,9,2};
    int arr2[]={2,1,2,3};
    int n=4;
    int i;
    for(i=0;i<n;i++){
        insert_end(&l1,arr1[i]);
        insert_end(&l2,arr2[i]);
    }
    reverse(&l1);
    reverse(&l2);
    struct node *result=add_lists(l1,l2);
    reverse(&result);
    printf("result: ");
    print_list(result);
    return 0;
}