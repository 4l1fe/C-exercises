#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    int key;
    struct node *next;
};
struct node *head = NULL;

void insert(int key, int data) {
    struct node *n = (struct node*) malloc(sizeof(struct node));
    n->key = key;
    n->data = data;
    n->next = head;
    head = n;
}

struct node* find(int key) {
    struct node *current = head;

    if (current == NULL) {
        return NULL;
    }

    while(current->key != key) {
        if(current->next == NULL) {
            return NULL;
        }
        current = current->next;
    }

    return current;
}

struct node* delete(int key) {
    struct node *current = head;
    struct node *previous = NULL;

    if (current == NULL) {
        return NULL;
    }

    while (current->key != key) {
        if (current->next == NULL) {
            return NULL;
        }
        previous = current;
        current = current->next;
    }

    if (current == head) {
        head = head->next;
    }
    else {
        previous->next = current->next;
    }

    return current;
}

struct node* deleteFirst() {
    struct node *n = head;
    head = head->next;
    return n;
}

void printList() {
    struct node *n = head;
    printf("\n[");
    while (n != NULL) {
        printf("(%d: %d) ", n->key, n->data);
        n = n->next;
    }
    printf("]");
}

bool isEmpty() {
    return head == NULL;
}

int length() {
    int length = 0;
    struct node *current;
    for(current=head; current!=NULL; current=current->next) {
        length++;
    }
    return length;
}

void sort() {
    int i, j, k, tempKey, tempData ;
    struct node *current;
    struct node *next;

    int size = length();
    k = size ;

    for ( i = 0 ; i < size - 1 ; i++, k-- ) {
    current = head ;
    next = head->next ;

    for ( j = 1 ; j < k ; j++ ) {

        if ( current->data > next->data ) {
            tempData = current->data ;
            current->data = next->data;
            next->data = tempData ;

            tempKey = current->key;
            current->key = next->key;
            next->key = tempKey;
        }

        current = current->next;
        next = next->next;
        }
    }
}

void reverse(struct node** head_ref) {
    struct node* previous = NULL;
    struct node* current = *head_ref;
    struct node* next;

    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    *head_ref= previous;
}

void main() {
    printf("Original:");
    insert(1,10); insert(2,20); insert(3,40);
    insert(4,11); insert(5,22); insert(6,1);
    printList();
    printf("\n");

    while (!isEmpty()) {
        struct node *temp = deleteFirst();
        printf("Deleted: (%d: %d)\n", temp->key, temp->data);
    }
    printf("\n");

    printf("Restored:");
    insert(1,10); insert(2,20); insert(3,40);
    insert(4,11); insert(5,22); insert(6,1);
    printList();
    printf("\n");

    struct node *found = find(4);
    printf("Found: (%d: %d)\n\n", found->key, found->data);

    printf("Item deleted:");
    delete(4);
    printList();
    printf("\n");
    found = find(4);
    if(found == NULL){
       printf("Element not found.");
    }
    printf("\n");

    printf("After sorting:");
    sort();
    printList();
    printf("\n");

    printf("After reversing:");
    reverse(&head);
    printList();
    printf("\n");
}
