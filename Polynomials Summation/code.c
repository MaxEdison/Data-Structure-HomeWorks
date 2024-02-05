///////////////////////////////////////
/* AmirHossein Heidari - Max Edison */
/*     Polynomials Summation       */
////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int multipler;
    int power;

    struct node *next;
};

int main()
{
    struct node *startA = (struct node *)malloc(sizeof(struct node));
    struct node *startB = (struct node *)malloc(sizeof(struct node));
    struct node *startResult = (struct node *)malloc(sizeof(struct node));

    struct node *res = startResult;
    struct node *a = startA;
    struct node *b = startB;    

    printf("Enter the first polynomial: \n");

    while (1)
    {
        scanf("%d %d", &a->multipler, &a->power);

        if (a->multipler == 0 || a->power == 0)
            break;

        a->next = (struct node *)malloc(sizeof(struct node));

        a = a->next;
        a->next = NULL;
    }

    printf("Enter the second polynomial: \n");

    while (1)
    {
        scanf("%d %d", &b->multipler, &b->power);
        
        if (b->multipler == 0 || b->power == 0)
            break;
        
        b->next = (struct node *)malloc(sizeof(struct node));

        b = b->next;
        b->next = NULL;
    }
    
    a = startA;
    b = startB;

    while (a != NULL && b != NULL)
    {
        if (a->power > b->power)
        {
            res->multipler = a->multipler;
            res->power = a->power;

            res->next = (struct node *)malloc(sizeof(struct node));
            res = res->next;
            res->next = NULL;

            a = a->next;
        }
        else if (a->power == b->power)
        {
            res->multipler = a->multipler + b->multipler;
            res->power = a->power;

            res->next = (struct node *)malloc(sizeof(struct node));
            res = res->next;
            res->next = NULL;

            a = a->next;
            b = b->next;
        }
        else
        {
            res->multipler = b->multipler;
            res->power = b->power;

            res->next = (struct node *)malloc(sizeof(struct node));
            res = res->next;
            res->next =NULL;

            b = b->next;
        }
    }
    
    while (a != NULL)
    {
        res->multipler = a->multipler;
        res->power = a->power;

        res->next = (struct node *)malloc(sizeof(struct node));
        res = res->next;
        res->next = NULL;

        a = a->next;
    }
    
    while (b != NULL)
    {
        res->multipler = b->multipler;
        res->power = b->power;

        res->next = (struct node *)malloc(sizeof(struct node));
        res = res->next;
        res->next = NULL;

        b = b->next;
    }


    res = startResult;

    while (res != NULL)
    {
//      printf("\n[TEST] %d \n", res->power);
        if (res->multipler == 0)
            res = res->next;

        else if (res->power == 0)
        {
            printf("%d ", res->multipler);
            res = res->next;

            if (res->next != NULL)
                printf("+ ");
        }

        else if (res->power == 1)
        {
            printf("%dx ", res->multipler);
            res = res->next;
            
            if (res->next != NULL)
                printf("+ ");
        }

        else
        {
            printf("%dx^%d ", res->multipler, res->power);
            res = res->next;
            
            if (res->next != NULL)
                printf("+ ");
        }
    }
    
    return 0;
}