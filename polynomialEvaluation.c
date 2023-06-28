#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

int main()
{
    float array[MAXSIZE];
    int i, num, power;
    float x, polySum;

    printf("Enter the order of the polynomial: \n");
    if (scanf("%d", &num) != 1 || num < 0 || num >= MAXSIZE)
    {
        printf("Invalid input for the order of the polynomial.\n");
        return 1;
    }

    printf("Enter the value of x: \n");
    if (scanf("%f", &x) != 1)
    {
        printf("Invalid input for the value of x.\n");
        return 1;
    }

    /* Read the coefficients into an array */
    printf("Enter %d coefficients: \n", num + 1);
    for (i = 0; i <= num; i++)
    {
        if (scanf("%f", &array[i]) != 1)
        {
            printf("Invalid input for coefficient %d.\n", i);
            return 1;
        }
    }
    polySum = array[0];
    for (i = 1; i <= num; i++)
    {
        polySum = polySum * x + array[i];
    }
    power = num;

    printf("The polynomial is: \n");
    for (i = 0; i <= num; i++)
    {
        if (array[i] != 0.0)
        {
            if (power == 0)
            {
                printf("%.2f", array[i]);
            }
            else if (power == 1)
            {
                if (array[i] == 1.0)
                {
                    printf("x");
                }
                else if (array[i] == -1.0)
                {
                    printf("-x");
                }
                else
                {
                    printf("%.2fx", array[i]);
                }
            }
            else
            {
                if (array[i] == 1.0)
                {
                    printf("x^%d", power);
                }
                else if (array[i] == -1.0)
                {
                    printf("-x^%d", power);
                }
                else
                {
                    printf("%.2fx^%d", array[i], power);
                }
            }
            if (power > 0)
            {
                printf(" + ");
            }
        }
        power--;
    }
    printf("\nSum of the polynomial = %.2f \n", polySum);
    return 0;
}