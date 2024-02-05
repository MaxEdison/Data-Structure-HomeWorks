///////////////////////////////////////////////
/*   AmirHossein Heidari  -  Max Edison     */
/* Iterative Preorder Traversal Binary Tree*/
////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct Stack
{
    int top;
    struct node *s[100];
};

int IsEmpty(struct Stack *stack)
{
    if (stack->top == -1)
        return 1;
    else
        return 0;
}

void Push(struct node *item, struct Stack *stack)
{
    stack->top++;
    stack->s[stack->top] = item;
}

struct node *Pop(struct Stack *Stack)
{
    if (IsEmpty(Stack))
    {
        printf("Stack Underflow");
        return NULL;
    }
    else
        return Stack->s[Stack->top--];
}

void preorderTraversal(struct node *root, struct Stack *stack)
{
    struct node *temp;

    Push(root, stack);
    while (!IsEmpty(stack))
    {
        temp = Pop(stack);
        printf("%d ", temp->data);

        if (temp->right == NULL && temp->left == NULL)
            continue;

        else
        {
            if (temp->right != NULL)
                Push(temp->right, stack);

            if (temp->left != NULL)
                Push(temp->left, stack);
        }
    }
}

int main()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;

    // initializing the binary tree

    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = 1;
    root->left = (struct node *)malloc(sizeof(struct node));
    root->right = (struct node *)malloc(sizeof(struct node));
    root->left->data = 2;
    root->right->data = 3;
    root->left->left = (struct node *)malloc(sizeof(struct node));
    root->left->right = (struct node *)malloc(sizeof(struct node));
    root->right->left = (struct node *)malloc(sizeof(struct node));
    root->right->right = (struct node *)malloc(sizeof(struct node));
    root->left->left->data = 4;
    root->left->right->data = 5;
    root->right->left->data = 6;
    root->right->right->data = 7;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->left->right->left = (struct node *)malloc(sizeof(struct node));
    root->left->right->right = (struct node *)malloc(sizeof(struct node));
    root->right->right->left = (struct node *)malloc(sizeof(struct node));
    root->right->right->right = (struct node *)malloc(sizeof(struct node));
    root->left->right->left->data = 8;
    root->left->right->right->data = 9;
    root->right->right->left->data = 10;
    root->right->right->right->data = 11;
    root->left->right->left->left = NULL;
    root->left->right->left->right = NULL;
    root->left->right->right->left = NULL;
    root->left->right->right->right = NULL;
    root->right->right->left->left = NULL;
    root->right->right->left->right = NULL;
    root->right->right->right->left = NULL;
    root->right->right->right->right = NULL;

    preorderTraversal(root, stack);

    return 0;
}
