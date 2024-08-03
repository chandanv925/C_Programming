
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define COUNTOF(arr) (sizeof(arr)/sizeof(arr[0]))

struct Node{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

/* Create node*/
struct Node *create_node(){
    return (struct Node *)malloc(sizeof(struct Node));
}

/* Create a linked list using array*/
struct Node *create_list(int A[], int n){
    int i;
    struct Node *new, *last, *head;
    head = create_node();
    head->data = A[0];
    head->next = NULL;
    last = head;

    for (i = 1; i < n; i++){
        new = create_node();
        new->data = A[i];
        new->next = NULL;
        last->next = new;
        last = new;
    }
    return head;
}

/* Count the number of node in a list*/
int count(struct Node *head){
    int len = 0;
    while (head){
        len++;
        head = head->next;
    }
    return len;
}
int Rcount(struct Node *head){
    if (!head)
        return 0;
    else
        return Rcount(head->next) + 1;
}

/* Display the list */
void Display(struct Node *head){   
    struct Node *ptr = head;
    while (ptr){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

/* Display the list in reverse order*/
void RDisplay(struct Node *head){
    struct Node *ptr = head;
    if (ptr){
        RDisplay(ptr->next);
        printf("%d ", ptr->data);
    }

}

/* Find the max in a list */
int Max(struct Node *head){
    struct Node *ptr = head;
    int max = INT_MIN;
    while (ptr){
        if (ptr->data > max){
            max = ptr->data;
        }
        ptr = ptr->next;
    }
    return max;
}
int RMax(struct Node *head){
    struct Node *ptr = head;
    int x = 0;

    if (!ptr)
        return INT_MIN;
    x = RMax(ptr->next);
    if (x > ptr->data)
        return x;
    else
        return ptr->data;
}

int RMax2(struct Node *head){
    if (!head)
        return 0;

    int maxInRest = Max(head->next);
    return maxInRest > head->data ? maxInRest : head->data;
}

/* Find the Sum of a list */
int sum(struct Node *head){
    struct Node *ptr = head;
    int s = 0;

    while (ptr)   //(ptr != NULL)
    {
        s += ptr->data;
        ptr = ptr->next;
    }
    return s;
}

/* Find the Sum of a list using recursion */
int Rsum(struct Node *ptr){
    if (ptr == NULL)
        return 0;
    else
        return Rsum(ptr->next) + ptr->data;
}

/* Find the diffrence of sum of Odd and even number */
int sumDifference(struct Node *head){
    struct Node *ptr = head;
    int even = 0, odd = 0;

    while (ptr) {
        if ((ptr->data & 1) == 0) {
            even += ptr->data;
        } else {
            odd += ptr->data;
        }
        ptr = ptr->next;
    }
    return abs(even - odd);
}

/* Insert a node at any index*/
void Insert(struct Node *p, int index, int val){
    struct Node *new;
    int i;

    if (index < 0 || index > count(p)){
        return;
    }
    new = (struct Node *)malloc(sizeof(struct Node));
    new->data = val;

    if (index == 0){
        new->next = first;
        first = new;
    }
    else{
        for (i = 0; i < index - 1; i++){
            p = p->next;
        }
        new->next = p->next;
        p->next = new;
    }
}

/* Linear Search in the list*/
struct Node *LSearch(struct Node *p, int key){
    struct Node *q;

    while (p){
        if (key == p->data){
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

/* Search in the list */
struct Node *RSearch(struct Node *head, int key){
    if (head == NULL)
        return NULL;
    if (key == head->data)
        return head;
    return RSearch(head->next, key);
}

/* Delete a node from the list */
int Delete(struct Node *p, int index){
    struct Node *q = NULL;
    int x = -1, i;

    if (index < 1 || index > count(p))
        return -1;
    if (index == 1){
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else{
        for (i = 0; i < index - 1; i++){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}

/* Remove duplicate from the sorted list */
void RemoveDuplicate(struct Node *p){
    struct Node *q = p->next;

    while (q != NULL){
        if (p->data != q->data){
            p = q;
            q = q->next;
        }
        else{
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

/* Reverse the list */
void Reverse1(struct Node *p){
    int *A, i = 0;
    struct Node *q = p;

    A = (int *)malloc(sizeof(int) * count(p));

    while (q != NULL){
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q != NULL){
        q->data = A[i];
        q = q->next;
        i--;
    }
}
void Reverse2(struct Node *p){
    struct Node *q = NULL, *r = NULL;

    while (p != NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}
void Reverse3(struct Node *q, struct Node *p){
    if (p){
        Reverse3(p, p->next);
        p->next = q;
    }
    else
        first = q;
}

/* Merge tow sorted list */
struct Node *Merge(struct Node *p, struct Node *q){
    struct Node *last, *merged_list;
    if (p->data < q->data){
        merged_list = last = p;
        p = p->next;
        merged_list->next = NULL;
    }
    else{
        merged_list = last = q;
        q = q->next;
        merged_list->next = NULL;
    }
    while (p && q){
        if (p->data < q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else{
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p)
        last->next = p;
    if (q)
        last->next = q;

    return merged_list;
}

/* Check if the list is has a loop*/
int isLoop(struct Node *f){
    struct Node *p, *q;
    p = q = f;

    do{
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while (p && q && p != q);

    return p == q ? 1 : 0;
}

/*Driver code*/
int main()
{

    int A[] = {10, 25, 30, 45, 50};
    int B[] = {15, 25, 35, 45, 55};
    first = create_list(A, COUNTOF(A));
    second = create_list(B, COUNTOF(B));
    //printf("%d\n",count(first));
    Display(first);
    Delete(first, 2);
    Display(first);
    Insert(first, 1, 25);
    Display(first);
    //printf("%d\n",isLoop(first));
    third = Merge(first, second);
    Display(third);
    //Reverse1(third);
    Display(third);

    RemoveDuplicate(third);
    Display(third);

    return 0;
}
