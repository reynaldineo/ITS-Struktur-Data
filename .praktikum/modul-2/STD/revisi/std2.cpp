/**
 * Implementasi Binary Search Tree (ADT: BST)
 * yakni BST yang tidak menyimpan key duplikat (unique key)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 29 Februrari 2019
 * Struktur Data 2020
 * 
 * Implementasi untuk Bahasa C
 */

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
// #include <stdio.h>
#include <iostream>

using namespace std;

/**
 * Node structure and
 * uniqueBST structure
 */

typedef struct bstnode_t {
    int key, stamina;
    struct bstnode_t 
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

BSTNode* __bst__createNode(int value, int stamina_f) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->stamina= stamina_f;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value, int stamina_f) {
    if (root == NULL) 
        return __bst__createNode(value, stamina_f);

    if (value < root->key)
        root->left = __bst__insert(root->left, value, stamina_f);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value, stamina_f);
    
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

void __bst__inorder(BSTNode *root) {
    if (root) {
        __bst__inorder(root->left);
        printf("%d ", root->key);
        // printf("r %d %d\n", root->key, root->stamina);
        __bst__inorder(root->right);
    }
}

void __bst__postorder(BSTNode *root) {
    if (root) {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        printf("%d ", root->key);
    }
}

void __bst__preorder(BSTNode *root) {
    if (root) {
        printf("%d ", root->key);
        __bst__preorder(root->left);
        __bst__preorder(root->right);
    }
}

/**
 * PRIMARY FUNCTION
 * ---------------------------
 * Accessible and safe to use.
 */

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
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

void bst_insert(BST *bst, int value, int stamina_f) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value, stamina_f);
        bst->_size++;
    }
}

void bst_remove(BST *bst, int value) {
    if (bst_find(bst, value)) {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}

/**
 * Binary search tree traversal
 * - Inorder
 * - Postorder
 * - Preorder
 */

void bst_inorder(BST *bst) {
    __bst__inorder(bst->_root);
}

void bst_postorder(BST *bst) {
    __bst__postorder(bst->_root);
}

void bst_preorder(BST *bst) {
    __bst__preorder(bst->_root);
}

BSTNode* cariBuyut(BSTNode *root, int valueA, int valueB) {
    while (root != NULL) {
        if (valueA < root->key && valueB < root->key)
            root = root->left;
        else if (valueA > root->key && valueB > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

BSTNode* findLowestCommonAncestor(BSTNode* root, int node1, int node2) {
    if (root == NULL) {
        return NULL;
    }
    
    if (root->key == node1 || root->key == node2) {
        return root;
    }
    
    if (root->key > node1 && root->key > node2) {
        return findLowestCommonAncestor(root->left, node1, node2);
    }
    
    if (root->key < node1 && root->key < node2) {
        return findLowestCommonAncestor(root->right, node1, node2);
    }
    
    return root;
}

int cariStaminaDariBuyut(BSTNode *root, int value) {
    BSTNode *temp = root;
    int total = 0;
    while (temp != NULL) {
        if (value < temp->key){
            temp = temp->left;
            total++;
            total += temp->stamina;
        }
        else if (value > temp->key){
            temp = temp->right;
            total++;
            total += temp->stamina;
        }  
        else{
            return total;
        }
    }
    return total;
}

int cariAncestor(BST *bst, int a, int b){
    cariBuyut(bst->_root, a, b);
}

int main()
{
    BST set;
    bst_init(&set);

    int aAwal, bAkhir, hasil = 0;
    cin >> aAwal >> bAkhir;
    
    int nJUmlah;
    cin >> nJUmlah;
    while(nJUmlah--){
        int nomerRuangan, staminaRuangan;
        cin >> nomerRuangan >> staminaRuangan;
        bst_insert(&set, nomerRuangan, staminaRuangan); 
    } // semua data telah di input

    // BSTNode *ancestor = cariBuyut(set._root, aAwal, bAkhir), *temp;
    // cariAncestor(&set, aAwal, bAkhir);
    BSTNode *ancestor = findLowestCommonAncestor(set._root, aAwal, bAkhir), *temp;
    hasil += ancestor->stamina;
    temp = ancestor;
    hasil += cariStaminaDariBuyut(temp, aAwal);
    temp = ancestor;
    hasil += cariStaminaDariBuyut(temp, bAkhir);
    
    cout << hasil << endl;
    return 0;
}