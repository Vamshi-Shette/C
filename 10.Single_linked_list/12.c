/*
12. Merging K Sorted Lists Challenges
Question:
Write a C program to merge K sorted linked lists.

Sample data:
List-1: 10 20 50
List-2: 30 40 60
List-3: 10 70 100

Expected output:
Merged list: 10 10 20 30 40 50 60 70 100
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

struct node* merge_two(struct node *a,struct node *b)
{
    if(a==NULL) return b;
    if(b==NULL) return a;
    struct node *result=NULL;
    if(a->data<=b->data)
    {
        result=a;
        result->next=merge_two(a->next,b);
    }
    else
    {
        result=b;
        result->next=merge_two(a,b->next);
    }
    return result;
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
    struct node *l1=NULL,*l2=NULL,*l3=NULL;
    int a[]={10,20,50};
    int b[]={30,40,60};
    int c[]={10,70,100};
    int i;
    for(i=0;i<3;i++){
        insert_end(&l1,a[i]);
        insert_end(&l2,b[i]);
        insert_end(&l3,c[i]);
    }
    struct node *temp=merge_two(l1,l2);
    struct node *merged=merge_two(temp,l3);
    printf("merged list: ");
    print_list(merged);
    return 0;
}