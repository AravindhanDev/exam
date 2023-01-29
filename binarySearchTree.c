#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNewNode(int);
Node* insertNode(Node*, int);
Node* deleteNode(Node*, int);
Node* minNode(Node*);
void inOrder(Node*);
void postOrder(Node*);
void preOrder(Node*);
bool searchNode(Node*, int);
int findHeight(Node*);
int max(int, int);

void main() {
    struct Node *root = NULL;
    root = insertNode(root, 8);
    root = insertNode(root, 3);
    root = insertNode(root, 1);
    root = insertNode(root, 6);
    root = insertNode(root, 7);
    root = insertNode(root, 10);
    root = insertNode(root, 14);
    root = insertNode(root, 4);

  printf("Inorder traversal: ");
  inOrder(root);

  printf("\nAfter deleting 10\n");
  root = deleteNode(root, 10);
  printf("Inorder traversal: ");
  inOrder(root);
}

Node* deleteNode(Node* root, int value) {
    if (root == NULL) return root;
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }   
        Node* temp = minNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int findHeight(Node* root) {
    if (root == NULL) return -1;
    return max(findHeight(root->left), findHeight(root->right)) + 1;
}

Node* minNode(Node* root) {
    Node* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
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

Node* insertNode(Node* root, int value) {
    if (root == NULL) return createNewNode(value);
    if (root->data > value) root->left = insertNode(root->left, value);
    if (root->data < value) root->right = insertNode(root->right, value);
    return root;
}

bool searchNode(Node* root, int value) {
    if (root == NULL) return false;
    if (value == root->data) return true;
    if (value < root->data) return searchNode(root->left, value);
    if (value > root->data) return searchNode(root->right, value);
}

Node* createNewNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}