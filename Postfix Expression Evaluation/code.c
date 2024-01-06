   //////////////////////////////////////
  // AmirHossein Heidari - Max Edison //
 // Postfix Expression ////////////////
////////////////////////

#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Stack
{
    int top;
    char s[100];
};

/*char peek(struct Stack *S, int index)
{
    if (S->top == -1)
        return 101010;
    else
        return S->s[index];
}*/

int Pow(int a, int b)
{
    int result = 1;
    for (int i = 0; i < b; i++)
        result *= a;

    return result;
}

void Push(struct Stack *S, int expression)
{
    if (S->top == 99)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        S->top++;
        S->s[S->top] = expression;
    }
}

char pop(struct Stack *S)
{
    if (S->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        char temp = S->s[S->top];
        S->top--;
        return temp;
    }
}

/*void ShowStack(struct Stack *S, char *expression)
{
    for (int i = strlen(expression)-1; i >= 0; i--)
    {
        printf("\n[%d] %c\n", i, S->s[i]);
    }
}*/

void eval(struct Stack *S, char *expression)
{
    for (int i = 0; i < strlen(expression); i++)
    {
        char c = expression[i];
        if (isdigit(c))
            Push(S, c - '0');
        
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        {
            int op2 = pop(S);
            int op1 = pop(S);
            switch (c)
            {
            case '+':
                Push(S, op1 + op2);
                break;
            case '-':
                Push(S, op1 - op2);
                break;
            case '*':
                Push(S, op1 * op2);
                break;
            case '/':
                Push(S, op1 / op2);
                break;
            case '^':
                Push(S, Pow(op1, op2));
                break;
            default:
                printf("Error");
                break;
            }
        }
        else
            printf("Error");
    }
    printf("[RESULT] %d\n", pop(S));
}

int main()
{
    char expression[100];
    struct Stack *stack;
    stack->top = -1;

    scanf("%s", expression);
    eval(stack, expression);

    return 0;
}