#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct treenode_t {
    int key;
    struct treenode_t 
        *left, *right;
} TREENode;

typedef struct tree_t {
    TREENode *_root;
    unsigned int _size;
} TREE;

TREENode* __TREE__createNode(int value) {
    TREENode *newNode = (TREENode*) malloc(sizeof(TREENode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TREENode* __TREE__insert(TREENode *root, int value) {
    if (root == NULL) 
        return __TREE__createNode(value);

    if (value < root->key)
        root->left = __TREE__insert(root->left, value);
    else if (value > root->key)
        root->right = __TREE__insert(root->right, value);
    
    return root;
}

TREENode* __TREE__search(TREENode *root, int value) {
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

TREENode* __TREE__findMinNode(TREENode *node) {
    TREENode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}

TREENode* __TREE__remove(TREENode *root, int value) {
    if (root == NULL) return NULL;

    if (value > root->key) 
        root->right = __TREE__remove(root->right, value);
    else if (value < root->key) 
        root->left = __TREE__remove(root->left, value);
    else {
        
        if (root->left == NULL) {
            TREENode *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL) {
            TREENode *leftChild = root->left;
            free(root);
            return leftChild;
        }

        TREENode *temp = __TREE__findMinNode(root->right);
        root->key     = temp->key;
        root->right   = __TREE__remove(root->right, temp->key);
    }
    return root;
}

void __TREE__inorder(TREENode *root) {
    if (root) {
        __TREE__inorder(root->left);
        printf("%d ", root->key);
        __TREE__inorder(root->right);
    }
}

void __TREE__postorder(TREENode *root) {
    if (root) {
        __TREE__postorder(root->left);
        __TREE__postorder(root->right);
        printf("%d ", root->key);
    }
}

void __TREE__preorder(TREENode *root) {
    if (root) {
        printf("%d ", root->key);
        __TREE__preorder(root->left);
        __TREE__preorder(root->right);
    }
}

void TREE_init(TREE *TREE) {
    TREE->_root = NULL;
    TREE->_size = 0u;
}

bool TREE_isEmpty(TREE *TREE) {
    return TREE->_root == NULL;
}

bool TREE_find(TREE *TREE, int value) {
    TREENode *temp = __TREE__search(TREE->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

void TREE_insert(TREE *TREE, int value) {
    if (!TREE_find(TREE, value)) {
        TREE->_root = __TREE__insert(TREE->_root, value);
        TREE->_size++;
    }
}

void TREE_remove(TREE *TREE, int value) {
    if (TREE_find(TREE, value)) {
        TREE->_root = __TREE__remove(TREE->_root, value);
        TREE->_size--;
    }
}

void TREE_inorder(TREE *TREE) {
    __TREE__inorder(TREE->_root);
}

void TREE_postorder(TREE *TREE) {
    __TREE__postorder(TREE->_root);
}

void TREE_preorder(TREE *TREE) {
    __TREE__preorder(TREE->_root);
}

TREENode *cari(TREENode *root,int data){
	if(root==NULL) return NULL;
	else if(data < root->key) return (cari(root->left,data));
	else if(data > root->key) return (cari(root->right,data));
	else if(data == root->key) return root;
}

TREENode *FindMin(TREENode *root)
{
	if(root == NULL)
		return NULL;
	else
		if(root->left == NULL)
			return root;
		else
			return FindMin(root->left);
}

void leaf(TREENode *root){
	if(root == NULL) printf("kosong!");
	if(root->left!=NULL) leaf(root->left);
	if(root->right!=NULL) leaf(root->right);
    if(root->right == NULL && root->left == NULL) printf("%d ",root->key);
}


int main()
{
    TREE pohon;
    TREE_init(&pohon);

    int menu, data;
    do{
        printf("menu:\n");
        printf("1 = exit\n");
        printf("2 = insert\n");
        printf("3 = hapus \n");
        printf("4 = inorder \n");
        printf("5 = preorder \n");
        printf("6 = postorder \n");
        printf("7 = cari \n");
        printf("8 = find min \n");
        printf("9 = leaf \n");
        scanf("%d", &menu);

        if(menu== 2){
            printf("\n");
            printf("Masukan data: ");
            scanf("%d", &data);
            TREE_insert(&pohon, data);
        }
        else if(menu == 3){
            printf("\n");
            printf("Hapus data: ");
            scanf("%d", &data);
            TREE_remove(&pohon, data);
        }
        else if(menu == 4){
            TREE_inorder(&pohon);
            puts("");
        }
        else if(menu == 5){
            TREE_preorder(&pohon);
            puts("");
        }
        else if(menu == 6){
            TREE_postorder(&pohon);
            puts("");
        }
        else if(menu == 7){
            printf("\n");
            printf("Cari data: ");
            scanf("%d", &data);
            cari(&pohon, data);
        }
        else if(menu == 8){
            FindMin(&pohon);
        }
        else if(menu == 9){
            leaf(&pohon);
        }
    } while (menu != 1);
    
    
    return 0;
}