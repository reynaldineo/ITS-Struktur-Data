#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    
    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

int sumNodes(Node* node, int startNodeData, int endNodeData) {
    if (node == NULL) {
        return 0;
    }
    
    if (node->data < startNodeData) {
        return sumNodes(node->right, startNodeData, endNodeData);
    }
    
    if (node->data > endNodeData) {
        return sumNodes(node->left, startNodeData, endNodeData);
    }
    
    return node->data + sumNodes(node->left, startNodeData, endNodeData) + sumNodes(node->right, startNodeData, endNodeData);
}

int main() {
    Node* root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 7);
    root = insert(root, 9);
    root = insert(root, 14);
    inOrderTraversal(root);
    printf("\n");
    int sum = sumNodes(root, 14, 10);
    printf("Sum of nodes from 3 to 14: %d\n", sum);
    return 0;
}
