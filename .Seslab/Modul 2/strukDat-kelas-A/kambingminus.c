#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int ketemu = 0;

/**
 * Node structure and
 * uniqueBST structure
 */

typedef struct bstnode_t {
    int key;
    struct bstnode_t *parent;
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

BSTNode* __bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->parent = NULL;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL) 
        return __bst__createNode(value);

    if (value < root->key)
    {
        root->left = __bst__insert(root->left, value);
        root->left->parent = root;
    }

    else if (value > root->key)
    {
        root->right = __bst__insert(root->right, value);
        root->right->parent = root;
    }
    return root;
}


void hitung_kambing (BSTNode *root, int tebakan)
{  
    if(!ketemu)
    {
        if (root && (root->left || root->right))
        {
            if(root->left && root->right)
            {
                if (tebakan == (root->key + root->left->key + root->right->key)
				|| tebakan == (root->key + root->parent->key + root->right->key)
				|| tebakan == (root->key + root->left->key + root->parent->key)) 
                ketemu = 1;
            }
            else
            {
                hitung_kambing(root->left, tebakan);
                hitung_kambing(root->right, tebakan);
            }
        }

        else if (!root->left)
            {
                if (tebakan == (root->key + root->parent->key + root->right->key)) ketemu = 1;
                else 
                {
                    hitung_kambing(root->left, tebakan);
                    hitung_kambing(root->right, tebakan);
                }
            }
            
        else if (!root->right)
            {
                if(tebakan == (root->key + root->parent->key + root->left->key)) ketemu = 1;
                else
                {
                    hitung_kambing(root->left, tebakan);
                    hitung_kambing(root->right, tebakan);
                }
            }
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

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}


/**
 * Binary search tree traversal
 * - Inorder
 * - Postorder
 * - Preorder
 */



void hitung_kambing_primary (BST *bst, int tebakan)
{
    if (tebakan > (bst->_root->key + bst->_root->left->key + bst->_root->right->key)) hitung_kambing (bst->_root->right, tebakan);
    else if (tebakan == (bst->_root->key + bst->_root->left->key + bst->_root->right->key)) ketemu = 1;
    else hitung_kambing (bst->_root->left, tebakan);
}


int main()
{
    BST kambingbapak;
    bst_init(&kambingbapak);

    int kambingputar;
    scanf("%d", &kambingputar);

    
    while (kambingputar--)
    {
        int kelompok_kambing;
        scanf("%d", &kelompok_kambing);
        bst_insert(&kambingbapak, kelompok_kambing);
    }

    int tebakan_total_kambing;
    scanf("%d", &tebakan_total_kambing);
    hitung_kambing_primary(&kambingbapak, tebakan_total_kambing);
    
    if (ketemu) printf("ManTap");
    else printf("HAiiyyaAhh SalAhh");

    return 0;
}