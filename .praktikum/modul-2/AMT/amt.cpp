#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <algorithm> //untuk min

using namespace std;

/**
 * Node structure and
 * uniqueBST structure
 */

typedef struct bstnode_t {
    int key;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

/**
 * !!! WARNING UTILITY FUNCTION !!!
 * Recognized by prefix "__bst__"
 * ---------------------------------------------
 * Note that you better never access these functions, 
 * unless you need to modify or you know how these functions work.
 */
BST utama;
BST leaf;

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
    
    return currNode;
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

/**
 * PRIMARY FUNCTION
 * ---------------------------
 * Accessible and safe to use.
 */

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

int flag=0, kombinasiMin, kombinasiMax;

void __bst__inorder(BSTNode *root, int xHasil) {
    if (root) {
        if(!flag)
            __bst__inorder(root->left, xHasil);

        if(!flag){
            int cekTemp = xHasil - root->key;
            if(cekTemp != root->key){
                if(bst_find(&utama, cekTemp)){
                    kombinasiMin = min(root->key, cekTemp);
                    kombinasiMax = xHasil - kombinasiMin;
                    bst_remove(&utama, kombinasiMin);
                    bst_remove(&utama, kombinasiMax);
                    bst_remove(&leaf, kombinasiMin);
                    bst_remove(&leaf, kombinasiMax);
                    flag=1;
                    return;
                }
            }
        }
        if(!flag)
        __bst__inorder(root->right, xHasil);
    }
}

void bst_inorder(BST *bst, int x) {
    __bst__inorder(bst->_root, x);
}

void __findLeaf_Nodes(BSTNode *root) {
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL) {
            bst_insert(&leaf, root->key);
        }
        __findLeaf_Nodes(root->left);
        __findLeaf_Nodes(root->right);
    }
}

void findLeaf(BST *bst){
    __findLeaf_Nodes(bst->_root);
}

void __bst__inorder_biasa(BSTNode *root) {
    if (root) {
        __bst__inorder_biasa(root->left);
        printf("%d", root->key);
        if(root->right != NULL)
            printf(", ");
        __bst__inorder_biasa(root->right);
    }
}

void bst_inorder_biasa(BST *bst) {
    __bst__inorder_biasa(bst->_root);
}

int main()
{
    bst_init(&utama);
    bst_init(&leaf);

    int n, q;
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        bst_insert(&utama, a);
    }
    // nyari leaf
    findLeaf(&utama);

    cin >> q;
    while(q--){
        int x; // angka jumlah yg ingin di hasilkan
        cin >> x;
        flag = 0;
        bst_inorder(&utama, x);
        if(flag == 1){ // kalau berhasil dpt kombinasi
            printf("Aceng mengambil: %d dan %d\n", kombinasiMin, kombinasiMax);
        }
        else if(flag == 0){ // kalau ga dpt kombinasi
            printf("[");
            if(!bst_isEmpty(&leaf)){
                bst_inorder_biasa(&leaf);
            }
            printf("]\n");
        }
    }
    
    return 0;
}