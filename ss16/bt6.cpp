#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }

    return root;
}

int countNodesGreaterThanX(struct Node* root, int X) {
    if (root == NULL) {
        return 0;
    }

    int count = 0;
    
    if (root->data > X) {
        count = 1;
    }

    count += countNodesGreaterThanX(root->left, X);
    count += countNodesGreaterThanX(root->right, X);
    
    return count;
}

int main() {
    struct Node* root = NULL;
    
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);
    
    int X;
    printf("Nhap gia tri X: ");
    scanf("%d", &X);
    
    int result = countNodesGreaterThanX(root, X);
    printf("So nut co gia tri lon hon %d: %d\n", X, result);
    
    return 0;
}

