/*
5. Intersection Finder Variants
Question:
Write a C program to find the intersection point of two singly linked lists.

Sample data:
List A: 1 2 → 3 4
List B: 5 → 3 4

Expected output:
Intersection found at node with data: 3
*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int get_length(struct node *head)
{
    int count=0;
    while(head)
    {
        count++;
        head=head->next;
    }
    return count;
}

struct node* find_intersection(struct node *head1,struct node *head2)
{
    int len1=get_length(head1);
    int len2=get_length(head2);
    int diff;

    if(len1>len2)
    {
        diff=len1-len2;
        while(diff--)
            head1=head1->next;
    }
    else
    {
        diff=len2-len1;
        while(diff--)
            head2=head2->next;
    }
    while(head1&&head2)
    {
        if(head1==head2)
            return head1;
        head1=head1->next;
        head2=head2->next;
    }
    return NULL;
}

int main()
{
    struct node *a1=malloc(sizeof(struct node));
    struct node *a2=malloc(sizeof(struct node));
    struct node *c1=malloc(sizeof(struct node));
    struct node *c2=malloc(sizeof(struct node));
    struct node *b1=malloc(sizeof(struct node));
    // common part 3->4
    c1->data=3;
    c2->data=4;
    c1->next=c2;
    c2->next=NULL;
    // list A: 1->2->3->4
    a1->data=1;
    a2->data=2;
    a1->next=a2;
    a2->next=c1;
    // list B: 5->3->4
    b1->data=5;
    b1->next=c1;
    struct node *result=find_intersection(a1,b1);
    if(result)
        printf("intersection found at node with data: %d\n",result->data);
    else
        printf("no intersection found\n");
    return 0;
}