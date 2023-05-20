#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mhs {
    char nrp[10];
    struct mhs *left;
    struct mhs *right;
} mhs;

mhs* input() {
    mhs* a = (struct mhs*)malloc(sizeof(struct mhs));
    printf("nrp: ");
    scanf("%s", a->nrp);
    a->left = NULL;
    a->right = NULL;
    return a;
}

void output(mhs* a) {
    printf("nrp = %s\n", a->nrp);
}

// void printInorder(mhs* a) {
//     if (a == NULL)
//         return;
//     printPreorder(a->left);
//     output(a);
//     printPreorder(a->right);
// }

// void printPostorder(mhs* a) {
//     if (a == NULL)
//         return;
//     printPreorder(a->left);
//     printPreorder(a->right);
//     output(a);
// }

void printPreorder(mhs* a) {
    if (a == NULL)
        return;
    output(a);
    printPreorder(a->left);
    printPreorder(a->right);
}

void freeTree(mhs* node) {
    if (node == NULL)
        return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

mhs* deleteNode(mhs* root, const char* nrp) {
    if (root == NULL)
        return root;

    if (strcmp(root->nrp, nrp) == 0) {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            mhs* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            mhs* temp = root->left;
            free(root);
            return temp;
        } else {
            mhs* parent = root;
            mhs* temp = root->right;
            while (temp->left != NULL) {
                parent = temp;
                temp = temp->left;
            }
            strcpy(root->nrp, temp->nrp);
            if (parent->left == temp)
                parent->left = deleteNode(parent->left, temp->nrp);
            else
                parent->right = deleteNode(parent->right, temp->nrp);
        }
    } else if (strcmp(root->nrp, nrp) < 0) {
        root->right = deleteNode(root->right, nrp);
    } else {
        root->left = deleteNode(root->left, nrp);
    }
    
    return root;
}


int main() {
    mhs* data;
    // printf("Masukan jumlah data yg ingin di input: ");
    // int banyakData;
    // scanf("%d", &banyakData);
    // while(banyakData--){
    //     data = input();
    // }
    data = input();
    data->left = input();
    data->right = input();
    data->left->left = input();
    data->left->right = input();
    printPreorder(data);

    char nrpToDelete[10];
    printf("\nEnter the NRP to delete: ");
    scanf("%s", nrpToDelete);
    data = deleteNode(data, nrpToDelete);
    
    printf("\nAfter deletion:\n");
    printPreorder(data);
    
    // freeTree(data);
    
    system("pause");
    return 0;
}