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

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

/**
 * Node structure and
 * uniqueBST structure
 */

typedef struct bstnode_t {
    // int key;
    string key;
    struct bstnode_t 
        *left, *right, *parent;
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

BSTNode* __bst__createNode(BSTNode *parent, string value) {
    BSTNode *newNode = new BSTNode; // ngebuat node baru (malloc)
    newNode->parent = parent; // set nilai parent
    newNode->key = value;   // set nilai awal (data)
    newNode->left = newNode->right = NULL; // set kanan kiri null
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, BSTNode *parent, string value) {
    if (root == NULL) 
        return __bst__createNode(parent, value);

    if (value < root->key)
        root->left = __bst__insert(root->left, root, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, root, value);
    
    return root;
}

BSTNode* __bst__search(BSTNode *root, string value) {
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

BSTNode* __bst__remove(BSTNode *root, string value) {
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
        // printf("%c ", root->key);
        cout << root->key << " ";
        __bst__inorder(root->right);
    }
}

void __bst__postorder(BSTNode *root) {
    if (root) {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        // printf("%s ", root->key);
        cout << root->key << " ";
    }
}

void __bst__preorder(BSTNode *root) {
    if (root) {
        // printf("%s ", root->key);
        cout << root->key << " ";
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
    bst->_size = 0;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, string value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, string value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, bst->_root, value);
        bst->_size++;
    }
}

void bst_remove(BST *bst, string value) {
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

// Function sendiri
int searchChild(BSTNode *Root, string NamaAnggota){
    BSTNode *temp = __bst__search(Root, NamaAnggota);

    // cek anak kiri
    if(temp->left == NULL){
        // cek lagi kanannya kosong apa engga
        if(temp->right != NULL)  // kalau ga kosong
            cout << temp->right->key << " -" << endl;
        else // kalau kanan kiri kosong
            printf("Aku Sedih!! Tidak Memiliki Anak:)\n");
    } 
    else if (temp->right == NULL){
        if(temp->left != NULL)
            cout << "- " << temp->left->key << endl;
        else 
            printf("Aku Sedih!! Tidak Memiliki Anak:)\n");
    }
    else { // kalau kanan kiri ga kosong
        cout << temp->right->key << " " << temp->left->key << endl;
    }
    return 0;
}

int main()
{
    BST set; // database
    bst_init(&set);

    int n, tc;
    cin >> n >> tc;

    while(n--){
        string nama;
        cin >> nama;
        bst_insert(&set, nama);
    }

    while(tc--){
        string kode;
        string namaAnggota; 
        cin >> kode >> namaAnggota;

        if(kode == "Anak"){
            searchChild(set._root, namaAnggota);
        }

        else if (kode == "Ibu"){
            // searchParent(set._root, namaAnggota);
            BSTNode* temp = __bst__search(set._root, namaAnggota);
            if(temp->parent == NULL){
                cout << "Aku Adalah Pemimpin Keluarga Ini! HAHAHA" << endl;
            }
            else{
                cout << temp->parent->key << endl;
            }
        }

    }


    return 0;
}