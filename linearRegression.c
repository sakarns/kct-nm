#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    float a, b, x[10], y[10], sumx = 0, sumy = 0, sumxy = 0, sumxx = 0;
    int i, n, choice;

    // Get the number of data points from the user
    printf("Enter the number of data points (up to 10): ");
    scanf("%d", &n);

    // Input validation for number of data points5
    if (n < 2 || n > 10) {
        printf("Invalid number of data points. Please enter a number between 2 and 10.\n");
        return 1;
    }

    // Get the x and y values from the user
    printf("Enter the values of x and y (x __ y):\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f%f", &x[i], &y[i]);
    }
    printf("\n");

j:
    // Ask the user to choose a curve fit type
    printf("Fit the curve of the form...\n1. y = ax + b\n2. y = a + bx\n3. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("\nCurve fit type: y = ax + b\n");

        // Compute the sums needed for the curve fit equation
        for (i = 0; i < n; i++)
        {
            sumx = sumx + x[i];
            sumy = sumy + y[i];
            sumxy = sumxy + x[i] * y[i];
            sumxx = sumxx + x[i] * x[i];
        }

        // Compute the coefficients a and b for the curve fit equation
        b = (n * sumxy - sumx * sumy) / (n * sumxx - sumx * sumx);
        a = (sumy - b * sumx) / n;

        // Print the curve fit equation
        printf("The best fit curve for the given data points is: y = %f * x + %f\n", a, b);
        printf("\n");
        break;

    case 2:
        printf("\nCurve fit type: y = a + bx\n");

        // Compute the sums needed for the curve fit equation
        for (i = 0; i < n; i++)
        {
            sumx = sumx + x[i];
            sumy = sumy + y[i];
            sumxy = sumxy + x[i] * y[i];
            sumxx = sumxx + x[i] * x[i];
        }

        // Compute the coefficients a and b for the curve fit equation
        a = (n * sumxy - sumx * sumy) / (n * sumxx - sumx * sumx);
        b = (sumy - a * sumx) / n;

        // Print the curve fit equation
        printf("The best fit curve for the given data points is: y = %f + %f * x\n", a, b);
        printf("\n");
        break;

    case 3:
        // Exit the program
        exit(0);

    default:
        // Error handling for invalid input
        printf("\nInvalid choice. Please enter a number between 1 and 3.\n");
        printf("\n");
        break;
    }

    // Loop back to the beginning to allow the user to choose another curve fit type
    goto j;
}