#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int searchValue(struct Node* root, int value) {
    if (root == NULL) return 0;
    if (root->data == value) return 1;
    return searchValue(root->left, value) || searchValue(root->right, value);
}

int main() {
    struct Node* root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);
    root->right->left = createNode(60);
    root->right->right = createNode(70);

    int valueToFind = 50;
    if (searchValue(root, valueToFind)) {
        printf("Gia tri %d duoc tim thay trong cay.\n", valueToFind);
    } else {
        printf("Gia tri %d khong ton tai trong cay.\n", valueToFind);
    }

    valueToFind = 25;
    if (searchValue(root, valueToFind)) {
        printf("Gia tri %d duoc tim thay trong cay.\n", valueToFind);
    } else {
        printf("Gia tri %d khong ton tai trong cay.\n", valueToFind);
    }

    return 0;
}

