#include <bits/stdc++.h>

using namespace std;

typedef struct bstnode_t {
    int key;
    int stamina;
    struct bstnode_t 
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

void bst_insert(BST *bst, int value, int stamina) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value, stamina);
        bst->_size++;
    }
}

// Fungsi baru

BSTNode* findLowestCommonAncestor(BSTNode* root, int node1, int node2) {
    if (root == NULL) {
        return NULL;
    }
    
    if (node1 == root->key || node2 == root->key) {
        return root;
    }
    
    if (node1 < root->key && node2 < root->key) {
        return findLowestCommonAncestor(root->left, node1, node2);
    }
    
    if (node1 > root->key && node2 > root->key) {
        return findLowestCommonAncestor(root->right, node1, node2);
    }
    
    return root;
}

// int staminaKepakai = 0;

int hitungStaminaKepakai(BSTNode *root, int tujuan, int *staminaKepakai){
    // int staminaKepakai = 0;
    if(root->key == tujuan){
        return *staminaKepakai;
    }
    if(tujuan > root->key){
        staminaKepakai += root->right->stamina + 1;
        hitungStaminaKepakai(root->right, tujuan, staminaKepakai);
    }
    if(tujuan < root->key){
        staminaKepakai += root->left->stamina + 1;
        hitungStaminaKepakai(root->left, tujuan, staminaKepakai);
    }
}

int main(){
    BST set;
    bst_init(&set);

    int aAwal, bAkhir;
    cin >> aAwal >> bAkhir;

    int nJumlah;
    cin >> nJumlah;

    while(nJumlah--){
        int nomerRuangan, staminaRuangan;
        cin >> nomerRuangan >> staminaRuangan;
        bst_insert(&set, nomerRuangan, staminaRuangan);
    }
    
    BSTNode* ancestor = findLowestCommonAncestor(set._root, aAwal, bAkhir);

    int staminaKepakai = 0;

    staminaKepakai += hitungStaminaKepakai(ancestor, aAwal, &staminaKepakai);
    staminaKepakai += hitungStaminaKepakai(ancestor, bAkhir, &staminaKepakai);
    // cout << staminaKepakai + ancestor->stamina;
    cout << &staminaKepakai << " debug " << ancestor->stamina;
    return 0;
}