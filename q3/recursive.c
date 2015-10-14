#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode *right;
    struct TreeNode *left;
} node;

void build_tree(node ** root, int num)
{
    if ((*root) == NULL) {
        node * tmp;
        tmp = (node *) malloc(sizeof(node));
        tmp->value = num;
        tmp->left = NULL;
        tmp->right = NULL;
        (*root) = tmp;
        return;
    }
    if (num >= (*root)->value)
        build_tree(&((*root)->right), num);
    else
        build_tree(&((*root)->left), num);
}

void flatten(node * root)
{
    if (root == NULL)
        return;
    flatten(root->right);
    flatten(root->left);
    if (root->left == NULL)
        return;
    node *tmp = root->left;
    while (tmp->right != NULL) {
        tmp = tmp->right;
    }
    tmp->right = root->right;
    root->right = root->left;
    root->left = NULL;
    //printf("%d\n", root->value);
}

int main()
{
    int num = 0;
    node * root = NULL;
    while (scanf("%d", &num)) {
        if (num == 0)
            break;
        build_tree(&root, num);
    }
    flatten(root);
    while (root != NULL) {
        printf("%d\n", root->value);
        root = root->right;
    }
    return 0;
}
