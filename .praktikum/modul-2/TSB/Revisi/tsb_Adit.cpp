#include <iostream>

using namespace std;

typedef struct bstnode_t {
    string key;
    struct bstnode_t \
        *left, *right, *parent;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode *__bst__createNode(BSTNode *parent, string value){
    BSTNode *newNode = new BSTNode; //malloc 
    newNode->parent = parent;
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __insert(BSTNode *root, BSTNode *parent, string value) {
    if (root == NULL)
        return __bst__createNode(parent, value);
    
    if (value < root->key)
        root->left = __insert(root->left, root,value);
    else if (value > root->key)
        root->right = __insert(root->right, root, value);
    
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

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
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

void bst_insert(BST *bst, string value){
    if (!bst_find(bst, value))
    {
        bst->_root = __insert(bst->_root, bst->_root, value);
        bst->_size++;
    }
}

int main(){
    BST set;
    bst_init(&set);

    int n, tc;

    cin >> n >> tc;

    while(n--){
        string kata;
        cin >> kata;
        bst_insert(&set, kata);
    }

    cout << endl;

    while(tc--){

        string op;
        cin >> op;
        string nama;
        BSTNode* temp;
        if(op == "Ibu"){
            cin >> nama;
            // cout << endl;
            temp = __bst__search(set._root, nama);
            if(temp->parent == NULL){
                cout << "Aku Adalah Pemimpin Keluarga Ini! HAHAHA" << endl;//pemimpin keluarga
            }
            else{
                cout << temp->parent->key << endl;
            }
        }
        else if(op == "Anak"){
            cin >> nama;
            // cout << endl;
            temp = __bst__search(set._root, nama);
            if(temp->left != NULL && temp->right == NULL){
                // cout << endl;
                cout << "- " << temp->left->key << endl;
            }
            else if(temp->right != NULL && temp->left == NULL){
                cout << temp->right->key << " -" << endl;
            }

            else if(temp->right != NULL && temp->left != NULL){
                cout << temp->right->key << " " << temp->left->key << endl;
            }

            else{
                cout << "Aku Sedih!! Tidak Memiliki Anak:)" << endl;
            }
        }
    }

    return 0;
}