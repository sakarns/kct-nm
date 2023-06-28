#include <stdio.h>
#include <math.h>

int fact(int n);


int main()
{
    float arr[10][11], x, h, p, y, px = 1;
    int i, j, n, ch = 30, choice;

    /* Input Section */
    printf("Enter number of data: ");
    scanf("%d", &n);
    printf("Enter data:\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d]=", i);
        scanf("%f", &arr[i][0]);
        printf("y[%d]=", i);
        scanf("%f", &arr[i][1]);
    }

    // Forming difference table using forward differences.
    for (j = 2; j <= n; j++)
        for (i = 0; i < n - j + 1; i++)
            arr[i][j] = arr[i + 1][j - 1] - arr[i][j - 1];

    // Printing forward difference table
    printf("\nForward difference table is:-");
    printf("\nX\tY");
    for (i = 0; i < n - 1; i++)
        printf("\t%c^%dY", ch, i + 1);
    for (i = 0; i < n; i++)
    {
        printf("\n");
        printf("%0.2f", arr[i][0]);
        for (j = 1; j < n - i + 1; j++)
        {
            printf("\t%0.2f", arr[i][j]);
        }
    }

    // Take the value of x for f(x)
    printf("\n\nEnter the value x for function f(x): ");
    scanf("%f", &x);

    // Calculate the value of f(x) using forward difference interpolation
    h = arr[1][0] - arr[0][0];
    p = (x - arr[0][0]) / h;
    y = arr[0][1];
    for (i = 1; i < n; i++)
    {
        px = px * (p - (i - 1));
        y = y + (arr[0][i + 1] * px) / fact(i);
    }

    printf("\nThe value of function at x=%f using forward difference interpolation is %f", x, y);

    // Forming difference table using backward differences.
    for (j = 2; j <= n; j++)
        for (i = n - 1; i >= j - 1; i--)
            arr[i][j] = arr[i][j - 1] - arr[i - 1][j - 1];

    // Printing backward difference table
    printf("\n\nBackward difference table is:-");
    printf("\nX\tY");
    for (i = 0; i < n - 1; i++)
        printf("\t%c^%dY", ch, i + 1);
    for (i = 0; i < n; i++)
    {
        printf("\n");
        printf("%0.2f", arr[i][0]);
        for (j = 1; j <= i + 1; j++)
        {
            printf("\t%0.2f", arr[i][j]);
        }
    }

    // Take the value of x for f(x)
    printf("\n\nEnter the value x for function f(x): ");
    scanf("%f", &x);

    // Calculate the value of f(x) using backward difference interpolation
    h = arr[1][0] - arr[0][0];
    p = (x - arr[n - 1][0]) / h;
    y = arr[n - 1][1];
    px = 1;
    for (i = 1; i < n; i++)
    {
        px = px * (p + (i - 1));
        y = y + (arr[n - i - 1][i + 1] * px) / fact(i);
    }

    printf("\nThe value of function at x=%f using backward difference interpolation is %f", x, y);
    printf("\n");
    return 0;
}

int fact(int n)
{
    int i, f = 1;
    for (i = 1; i <= n; i++)
        f = f * i;
    return f;
}