#include <stdio.h>
#include <math.h>

#define X 5
#define T 5

float fun(int x)
{
    return x * x * (5 - x);
}

int main()
{
    float u[X + 1][T + 1], ut, h = 1.0, k = 0.0125, c, al, us, ue;
    int i, j;
    printf("\nEnter the square of c: ");
    scanf("%f", &c);

    al = c * k / pow(h, 2);

    printf("Enter the value of u[0][t]: ");
    scanf("%f", &ut);

    printf("Enter the value of u[%d][t]: ", X);
    scanf("%f", &ue);

    int number = 0;

    printf("\nIndex...\n1. Heat Equation\n2. Wave Equation");
    printf("\nChoose your Number: ");
    scanf("%d", &number);

    switch (number)
    {
    case 1:
        for (i = 0; i <= T; i++)
        {
            u[0][i] = u[X][i] = us;
        }
        for (j = 1; j <= X - 1; j++)
        {
            u[j][0] = fun(j);
        }
        for (i = 0; i <= T - 1; i++)
        {
            for (j = 1; j <= X - 1; j++)
            {
                u[j][i + 1] = al * u[j - 1][i] + (1 - 2 * al) * u[j][i] + al * u[j + 1][i];
            }
        }
        printf("The value of alpha is %4.2f\n", al);
        printf("The value of u[j,i] are:\n");
        for (i = 0; i < T; i++)
        {
            for (j = 0; j < X; j++)
            {
                printf("%7.4f\t", u[j][i]);
            }
            printf("\n");
        }
        break;

    case 2:
        for (j = 0; j <= T; j++)
        {
            u[0][j] = ut;
            u[X][j] = ue;
        }
        for (i = 1; i <= X - 1; i++)
        {
            u[i][1] = u[i][0] = fun(i);
        }
        for (j = 1; j <= T - 1; j++)
        {
            for (i = 1; i <= X - 1; i++)
            {
                u[i][j + 1] = u[i - 1][j] + u[i + 1][j] - u[i][j - 1];
            }
        }
        printf("The values of u[i][j] are:\n");
        for (j = 0; j <= T; j++)
        {
            for (i = 0; i <= X; i++)
            {
                printf("%6.1f", u[i][j]);
            }
            printf("\n");
        }
        break;

    default:
        printf("Choose from 1 or 2: ");
        break;
    }

    return 0;
}