#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

int maxStage = 0;

typedef struct AVLNode_t
{
    int key;
    int height;
    int strength;
    struct AVLNode_t *left, *right;
} AVLNode;

typedef struct avl_t
{
    int size;
    AVLNode *root;
} Avl;

AVLNode *createNode(int value, int str)
{
    AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
    newNode->key = value;
    newNode->height = 1;
    newNode->strength = str;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int getHeight(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

int max(int a, int b) { return (a > b) ? a : b; }

AVLNode *rightRotate(AVLNode *pivotNode)
{

    AVLNode *newParrent = pivotNode->left;
    pivotNode->left = newParrent->right;
    newParrent->right = pivotNode;

    pivotNode->height = max(getHeight(pivotNode->left), getHeight(pivotNode->right)) + 1;
    newParrent->height = max(getHeight(newParrent->left), getHeight(newParrent->right)) + 1;

    return newParrent;
}

AVLNode *leftRotate(AVLNode *pivotNode)
{

    AVLNode *newParrent = pivotNode->right;
    pivotNode->right = newParrent->left;
    newParrent->left = pivotNode;

    pivotNode->height = max(getHeight(pivotNode->left), getHeight(pivotNode->right)) + 1;
    newParrent->height = max(getHeight(newParrent->left), getHeight(newParrent->right)) + 1;

    return newParrent;
}

AVLNode *leftCaseRotate(AVLNode *node)
{
    return rightRotate(node);
}

AVLNode *rightCaseRotate(AVLNode *node)
{
    return leftRotate(node);
}

AVLNode *leftRightCaseRotate(AVLNode *node)
{
    node->left = leftRotate(node->left);
    return rightRotate(node);
}

AVLNode *rightLeftCaseRotate(AVLNode *node)
{
    node->right = rightRotate(node->right);
    return leftRotate(node);
}

int getBalanceFactor(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

AVLNode *insert(AVLNode *node, int value, int str)
{
    if (node == NULL)
        return createNode(value, str);
    if (value < node->key)
        node->left = insert(node->left, value, str);
    else if (value > node->key)
        node->right = insert(node->right, value, str);

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor > 1 && value < node->left->key)
        return leftCaseRotate(node);
    if (balanceFactor > 1 && value > node->left->key)
        return leftRightCaseRotate(node);
    if (balanceFactor < -1 && value > node->right->key)
        return rightCaseRotate(node);
    if (balanceFactor < -1 && value < node->right->key)
        return rightLeftCaseRotate(node);

    return node;
}

AVLNode *search(AVLNode *root, int value)
{
    while (root != NULL)
    {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

void avl_init(Avl *avl)
{
    avl->size = 0;
    avl->root = NULL;
}

bool avl_find(Avl *avl, int value)
{
    AVLNode *temp = search(avl->root, value);
    if (temp == NULL)
        return false;

    if (temp->key == value)
        return true;
    else
        return false;
}

void avl_insert(Avl *avl, int value, int str)
{
    if (!avl_find(avl, value))
    {
        avl->root = insert(avl->root, value, str);
        avl->size++;
    }
}

// Function
void getMaxStage(AVLNode *root)
{
    if (root)
    {
        maxStage++; // ngitung berapa jmlh stagenya
        getMaxStage(root->right); // karena model transversal di soal setiap ke kanan naik 1 stage
    }
}

void getStatus(AVLNode *root, int ind, int key[MAX][MAX], int strength[MAX][MAX], int sum[MAX], int last[MAX])
{
    if (root)
    {
        getStatus(root->left, ind, key, strength, sum, last);
        key[ind][last[ind]] = root->key;
        strength[ind][last[ind]] = root->strength;
        sum[ind] += root->strength;
        last[ind]++;
        getStatus(root->right, ind + 1, key, strength, sum, last);
    }
}

bool checkWin(AVLNode *root, int *stage, char *nama_Planet, int powerUltraMan)
{
    int key[MAX][MAX], strength[MAX][MAX], sum[MAX], last[MAX];
    memset(sum, 0, sizeof(sum));
    memset(last, 0, sizeof(last));
    getStatus(root, 0, key, strength, sum, last);

    for (int i = 0; i < maxStage; i++)
    {
        if (i == maxStage - 1) // kalau udh perulangan terakhir alias masuk Final stage
        {
            printf("Final Stage:\n");
            for (int j = 0; j < last[i]; j++)
                printf("Boss %s_%d: %d\n", nama_Planet, key[i][j], strength[i][j]);
        }
        else
        {
            printf("Stage %d:\n", i + 1);
            for (int j = 0; j < last[i]; j++)
            {
                char code = 'A' + j;
                printf("Monster %c%d_%d_%d: %d\n", code, key[i][j], i + 1, j + 1, strength[i][j]);
            }
            printf("=>\n");
        }
        if (powerUltraMan % 2 == 0) 
            sum[i] *= 0.9; // damage musuh kurang 10%
        else                
            sum[i] *= 0.8; // damage musuh kurang 20%
        powerUltraMan -= sum[i];
        if (powerUltraMan > 0)
            (*stage)++; // ngitung jumlah stage yg di lewati
    }

    if (powerUltraMan > 0) // kalau sampai akhir masih ada power
        return true; // berarti menang sampai akhir
    else
        return false; // berarti kalah di suatu stage
}

int main()
{
    Avl myAvl;
    avl_init(&myAvl);

    int nJumlah, powerUltraMan, keyMusuh, damageMusuh, stage = 1;
    char namaPlanet[100];
    scanf("%d %d %s", &nJumlah, &powerUltraMan, namaPlanet);

    while(nJumlah--)
    {
        scanf("%d%d", &keyMusuh, &damageMusuh);
        avl_insert(&myAvl, keyMusuh, damageMusuh);
    }

    getMaxStage(myAvl.root); // buat dapetin maxStage

    printf("Ultraman lapet(Power: %d)\nPlanet: %s\n-----------------------\n", powerUltraMan, namaPlanet);

    if (checkWin(myAvl.root, &stage, namaPlanet, powerUltraMan)) // bisa menang sampai akhir ga?
        printf("\nResult:\nUltraman Lapet lolos dari Planet %s", namaPlanet);
    else
    {
        if (stage == maxStage) // kalau stage yg di lewati == maxStage
            printf("\nResult:\nUltraman Lapet terperangkap di Planet %s pada Final Stage", namaPlanet);
        else // kalau engga ya berarti kalah
            printf("\nResult:\nUltraman Lapet terperangkap di Planet %s pada Stage %d", namaPlanet, stage);
    }
    return 0;
}