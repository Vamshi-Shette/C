/*
20. Adjacent Node Swapping Variants
Question:
Write a C program to swap every two adjacent nodes.

Sample data:
List: 1 2 3 4 5

Expected output:
Swapped list: 2 1 4 3 5
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* swap_adjacent(struct node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct node *prev = NULL;
    struct node *current = head;
    head = head->next;   // New head will be second node

    while (current != NULL && current->next != NULL)
    {
        struct node *nextPair = current->next->next;
        struct node *second = current->next;

        // Swap
        second->next = current;
        current->next = nextPair;

        if (prev != NULL)
            prev->next = second;

        prev = current;
        current = nextPair;
    }

    return head;
}

void insert_end(struct node **head, int value)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if (*head == NULL)
    {
        *head = newnode;
        return;
    }

    struct node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

void print_list(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct node *head = NULL;

    insert_end(&head, 1);
    insert_end(&head, 2);
    insert_end(&head, 3);
    insert_end(&head, 4);
    insert_end(&head, 5);

    printf("Original list: ");
    print_list(head);

    head = swap_adjacent(head);

    printf("Swapped list: ");
    print_list(head);

    return 0;
}