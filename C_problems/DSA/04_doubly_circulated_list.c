#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular doubly linked list
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    struct Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        new_node->next = *head_ref;
        new_node->prev = *head_ref;
        return;
    }

    while (last->next != *head_ref) {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
    new_node->next = *head_ref;
    (*head_ref)->prev = new_node;
}

// Function to insert a node at a given position in the circular doubly linked list
void insert(struct Node** head_ref, int data, int position) {
    struct Node* new_node = createNode(data);
    struct Node* temp = *head_ref;

    // Case 1: List is empty
    if (*head_ref == NULL) {
        new_node->next = new_node;
        new_node->prev = new_node;
        *head_ref = new_node;
        return;
    }

    // Case 2: Insert at the beginning
    if (position == 0) {
        struct Node* last = (*head_ref)->prev;

        new_node->next = *head_ref;
        new_node->prev = last;
        last->next = new_node;
        (*head_ref)->prev = new_node;
        *head_ref = new_node;
        return;
    }

    // Case 3: Insert at a given position (not at the beginning)
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
        if (temp == *head_ref) {
            // If position is out of bounds, insert at the end
            break;
        }
    }

    struct Node* next_node = temp->next;
    new_node->next = next_node;
    new_node->prev = temp;
    temp->next = new_node;
    if (next_node != *head_ref) {
        next_node->prev = new_node;
    } else {
        // If inserted at the end, update the prev pointer of head
        (*head_ref)->prev = new_node;
    }
}
// Function to reverse the circular doubly linked list
void reverse(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* temp = NULL;
    
    // If the list is empty or has only one node, do nothing
    if (*head_ref == NULL || (*head_ref)->next == *head_ref) {
        return;
    }

    do {
        // Swap next and prev for the current node
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the next node (which is previous node due to swap)
        current = current->prev;
    } while (current != *head_ref);

    // Adjust the head pointer
    if (temp != NULL) {
        *head_ref = temp->prev;  // New head is the last node we swapped
    }
}

// Function to print the list
void printList(struct Node* head) {
    struct Node* temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Creating a circular doubly linked list
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    printf("Original list:\n");
    printList(head);
    insert(&head, 3, 3);
    // reverse(&head);

    printf("Reversed list:\n");
    printList(head);

    return 0;
}
