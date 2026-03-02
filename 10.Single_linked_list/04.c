/*
4. Copy with Random Pointers Challenges
Question:
Write a C program to create a deep copy of a singly linked list where each node has a random pointer.

Sample data:
List: 1 2 3 5 7
Random pointers: 1→3, 2→5, 3→7, 5→1, 7→3

Expected output:
New list with same data and random pointers correctly mapped.
*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *random;
};

struct node* copy_list(struct node *head)
{
    struct node *curr=head,*temp;

    // step 1: insert copy nodes
    while(curr)
    {
        temp=malloc(sizeof(struct node));
        temp->data=curr->data;
        temp->next=curr->next;
        curr->next=temp;
        curr=temp->next;
    }

    // step 2: copy random pointers
    curr=head;
    while(curr)
    {
        if(curr->random)
            curr->next->random=curr->random->next;
        curr=curr->next->next;
    }

    // step 3: separate lists
    curr=head;
    struct node *newhead=head?head->next:NULL;
    while(curr)
    {
        temp=curr->next;
        curr->next=temp->next;
        if(temp->next)
            temp->next=temp->next->next;
        curr=curr->next;
    }

    return newhead;
}

void display(struct node *head)
{
    while(head)
    {
        printf("data:%d ",head->data);
        if(head->random)
            printf("random:%d\n",head->random->data);
        else
            printf("random:null\n");
        head=head->next;
    }
}

int main()
{
    struct node *n1=malloc(sizeof(struct node));
    struct node *n2=malloc(sizeof(struct node));
    struct node *n3=malloc(sizeof(struct node));
    struct node *n4=malloc(sizeof(struct node));
    struct node *n5=malloc(sizeof(struct node));

    n1->data=1; n2->data=2; n3->data=3; n4->data=5; n5->data=7;

    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=NULL;

    // random connections
    n1->random=n3;
    n2->random=n4;
    n3->random=n5;
    n4->random=n1;
    n5->random=n3;

    struct node *copy=copy_list(n1);

    printf("new list with copied random pointers:\n");
    display(copy);

    return 0;
}