#include <bits/stdc++.h>

using namespace std;

typedef struct bstnode_t {
    int key;
    int stamina;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;


BSTNode* __bst__createNode(int value, int stamina) {
    BSTNode *newNode = new BSTNode;
    newNode->key = value;
    newNode->stamina = stamina;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value, int stamina) {
    if (root == NULL) 
        return __bst__createNode(value, stamina);

    if (value < root->key)
        root->left = __bst__insert(root->left, value, stamina);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value, stamina);
    
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


void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
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

BSTNode *AncBawah(BSTNode *root, int a, int b)
{
    if (root == NULL)
        return NULL;

    BSTNode *left = AncBawah(root->left, a, b); 
    BSTNode *right = AncBawah(root->right, a, b);
    if (root->key == a || root->key == b)
        return root;
    if (left != NULL && right != NULL)
        return root;
    if (right)
        return right;
    else
        return left;
}

void bst_insert(BST *bst, int value, int stamina) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value, stamina);
        bst->_size++;
    }
}

int stamina = 0;

void jarak(BSTNode *root, int tujuan){
    if(root->key == tujuan){
        return;
    }
    if(root->key < tujuan){
        stamina += root->right->stamina + 1;
        jarak(root->right, tujuan);
    }
    if(root->key > tujuan){
        stamina += root->left->stamina + 1;
        jarak(root->left, tujuan);
    }
}

int main(){
    BST set;
    bst_init(&set);

    int start, tujuan, tree;

    cin >> start >> tujuan;

    cin >> tree;

    while(tree--){
        int val, stamina;
        cin >> val >> stamina;
        bst_insert(&set, val, stamina);
    }
    
    BSTNode* temp = AncBawah(set._root, start, tujuan);
    // BSTNode* temp2 = __bst__search(set._root, 3);

    jarak(temp, start);
    jarak(temp, tujuan);
    cout << stamina + temp->stamina;
    // cout << set._root->key << " " << set._root->stamina;
    // cout << temp->key << " " << temp->stamina;
    return 0;
    
}