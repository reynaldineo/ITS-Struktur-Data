// #include <bits/stdc++.h>
// using namespace std;
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct bstnode_t {
    int key;
    struct bstnode_t 
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode* __bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL) 
        return __bst__createNode(value);

    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);
    
    return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

BSTNode* __bst__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    // return currNode;
    printf("Data min = %d\n", currNode->key);
}

BSTNode* __bst__remove(BSTNode *root, int value) {
    if (root == NULL) return NULL;

    if (value > root->key) 
        root->right = __bst__remove(root->right, value);
    else if (value < root->key) 
        root->left = __bst__remove(root->left, value);
    else {
        
        if (root->left == NULL) {
            BSTNode *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL) {
            BSTNode *leftChild = root->left;
            free(root);
            return leftChild;
        }

        BSTNode *temp = __bst__findMinNode(root->right);
        root->key     = temp->key;
        root->right   = __bst__remove(root->right, temp->key);
    }
    return root;
}

void __TREE__inorder(BSTNode *root) {
    if (root) {
        __TREE__inorder(root->left);
        printf("%d ", root->key);
        __TREE__inorder(root->right);
    }
}

void __bst__preorder(BSTNode *root) {
    if (root) {
        printf("%d ", root->key);
        __bst__preorder(root->left);
        __bst__preorder(root->right);
    }
}

void __TREE__postorder(BSTNode *root) {
    if (root) {
        __TREE__postorder(root->left);
        __TREE__postorder(root->right);
        printf("%d ", root->key);
    }
}

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_findMinNode(BST *bst) {
    __bst__findMinNode(bst->_root);
}

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

void bst_remove(BST *bst, int value) {
    if (bst_find(bst, value)) {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}

void bst_inorder(BST *bst) {
    __TREE__inorder(bst->_root);
}

void bst_preorder(BST *bst) {
    __bst__preorder(bst->_root);
}

void bst_postorder(BST *bst) {
    __TREE__postorder(bst->_root);
}

void __leaf__(BSTNode *root){
	if(root == NULL) 
        printf("kosong!");
	if(root->left!=NULL) __leaf__(root->left);
	if(root->right!=NULL) __leaf__(root->right);
    if(root->right == NULL && root->left == NULL) 
        printf("%d ",root->key);
}

void leaf(BST *bst) {
    __leaf__(bst->_root);
}

int main() {
    BST set;
    bst_init(&set);

    while(1){
        int menu;
        printf("\n");
        printf("pilih menu!\n");
        printf("1. Masukkan Data\n");
        printf("2. Hapus Data\n");
        printf("3. Pre Order\n");
        printf("4. In Order\n");
        printf("5. Post Order\n");
        printf("6. Find\n");
        printf("7. Find Min\n");
        printf("8. Leaf\n");
        printf("0. keluar\n");
        printf(">>>>> ");

        scanf("%d", &menu);
        printf("\n");

        if (menu == 1){
            int data;
            printf("Banyak data yang ingin di masukkan : ");
            scanf("%d", &data);
            while(data--){
                int num;
                scanf("%d", &num);
                bst_insert(&set, num);
            }
        }
        
        else if(menu == 2){
            int num;
            printf("Masukan data yang ingin di hapus: ");
            scanf("%d", &num);
            bst_remove(&set, num);
        }

        else if(menu == 3){
            bst_preorder(&set);
            printf("\n");
        }

        else if(menu == 4){
            bst_inorder(&set);
            printf("\n");
        }

        else if(menu == 5){
            bst_postorder(&set);
            printf("\n");
        }

        else if(menu == 6){
            printf("Masukan angka yg ingin di cari: ");
            int num;
            scanf("%d", &num);
            if(bst_find(&set, num) == true)
                printf("Data ada\n");
            else
                printf("Ga ada\n");
        }

        else if(menu == 7){
            bst_findMinNode(&set);
        }

        else if(menu == 8){
            printf("leafnya adalah: \n");
            leaf(&set);
            printf("\n");
        }

        else if(menu == 0){
            break;
        }
    }
    return 0;
}