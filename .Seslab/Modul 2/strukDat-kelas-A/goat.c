#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int found=0;

typedef struct bstnode_t {
    int key;
    struct bstnode_t *parent;
    struct bstnode_t *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode* _bst_createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->parent = NULL;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* _bst_insert(BSTNode *root, int value) {
    if (root == NULL) 
        return _bst_createNode(value);
    if (value < root->key){
    	root->left = _bst_insert(root->left, value);
        root->left->parent = root;
	}
    else if (value > root->key){
    	root->right = _bst_insert(root->right, value);
   		root->right->parent = root;
	}
    return root;
}

void _bst_transverse(BSTNode *root, int num) {
	//printf("%d", found);
	if(!found){
		if (root && (root->left || root->right)) 
		{
			if(root->left && root->right){
				if(num==(root->key + root->left->key + root->right->key)
				|| num==(root->key + root->parent->key + root->right->key)
				|| num==(root->key + root->left->key + root->parent->key))found=1;	
			    else{
			    	_bst_transverse(root->left, num);
			    	_bst_transverse(root->right, num);
				}
			}else if(!root->left){
				if(num==(root->key + root->parent->key + root->right->key))found=1;	
			    else{
			    	_bst_transverse(root->left, num);
			    	_bst_transverse(root->right, num);
				}
			}else if(!root->right){
				if(num==(root->key + root->parent->key + root->left->key))found=1;	
			    else{
			    	_bst_transverse(root->left, num);
			    	_bst_transverse(root->right, num);
				}
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
        bst->_root = _bst_insert(bst->_root, value);
        bst->_size++;
}

void transverse(BST *bst, int num) {
	if(num>(bst->_root->key + bst->_root->left->key + bst->_root->right->key))
	_bst_transverse(bst->_root->right, num);
	else if (num==(bst->_root->key + bst->_root->left->key + bst->_root->right->key))found=1;
	else _bst_transverse(bst->_root->left, num);
}

int main()
{	
	BST goat;
	bst_init(&goat);
	int q;
	scanf("%d", &q);
	while(q--){
		int kambing;
		scanf("%d", &kambing);
		bst_insert(&goat, kambing);
	}
	int guess;
	scanf("%d", &guess);
	transverse(&goat, guess);
	if(found)printf("ManTap");
	else printf("HAiiyyaAhh SalAhh");
    return 0;
}