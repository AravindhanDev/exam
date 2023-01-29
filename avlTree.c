#include "stdio.h"
#include "stdlib.h"

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

int max(int, int);
int height(Node*);
int getBalance(Node*);
Node* createNode(int);
Node* leftRotate(Node*);
Node* rightRotate(Node*);
Node* insertNode(Node*, int);
Node* deleteNode(Node*, int);
Node* minValueNode(Node*);
void preOrder(Node*);

int main() {
    struct Node *root = NULL;

    root = insertNode(root, 2);
    root = insertNode(root, 1);
    root = insertNode(root, 7);
    root = insertNode(root, 4);
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 8);

    preOrder(root);

    root = deleteNode(root, 3);

    printf("\nAfter deletion: ");

    preOrder(root);

    return 0;
}

void preOrder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->key);
    preOrder(root->left);
    preOrder(root->right);
}

int max(int a, int b) {
    return a > b ? a : b;
}

int height(Node* node) {
    if (node == NULL) return 0;
    return node->height;
}

int getBalance(Node* node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL || root->right == NULL) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    
    if (root == NULL) return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

Node* insertNode(Node* root, int key) {
    if (root == NULL) return createNode(key);
    if (key < root->key) {
        root->left = insertNode(root->left, key); 
    }
    else if (key > root->key) {
        root->right = insertNode(root->right, key);
    }
    else return root;       
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);
    if (balance > 1 && key < root->left->key) {
        return rightRotate(root);
    }
    if (balance < -1 && key > root->right->key) {
        return leftRotate(root);
    }
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

Node* minValueNode(Node* root) {
    Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}
