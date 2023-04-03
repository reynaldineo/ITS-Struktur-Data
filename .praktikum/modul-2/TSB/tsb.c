#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct bstnode_t {
    char *key;
    struct bstnode_t 
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode* __bst__createNode(char *value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = (char*) malloc(sizeof(char)*(strlen(value)+15));
    strcpy(newNode->key, value);
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, char *value) {
    if (root == NULL) 
        return __bst__createNode(value);

    if (strcmp(root->key,value) < 0)
        root->left = __bst__insert(root->left, value);
    else if (strcmp(root->key,value) > 0)
        root->right = __bst__insert(root->right, value);
    
    return root;
}

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0;
}

void bst_insert(BST *bst, char *value){
    bst->_root = __bst__insert(bst->_root, value);
    bst->_size++;
}

void searchChild (BSTNode *root, char *NamaAnggota)
{
    if (root==NULL) {
        return;
    }
    
    if(strcmp(root->key,NamaAnggota)==0) {    
        if(root->left == NULL ){
            if( root->right != NULL)
                printf("- %s\n",  root->right->key);
            else    
                printf("Aku Sedih!! Tidak Memiliki Anak:)\n");
        }
        else if(root->right==NULL) {
            if( root->left!=NULL)
                printf("%s -\n",  root->left->key);
            else    
                printf("Aku Sedih!! Tidak Memiliki Anak:)\n");           
        }
        else {
            printf("%s %s\n", root->left->key, root->right->key);
        }
        return;
    }

    else if(strcmp(root->key,NamaAnggota) > 0){
        searchChild (root->right, NamaAnggota);
    }
    else searchChild (root->left, NamaAnggota);
}

void searchParents(BSTNode *root, char *NamaAnggota){
    if (root==NULL) {
        return;
    }
    BSTNode *prevNode = root;
    while (root) { 
        if(strcmp(root->key, NamaAnggota) == 0) {
            break;
        }
        prevNode = root;

        if(strcmp(root->key,NamaAnggota) > 0) {
            root = root->right;
        }
        else if(strcmp(root->key,NamaAnggota) < 0) {
            root = root->left;
        }
    }
    printf("%s\n", prevNode->key);
}
 
int main(){
    BST set;
    bst_init(&set);
    
    int n,tc;
    char opt1[10000], opt2[10000];

    scanf("%d %d", &n, &tc);

    while(n--){
        char nama[10000];
        scanf("%s", nama);
        bst_insert(&set, nama);
    }

    while(tc--){
        char kode[10000], namaAnggota[10000];
        scanf("%s %s" ,kode ,namaAnggota);
        if(!strcmp(kode, "Anak")) {
            searchChild(set._root, namaAnggota);
        }
        else if(!strcmp(kode, "Ibu")) {
            if(!strcmp(set._root->key, namaAnggota)) {
                printf("Aku Adalah Pemimpin Keluarga Ini! HAHAHA\n");
            }
            else searchParents(set._root, namaAnggota);
        }         
    }
    return 0;
}