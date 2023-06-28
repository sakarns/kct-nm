#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    float a, b, x[10], y[10], sumx = 0, sumy = 0, sumxy = 0, sumxx = 0;
    float Y[10], X[10], A;
    int i, n, choice;

    // Get the number of data points from the user
    printf("Enter number of data points (up to 10): ");
    scanf("%d", &n);

    // Input validation for number of data points
    if (n < 1 || n > 10) {
        printf("Invalid number of data points. Please enter a number between 1 and 10.\n");
        return 1;
    }

    // Get the x and y values from the user
    printf("Enter the values of x and y: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%f%f", &x[i], &y[i]);
    }

j:
    // Ask the user to choose a curve fit type
    printf("\nFit the curve of the form...\n1. y = a*x^b\n2. y = a*b^x\n3. y = a*exp(b*x)\n4. Exit\n");
    printf("Enter choice : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("\nCurve fit type: y = a*x^b\n");

        // Compute the logarithms of the x and y values
        for (i = 0; i < n; i++)
        {
            X[i] = log(x[i]);
            Y[i] = log(y[i]);
        }

        // Compute the sums needed for the curve fit equation
        for (i = 0; i < n; i++)
        {
            sumx = sumx + X[i];
            sumy = sumy + Y[i];
            sumxy = sumxy + X[i] * Y[i];
            sumxx = sumxx + X[i] * X[i];
        }

        // Compute the coefficients a and b for the curve fit equation
        b = (n * sumxy - sumx * sumy) / (n * sumxx - sumx * sumx);
        a = exp((sumy - b * sumx) / n);

        // Print the curve fit equation
        printf("The best fit curve for the given data points is: y = %f * x^%f\n", a, b);
        break;

    case 2:
        printf("\nCurve fit type: y = a*b^x\n");

        // Compute the logarithms of the x and y values
        for (i = 0; i < n; i++)
        {
            X[i] = log(x[i]);
            Y[i] = log(y[i]);
        }

        // Compute the sums needed for the curve fit equation
        for (i = 0; i < n; i++)
        {
            sumx = sumx + X[i];
            sumy = sumy + Y[i];
            sumxy = sumxy + X[i] * Y[i];
            sumxx = sumxx + X[i] * X[i];
        }

        // Compute the coefficients a and b for the curve fit equation
        A = exp((sumy * sumxx - sumx * sumxy) / (n * sumxx - sumx * sumx));
        b = (n * sumxy - sumx * sumy) / (n * sumxx - sumx * sumx);

        // Print the curve fit equation
        printf("The best fit curve for the given data points is: y = %f * (%f)^x\n", A, exp(b));
        break;

    case 3:
        printf("\nCurve fit type: y = a*exp(b*x)\n");

        // Compute the logarithm of the y values
        for (i = 0; i < n; i++)
        {
            Y[i] = log(y[i]);
        }

        // Compute the sums needed for the curve fit equation
        for (i = 0; i < n; i++)
        {
            sumx = sumx + x[i];
            sumy = sumy + Y[i];
            sumxy = sumxy + x[i] * Y[i];
            sumxx = sumxx + x[i] * x[i];
        }

       // Compute the coefficients a and b for the curve fit equation
        b = (n * sumxy - sumx * sumy) / (n * sumxx - sumx * sumx);
        a = exp((sumy - b * sumx) / n);

        // Print the curve fit equation
        printf("The best fit curve for the given data points is: y = %f * exp(%f * x)\n", a, b);
        break;

    case 4:
        // Exit the program
        exit(0);

    default:
        // Error handling for invalid input
        printf("\nInvalid choice. Please enter a number between 1 and 4.\n");
        break;
    }

    // Loop back to the beginning to allow the user to choose another curve fit type
    goto j;
}