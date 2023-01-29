#include "stdio.h"
#include "stdlib.h"

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* create();
void preOrder(Node*);
void inOrder(Node*);
void postOrder(Node*);

void main() {
    Node* root = create();
    inOrder(root);
    preOrder(root);
    postOrder(root);
}

Node* create() {
    int value;
    Node* newNode = (Node*)malloc(sizeof(Node));
    printf("Enter value for node ");
    scanf("%d", &value);
    if (value == -1) return NULL;
    newNode->data = value;
    printf("\nEnter left child of %d\n", value);
    newNode->left = create();
    printf("\nEnter right child of %d\n", value); 
    newNode->right = create();
    return newNode;
}

void preOrder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}
void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}