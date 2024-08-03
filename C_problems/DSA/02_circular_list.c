#include <stdio.h>
#include <stdlib.h>

#define COUNTOF(arr) (sizeof(arr) / sizeof(arr[0]))

struct Node
{
    int data;
    struct Node *next;
} *Head;

/* Create node*/
struct Node *create_node()
{
    return (struct Node *)malloc(sizeof(struct Node));
}

/* Create a circular list */
struct Node *create_list(int A[], int n)
{
    int i;
    struct Node *t, *last, *head;
    head = create_node();
    head->data = A[0];
    head->next = head;
    last = head;

    for (i = 1; i < n; i++)
    {
        t = create_node();
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
    return head;
}

/* Display the circular list*/
void Display(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}
void RDisplay(struct Node *h)
{
    static int flag = 0;
    if (h != Head || flag == 0)
    {
        flag = 1;
        printf("%d ", h->data);
        RDisplay(h->next);
    }
    flag = 0;
}

/* Length of list*/
int Length(struct Node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;

    } while (p != Head);
    return len;
}

/* Insert in the circular list*/
void Insert(struct Node *head, int index, int x)
{
    struct Node *t, *ptr = head;
    int i;
    if (index < 0 || index > Length(ptr))
        return;

    if (index == 0)
    {
        t = create_node();
        t->data = x;
        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            while (ptr->next != head)
                ptr = ptr->next;
            ptr->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            ptr = ptr->next;
        t = create_node();
        t->data = x;
        t->next = ptr->next;
        ptr->next = t;
    }
}

/* Delete from the circular list*/
int Delete(struct Node *head, int index)
{
    struct Node *q, *p = head;
    int i, x;

    if (index < 0 || index > Length(head))
        return -1;
    if (index == 1)
    {
        while (p->next != head)
            p = p->next;
        x = head->data;
        if (head == p)
        {
            free(head);
            head = NULL;
        }
        else
        {
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }
    else
    {
        for (i = 0; i < index - 2; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}

/* Driver code*/
int main()
{
    int A[] = {2, 3, 4, 5, 6};
    Head = create_list(A, COUNTOF(A));
    Insert(Head, 2, 2);
    Delete(Head, 2);
    RDisplay(Head);
    return 0;
}