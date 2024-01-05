// AmirHossein Heidari - Max Edison

//Implementation a Queue using Two Stacks

#include <stdio.h>

struct Stack     //Defining Stack
{
    int top ;
    int s[10];
};

int IsEmpty1(struct Stack* S1)  //Check if stack is empty
{
    if (S1->top == -1)
        return 1;
    else
        return 0;
}

int IsFull1(struct Stack* S1)  //Check if stack is full
{
    if (S1->top == 9)
        return 1;
    else
        return 0;
}

int IsEmpty2(struct Stack* S2)  //Check if stack is empty
{
    if (S2->top == -1)
        return 1;
    else
        return 0;
}

int IsFull2(struct Stack* S2)  //Check if stack is full
{
    if (S2->top == 9)
        return 1;
    else
        return 0;
}

void Push1(struct Stack* S1, int x)  //Push to stack
{
    if (S1->top == 9)
        printf("[!] Stack Overflow\n");

    else
    {
        printf("[...] Pushing %d to Stack 1\n", x);

        S1->top++;
        S1->s[S1->top] = x;

        printf("[+] Pushed %d\n", x);
    }
}

void Push2(struct Stack* S2, int x)  //Push to stack
{
    if (S2->top == 9)
        printf("[!] Stack Overflow\n");

    else
    {
        printf("[...] Pushing %d to Stack 2\n", x);

        S2->top++;
        S2->s[S2->top] = x;

        printf("[+] Pushed %d\n", x);
    }
}

int Pop1(struct Stack* S1)  //Pop from stack
{
    if (S1->top == -1)
    {
        printf("[!] Stack Underflow\n");
        return 0;
    }

    else
    {
        printf("[...] Popping %d from Stack 1\n", S1->s[S1->top]);
        printf("[+] Popped %d\n", S1->s[S1->top]);

        return S1->s[S1->top--];
    }
}

int Pop2(struct Stack* S2)  //Pop from stack
{
    if (S2->top == -1)
        printf("[!] Stack Underflow\n");

    else
        printf("[...] Popping %d from Stack 2\n", S2->s[S2->top]);
        printf("[+] Popped %d\n", S2->s[S2->top]);

        return S2->s[S2->top--];
}

void EnQueue(struct Stack* S1, struct Stack* S2, int x)  //EnQueue (Add x to queue)
{
    if (IsEmpty2(S2))
    {
        if (!IsFull1(S1))
        {
            Push1(S1, x);
        }

        else
        {
            printf("[!] Queue Overflow\n");
        }
    }

    else if (!IsEmpty2(S2))
    {
        while (S2->top != -1)
        {
            Push1(S1, Pop2(S2));
        }

        Push1(S1, x);
    } 
}

void DeQueue(struct Stack* S1, struct Stack* S2)  //DeQueue (Remove from queue)
{
    if (IsEmpty2(S2))
    {
        while (S1->top != -1)
        {
            Push2(S2, Pop1(S1));
        }

        if (!IsEmpty2(S2))
        {
            Pop2(S2);
        } 

        else
        {
            printf("[!] Queue Underflow\n");
        }
    }

    else if (!IsEmpty2(S2))
    {
        Pop2(S2);
    }
}

int Size1(struct Stack* S1)  //Size of Stack
{
    return S1->top + 1;
}

int Size2(struct Stack* S2)  //Size of Stack
{
    return S2->top + 1;
}

int IsEmpty(struct Stack* S1, struct Stack* S2)  //Check if queue is empty
{
    if (Size1(S1) + Size2(S2) == 0)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int IsFull(struct Stack* S1, struct Stack* S2)  //Check if queue is full
{
    if (Size1(S1) + Size2(S2) == 10)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void main()
{
    struct Stack S1, S2;  //Stacks
    const int TRUE = 1;
    char input;
    int value;

    S1.top = -1;
    S2.top = -1;

    printf("\n*!Welcome to the Queue!*\n");
    printf("- Enter 'q' to quit.\n");
    printf("- Enter 'e' to enqueue.\n");
    printf("- Enter 'd' to dequeue.\n");
    printf("- Enter 'f' to check Full.\n");
    printf("- Enter 'm' to check Empty.\n");

    while (TRUE) 
    {
        printf("\n");
        scanf(" %c", &input);

        if (input == 'q') 
        {
            printf("[!] Quitting...\n");
            break;
        } 

        else if (input == 'e') 
        {
            printf("> Enter a value: ");
            scanf("%d", &value);
            printf("\n");

            EnQueue(&S1, &S2, value);
        } 

        else if (input == 'd') 
        {
            DeQueue(&S1, &S2);
        } 
        
        else if (input == 'f')
        {
            if (IsFull(&S1, &S2))
            {
                printf("[+] Queue is Full !\n");
            }
            else
            {
                printf("[-] Queue is NOT Full !\n");
            }
        }
        
        else if (input == 'm')
        {
            if (IsEmpty(&S1, &S2))
            {
                printf("[+] Queue is Empty !\n");
            }
            else
            {
                printf("[-] Queue is NOT Empty !\n");
            }
        }
        
        else 
        {
            printf("Try again!\n");
        }
    }
    
    printf("[+] Goodbye!\n");
}
