
/*
2. Loop Detection Challenges
Question:
Write a C program to detect and remove a loop in a singly linked list.

Sample data:
List: 1 → 2 → 3 → 4 → 5 → (loop to 2)

Expected output:
Loop detected and removed.
List after removal: 1 2 3 4 5
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void remove_loop(struct node *head)
{
    struct node *slow=head,*fast=head;

    while(fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            break;
    }

    if(slow!=fast)
    {
        printf("no loop found\n");
        return;
    }

    slow=head;
    while(slow->next!=fast->next)
    {
        slow=slow->next;
        fast=fast->next;
    }

    fast->next=NULL;
    printf("loop detected and removed\n");
}

void display(struct node *head)
{
    while(head)
    {
        printf("%d ",head->data);
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

    n1->data=1; n2->data=2; n3->data=3; n4->data=4; n5->data=5;

    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n2;   // loop to 2

    remove_loop(n1);

    printf("list after removal: ");
    display(n1);

    return 0;
}