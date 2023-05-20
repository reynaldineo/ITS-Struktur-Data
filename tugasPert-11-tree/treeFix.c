#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tree {
    int data;
    struct Tree *left;
    struct Tree *right;
} Tree;

int isEmpty(Tree *pohon){
    if(pohon == NULL) return 1;
    else return 0; 
}

int init(Tree *pohon){
    pohon = NULL;
}

void tambah(Tree **root,int databaru){
	if((*root) == NULL){
		Tree *baru;
		// baru = new Tree;
        baru = (Tree*) malloc(sizeof(Tree));
		baru->data = databaru;
		baru->left = NULL;
		baru->right = NULL;
		(*root) = baru;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else if(databaru < (*root)->data)
		tambah(&(*root)->left,databaru);
	else if(databaru > (*root)->data)
		tambah(&(*root)->right,databaru);
	else if(databaru == (*root)->data)
		printf("Data sudah ada!");
} 

void preOrder(Tree *root){
    if(root != NULL){
        printf("%d", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Tree *root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d", root->data);
        inOrder(root->right);
    }
}

void postOrder(Tree *root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d", root->data);
    }
}

Tree *cari(Tree *root,int data){
	if(root==NULL) return NULL;
	else if(data < root->data) return (cari(root->left,data));
	else if(data > root->data) return (cari(root->right,data));
	else if(data == root->data) return root;
}

int count(Tree *root)
{
	 if (root == NULL) return 0;
	 return count(root->left) + count(root->right) + 1;
}

int height(Tree *root)
{
	 if (root == NULL) return -1;
	 int u = height(root->left), v = height(root->right);
	 if (u > v) return u+1;
	 else return v+1;
}

Tree *FindMin(Tree *root)
{
	if(root == NULL)
		return NULL;
	else
		if(root->left == NULL)
			return root;
		else
			return FindMin(root->left);
}

void leaf(Tree *root){
	if(root == NULL) printf("kosong!");
	if(root->left!=NULL) leaf(root->left);
	if(root->right!=NULL) leaf(root->right);
    if(root->right == NULL && root->left == NULL) printf("%d ",root->data);
}

int main(){
    Tree* pohon;
    init(pohon);
    printf("Jumlah data: ");
    int jumlahData;
    scanf("%d", &jumlahData);
    while (jumlahData--){
        int data;
        scanf("%d", &data);
        tambah(pohon, data);
    }
    inOrder(pohon);
    
}