#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;  
    struct Node* right; 
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int tinhChieuCao(struct Node* root) {
    if (root == NULL) {
        return 0; 
    }
    int trai = tinhChieuCao(root->left);
    int phai = tinhChieuCao(root->right);
    return 1 + (trai > phai ? trai : phai);
}
 
int main() {

    struct Node* goc = createNode(1);
    goc->left = createNode(2);
    goc->right = createNode(3);
    goc->left->left = createNode(4);

    printf("Height : %d\n", tinhChieuCao(goc));

    return 0;
}

