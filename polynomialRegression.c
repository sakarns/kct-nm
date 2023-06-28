#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, j, k;
    float sumx, sumxsq, sumy, sumxy, x, y;
    float sumx3, sumx4, sumxsqy, a[20][20], u = 0.0, b[20];

    // Get the number of data points from the user
    printf("\nEnter the number of data points (up to 20): ");
    scanf("%d", &n);

    // Input validation for number of data points
    if (n < 2 || n > 20) {
        printf("Invalid number of data points. Please enter a number between 2 and 20.\n");
        return 1;
    }

    // Initialize the sums to zero
    sumx = 0;
    sumxsq = 0;
    sumy = 0;
    sumxy = 0;
    sumx3 = 0;
    sumx4 = 0;
    sumxsqy = 0;

    // Get the x and y values from the user and calculate the sums needed for the matrix
    printf("\nEnter the x and y values:\n");
    printf("------------------------------------\n");
    printf("|    x    |    y    | x^2  | x^3  | x^4  | xy   | x^2y |\n");
    printf("------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f %f", &x, &y);
        sumx += x;
        sumxsq += pow(x, 2);
        sumx3 += pow(x, 3);
        sumx4 += pow(x, 4);
        sumy += y;
        sumxy += x * y;
        sumxsqy += pow(x, 2) * y;
        printf("|%8.2f|%8.2f|%6.2f|%6.2f|%6.2f|%6.2f|%7.2f|\n", x, y, pow(x, 2), pow(x, 3), pow(x, 4), x * y, pow(x, 2) * y);
    }
    printf("------------------------------------\n");

    // Populate the augmented matrix
    a[0][0] = n;
    a[0][1] = sumx;
    a[0][2] = sumxsq;
    a[0][3] = sumy;
    a[1][0] = sumx;
    a[1][1] = sumxsq;
    a[1][2] = sumx3;
    a[1][3] = sumxy;
    a[2][0] = sumxsq;
    a[2][1] = sumx3;
    a[2][2] = sumx4;
    a[2][3] = sumxsqy;

    // Print the augmented matrix
    printf("\nAugmented Matrix:\n");
    printf("------------------------------------\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j <= 3; j++)
        {
            printf("|%10.2f", a[i][j]);
        }
        printf("|\n");
    }
    printf("------------------------------------\n");

    // Solve the system of equations using Gaussian elimination
    for (k = 0; k <= 2; k++)
    {
        for (i = 0; i <= 2; i++)
        {
            if (i != k)
            {
                u = a[i][k] / a[k][k];
                for (j = k; j <= 3; j++)
                {
                    a[i][j] = a[i][j] - u * a[k][j];
                }
            }
        }
    }

    // Print the solution
    printf("\nSolution:\n");
    printf("------------------------------------\n");
    for (i = 0; i < 3; i++)
    {
        b[i] = a[i][3] / a[i][i];
        printf("|%8.2f|", b[i]);
    }
    printf("\n------------------------------------\n");
    printf("y = %10.4fx + %10.4fx + %10.4f\n", b[2], b[1], b[0]);

    return 0;
}