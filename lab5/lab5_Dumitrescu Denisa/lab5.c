#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int data;
    struct node *leftChild;
    struct node *rightChild;
};

struct node *root = NULL;
int array[10];
int i = 0;

int visit(int data)
{
    array[i] = data;
    printf("%d ", array[i]);
    i++;
}

void inOrderTraversal(struct node *tree)
{
    if (tree != NULL)
    {
        inOrderTraversal(tree->leftChild);
        visit(tree->data);
        inOrderTraversal(tree->rightChild);
    }
}

int isSearch(int array[10])
{
    int ok = 1;
    for (int j = 0; j < 10; j++)
    {
        if (array[i] > array[i + 1])
            ok = 0;
    }
    return ok;
}

void preOrderTraversal(struct node *tree)
{
    if (tree != NULL)
    {
        visit(tree->data);
        preOrderTraversal(tree->leftChild);
        preOrderTraversal(tree->rightChild);
    }
}

int isBalanced1(int array[10])
{
    int level_left = 1, level_right = 1;
    for (int j = 1; j < 9; j++)
    {
        if (array[0] > array[j] && array[0] > array[j + 1])
        {
            if (array[j] > array[j + 1])
                level_left++;
            // printf("L %d ", level_left);
        }
        else
        {
            if (array[j] > array[j + 1])
                level_right++;
            // printf("\n R %d ", level_right);
        }
    }
    // printf(" %d %d ", level_left, level_right);
    level_left = level_left / 2;
    level_right = level_right / 2;
    if (level_left - level_right == 0 || level_right - level_left == 1 || level_left - level_right == 1)
        return 1;
    else
        return 0;
}

int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

int tree_height(struct node *node)
{
    if (node == NULL)
        return 0;

    return 1 + max(tree_height(node->leftChild), tree_height(node->rightChild));
}

int isBalanced2(struct node *node)
{

    int lh, rh, hd;

    if (node == NULL)
        return 1;

    lh = tree_height(node->leftChild);
    rh = tree_height(node->rightChild);

    hd = abs(lh - rh);

    if (hd <= 1 && isBalanced2(node->leftChild) && isBalanced2(node->rightChild))
        return 1;

    return 0;
}

void postOrderTraversal(struct node *tree)
{
    if (tree != NULL)
    {
        postOrderTraversal(tree->leftChild);
        postOrderTraversal(tree->rightChild);
        visit(tree->data);
    }
}

struct node *lca(struct node *node, int x, int y)
{
    if (node != NULL)
    {
        if (node->data == x || node->data == y)
        {
            return node;
        }
        struct node *left = lca(node->leftChild, x, y);
        struct node *right = lca(node->rightChild, x, y);
        if (left != NULL && right != NULL)
        {
            return node;
        }
        if (left != NULL)
        {
            return left;
        }
        return right;
    }
    else
    {
        return NULL;
    }
}

// insert binary search tree
void insertSearch(int data)
{
    struct node *tempNode = (struct node *)malloc(sizeof(struct node));
    struct node *current;
    struct node *parent;

    tempNode->data = data;
    tempNode->leftChild = NULL;
    tempNode->rightChild = NULL;

    // arbore gol
    if (root == NULL)
    {
        root = tempNode;
    }
    else
    {
        current = root;
        parent = NULL;
        while (1)
        {
            parent = current;

            // subarbore stanga
            if (data < parent->data)
            {
                current = current->leftChild;
                // insert la stanga
                if (current == NULL)
                {
                    parent->leftChild = tempNode;
                    return;
                }
            }
            else
            {
                // subarbore dreapta
                current = current->rightChild;
                // insert la dreapta
                if (current == NULL)
                {
                    parent->rightChild = tempNode;
                    return;
                }
            }
        }
    }
}

int main()
{
    int data;
    int v[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &data);
        insertSearch(data);
    }
    // printf("In: ");
    //  inOrderTraversal(root);
    //  printf("%d ",isSearch(array));
    // printf("\nPre: ");
    // preOrderTraversal(root);
    // printf("\n");
    // printf("%d", isBalanced2(root));
    printf("\nPost: ");
    postOrderTraversal(root);
    printf("\n");
    printf("%d", lca(root, 14, 17)->data);
    printf("\n");
}
