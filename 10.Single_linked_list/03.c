/*
3. Palindrome Check Variants
Question:
Write a C program to check if a singly linked list is a palindrome.

Sample data:
List: 1 2 2 1

Expected output:
Linked list is a palindrome.
*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int is_palindrome(struct node *head)
{
    struct node *slow=head,*fast=head;
    struct node *prev=NULL,*next=NULL;

    while(fast&&fast->next)
    {
        fast=fast->next->next;

        next=slow->next;
        slow->next=prev;
        prev=slow;
        slow=next;
    }

    if(fast)
        slow=slow->next;

    while(prev&&slow)
    {
        if(prev->data!=slow->data)
            return 0;
        prev=prev->next;
        slow=slow->next;
    }
    return 1;
}

int main()
{
    struct node *n1=malloc(sizeof(struct node));
    struct node *n2=malloc(sizeof(struct node));
    struct node *n3=malloc(sizeof(struct node));
    struct node *n4=malloc(sizeof(struct node));

    n1->data=1;
    n2->data=2;
    n3->data=2;
    n4->data=1;

    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=NULL;

    if(is_palindrome(n1))
        printf("linked list is a palindrome\n");
    else
        printf("not a palindrome\n");

    return 0;
}