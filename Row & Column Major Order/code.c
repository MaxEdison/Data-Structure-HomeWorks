// AmirHossein Heidari - Max Edison

#include <stdio.h>

int main()
{
    int x[4][3][2];
    int number = 0, d, r, c;

    printf("enter i : ");
    scanf("%d", &d);
    printf("enter j : ");
    scanf("%d", &r);
    printf("enter k : ");
    scanf("%d", &c);

    //initialzing array in Row Major Order

    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            for (int k = 0; k <= 1; k++)
            {
                number++;
                x[i][j][k] = number;
            }   
        }   
    }

    //print result in Row Major Order
    printf("\nRow Major Order    : x[%d][%d][%d] = %d\n", d, r, c, x[d-1][r-1][c-1]);


    //initialzing array in Column Major Order

    number = 0;
    for (int k = 0; k <= 1; k++)
    {
        for (int j = 0; j <= 2; j++)
        {
            for (int i = 0; i <= 3; i++)
            {
                number++;
                x[i][j][k] = number;
            }
        }
    }

    //print result in Column Major Order
    printf("Column Major Order : x[%d][%d][%d] = %d", d, r, c, x[d-1][r-1][c-1]);

    return 0;
}