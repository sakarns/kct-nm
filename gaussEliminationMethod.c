#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main()
{
    float a[SIZE][SIZE], x[SIZE], ratio, max;
    int i, j, k, n, row, col, temp, choice;

    /* Inputs */
    /* 1. Reading number of unknowns */
    printf("Enter number of unknowns: ");
    scanf("%d", &n);

    /* 2. Reading Augmented Matrix */
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n + 1; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
    printf("\n");
j:
    /* Choose method */
    printf("Index...\n");
    printf("1. Gauss Elimination\n");
    printf("2. Partial Pivoting\n");
    printf("3. Complete Pivoting\n");
    printf("4. Quit\n");
    printf("\nChoose a method: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        /* Applying Gauss Elimination */
        for (i = 1; i <= n - 1; i++)
        {
            if (a[i][i] == 0.0)
            {
                printf("Mathematical Error!");
                exit(0);
            }

            for (j = i + 1; j <= n; j++)
            {
                ratio = a[j][i] / a[i][i];

                for (k = 1; k <= n + 1; k++)
                {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }

        /* Obtaining Solution by Back Subsitution */
        x[n] = a[n][n + 1] / a[n][n];

        for (i = n - 1; i >= 1; i--)
        {
            x[i] = a[i][n + 1];

            for (j = i + 1; j <= n; j++)
            {
                x[i] = x[i] - a[i][j] * x[j];
            }

            x[i] = x[i] / a[i][i];
        }

        /* Displaying Solution */
        printf("\nSolution:\n");

        for (i = 1; i <= n; i++)
        {
            printf("x[%d] = %0.3f\n", i, x[i]);
        }
        printf("\n");
        break;

    case 2:
        /* Applying Partial Pivoting */
        for (i = 1; i <= n - 1; i++)
        {
            max = a[i][i];
            row = i;

            for (j = i + 1; j <= n; j++)
            {
                if (a[j][i] > max)
                {
                    max = a[j][i];
                    row = j;
                }
            }

            if (row != i)
            {
                for (k = 1; k <= n + 1; k++)
                {
                    temp = a[i][k];
                    a[i][k] = a[row][k];
                    a[row][k] = temp;
                }
            }

            for (j = i + 1; j <= n; j++)
            {
                ratio = a[j][i] / a[i][i];

                for (k = 1; k <= n + 1; k++)
                {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }

        /* Obtaining Solution by Back Subsitution */
        x[n] = a[n][n + 1] / a[n][n];

        for (i = n - 1; i >= 1; i--)
        {
            x[i] = a[i][n + 1];

            for (j = i + 1; j <= n; j++)
            {
                x[i] = x[i] - a[i][j] * x[j];
            }

            x[i] = x[i] / a[i][i];
        }

        /* Displaying Solution */
        printf("\nSolution:\n");

        for (i = 1; i <= n; i++)
        {
            printf("x[%d] = %0.3f\n", i, x[i]);
        }
        printf("\n");
        break;

    case 3:
        /* Applying Complete Pivoting */
        for (i = 1; i <= n; i++)
        {
            max = 0.0;

            for (j = i; j <= n; j++)
            {
                for (k = i; k <= n; k++)
                {
                    if (abs(a[j][k]) > max)
                    {
                        max = abs(a[j][k]);
                        row = j;
                        col = k;
                    }
                }
            }

            if (max == 0.0)
            {
                printf("Mathematical Error!");
                exit(0);
            }

            /* Interchanging Rows */
            if (row != i)
            {
                for (k = 1; k <= n + 1; k++)
                {
                    temp = a[i][k];
                    a[i][k] = a[row][k];
                    a[row][k] = temp;
                }
            }

            /* Interchanging Columns */
            if (col != i)
            {
                for (k = 1; k <= n; k++)
                {
                    temp = a[k][i];
                    a[k][i] = a[k][col];
                    a[k][col] = temp;
                }
            }

            for (j = i + 1; j <= n; j++)
            {
                ratio = a[j][i] / a[i][i];

                for (k = 1; k <= n + 1; k++)
                {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }

        /* Obtaining Solution by Back Subsitution */
        x[n] = a[n][n + 1] / a[n][n];

        for (i = n - 1; i >= 1; i--)
        {
            x[i] = a[i][n + 1];

            for (j = i + 1; j <= n; j++)
            {
                x[i] = x[i] - a[i][j] * x[j];
            }

            x[i] = x[i] / a[i][i];
        }

        /* Displaying Solution */
        printf("\nSolution:\n");

        for (i = 1; i <= n; i++)
        {
            printf("x[%d] = %0.3f\n", i, x[i]);
        }
        printf("\n");
        break;

    case 4:
        exit(0);

    default:
        printf("Invalid Choice!\n");
        break;
    }
    goto j;
}