#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define EMPTY NULL

struct node {
    int data;
    struct node *leftChild;
    struct node *rightChild;
};

struct node *root = EMPTY;

void insert(int data) {
    struct node *inserted = (struct node*) malloc(sizeof(struct node));
    struct node *current;
    struct node *parent;

    inserted->data = data;
    inserted->leftChild = EMPTY;
    inserted->rightChild = EMPTY;

    if (root == EMPTY) {
        root = inserted;
    }
    else {
        current = root;

        while(true) {
            parent = current;

            if (data < parent->data) {
                current = current->leftChild;
                if (current == EMPTY) {
                    parent->leftChild = inserted;
                    return;
                }
            }
            else {
                current = current->rightChild;
                if (current == EMPTY) {
                    parent->rightChild = inserted;
                    return;
                }
            }
        }
    }

}

struct node* search(int data) {
    struct node *searched = root;
    printf("Visiting elements: ");

    while (data != searched->data) {
        if (searched != EMPTY)
            printf("%d ", searched->data);

        if (data < searched->data)
            searched = searched->leftChild;
        else
            searched = searched->rightChild;

        if (searched == EMPTY)
            return searched;
    }

    return searched;
}

void pre_order_traversal(struct node *root) {
    if (root != EMPTY) {
        printf("%d ", root->data);
        pre_order_traversal(root->leftChild);
        pre_order_traversal(root->rightChild);
    }
}

void inorder_traversal(struct node *root) {
    if (root != EMPTY) {
        inorder_traversal(root->leftChild);
        printf("%d ", root->data);
        inorder_traversal(root->rightChild);
    }
}

void post_order_traversal(struct node *root) {
    if (root != EMPTY) {
        post_order_traversal(root->leftChild);
        post_order_traversal(root->rightChild);
        printf("%d ", root->data);
    }
}

void main() {
    int i;
    int array[7] = { 27, 14, 35, 10, 19, 31, 42 };

    for(i = 0; i < 7; i++)
        insert(array[i]);

    i = 31;
    struct node * temp = search(i);

    if(temp != NULL) {
        printf("[%d] Element found.", temp->data);
        printf("\n");
    }else {
        printf("[ x ] Element not found (%d).\n", i);
    }

    i = 15;
    temp = search(i);

    if(temp != NULL) {
        printf("[%d] Element found.", temp->data);
        printf("\n");
    }else {
        printf("[ x ] Element not found (%d).\n", i);
    }

    printf("\nPreorder traversal: ");
    pre_order_traversal(root);

    printf("\nInorder traversal: ");
    inorder_traversal(root);

    printf("\nPost order traversal: ");
    post_order_traversal(root);
}
