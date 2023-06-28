#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n, i, j;
    float x[10], y[10][10], f,ch = 30, num, den;

    /* Input Section */
    printf("Enter number of data: ");
    scanf("%d", &n);
    printf("Enter data:\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d]=", i);
        scanf("%f", &x[i]);
        printf("y[%d]=", i);
        scanf("%f", &y[i][0]);
    }

    // Construct the divided difference table
    for (j = 1; j < n; j++)
    {
        for (i = 0; i < n - j; i++)
        {
            y[i][j] = (y[i + 1][j - 1] - y[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    // Display the divided difference table
    printf("\nDivided Difference Table:\n");
    printf("\nX\tY");
    for (i = 0; i < n - 1; i++)
        printf("\t%c^%dY", ch, i + 1);
        printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("%.2f\t", x[i]);
        for (j = 0; j < n - i; j++)
        {
            printf("%.2f\t", y[i][j]);
        }
        printf("\n");
    }

    // Evaluate the polynomial using the divided difference formula
    printf("\nEnter the value of x for which f(x) is to be calculated: ");
    scanf("%f", &num);

    f = y[0][0];
    for (i = 1; i < n; i++)
    {
        den = 1;
        for (j = 0; j < i; j++)
        {
            den *= (num - x[j]);
        }
        f += y[0][i] * den;
    }

    printf("\nThe value of f(%.2f) is: %f\n", num, f);

    return 0;
}