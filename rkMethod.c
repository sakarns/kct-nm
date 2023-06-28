#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

#define f(x, y) (y * y - x * x) / (y * y + x * x)

int main()
{
    float x0, y0, xn, h, yn, k1, k2, k3, k4, k;
    int i, n, choice;

    printf("Enter Initial Condition\n");
    printf("x0 = ");
    scanf("%f", &x0);
    printf("y0 = ");
    scanf("%f", &y0);
    printf("Enter calculation point xn = ");
    scanf("%f", &xn);

    /* Calculating step size (h) */
    h = (xn - x0) / n;

j:
    // Ask the user to choose a curve fit type
    printf("\nFit the curve of the form...\n1. RK2 Method\n2. RK4 Method\n3. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        /* Runge Kutta 2 Method */
        n=2;
        printf("\nx0\ty0\tyn\n");
        for (i = 0; i < n; i++)
        {
            k1 = h * (f(x0, y0));
            k2 = h * (f((x0 + h), (y0 + k1)));
            yn = y0 + (k1 + k2) / 2;
            printf("%0.4f\t%0.4f\t%0.4f\n", x0, y0, yn);
            x0 = x0 + h;
            y0 = yn;
        }

        /* Displaying result */
        printf("\nValue of y at x = %0.2f is %0.3f", xn, yn);
        printf("\n");
        break;

    case 2:
        /* Runge Kutta 4 Method */
        n=4;
        printf("\nx0\ty0\tyn\n");
        for (i = 0; i < n; i++)
        {
            k1 = h * (f(x0, y0));
            k2 = h * (f((x0 + h / 2), (y0 + k1 / 2)));
            k3 = h * (f((x0 + h / 2), (y0 + k2 / 2)));
            k4 = h * (f((x0 + h), (y0 + k3)));
            k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
            yn = y0 + k;
            printf("%0.4f\t%0.4f\t%0.4f\n", x0, y0, yn);
            x0 = x0 + h;
            y0 = yn;
        }

        /* Displaying result */
        printf("\nValue of y at x = %0.2f is %0.3f", xn, yn);
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