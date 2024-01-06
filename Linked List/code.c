///////////////////////////////////////
/* AmirHossein Heidari - Max Edison */
/*           Linked List           */
////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};


int main()
{
    int input;

    struct node *start = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    temp = start;

    printf("Please enter 10 integers: \n");
    printf("> Number : ");
    scanf("%d", &input);    
    
    start->data = input;
    start->next = NULL;

    for (int i = 0; i < 9; i++)
    {
        struct node *Node = (struct node *)malloc(sizeof(struct node));

        printf("> Number : ");
        scanf("%d", &input);  

        Node->data = input;
        Node->next = NULL;
        temp->next = Node;
        temp = Node;
    }
    
    /*printf("> Your Linked List : \n");
    for (int i = 0; i < 10; i++)
    {
        if (i == 9)
            printf("%d\n", start->data);
        else
            printf("%d --> ", start->data);

        start = start->next;
    }*/

    printf("Please Enter n : ");
    scanf("%d", &input);

    printf("Result : \n");

    while (start != NULL)
    {
        if (start->data % input == 0)
            printf("%d\n", start->data);

        start = start->next;
    }

    return 0;
}
