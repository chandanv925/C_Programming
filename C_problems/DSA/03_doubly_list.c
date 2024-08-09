#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void append(struct Node **head_ref, int new_data)
{
    struct Node *new_node = createNode(new_data);
    struct Node *last = *head_ref;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
}

// Function to reverse the doubly linked list
void reverse(struct Node **head_ref)
{
    struct Node *temp = NULL;
    struct Node *current = *head_ref;

    // Swap next and prev for all nodes
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // Before changing the head, check for the case when list is empty or has one node
    if (temp != NULL)
    {
        *head_ref = temp->prev;
    }
}

// Function to print the list
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;

    // Creating a doubly linked list
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);

    printf("Original list:\n");
    printList(head);

    // Reversing the doubly linked list
    reverse(&head);

    printf("Reversed list:\n");
    printList(head);

    return 0;
}
