#include <stdio.h>
#include <math.h>

int main()
{
    char choice = 'y';
    int n, i, j, k;
    float h[10], a, b, c, d, sum, s[10] = {0}, x[10], F[10], f[10], p, m[10][10] = {0}, temp;

    while (choice == 'y' || choice == 'Y')
    {
        printf("Enter the number of samples: ");
        scanf("%d", &n);

        // input sample points
        printf("\nEnter the sample points (x, f(x)):\n");
        for (i = 0; i < n; i++)
        {
            printf("Sample %d: ", i + 1);
            scanf("%f%f", &x[i], &f[i]);
        }

        // calculate F and h arrays
        for (i = n - 1; i > 0; i--)
        {
            F[i] = (f[i] - f[i - 1]) / (x[i] - x[i - 1]);
            h[i - 1] = x[i] - x[i - 1];
        }

        // form the h, s, and f matrices
        for (i = 1; i < n - 1; i++)
        {
            m[i][i] = 2 * (h[i - 1] + h[i]);
            if (i != 1)
            {
                m[i][i - 1] = h[i - 1];
                m[i - 1][i] = h[i - 1];
            }
            m[i][n - 1] = 6 * (F[i + 1] - F[i]);
        }

        // perform forward elimination
        for (i = 1; i < n - 2; i++)
        {
            temp = (m[i + 1][i] / m[i][i]);
            for (j = 1; j <= n - 1; j++)
                m[i + 1][j] -= temp * m[i][j];
        }

        // perform backward substitution
        for (i = n - 2; i > 0; i--)
        {
            sum = 0;
            for (j = i; j <= n - 2; j++)
                sum += m[i][j] * s[j];
            s[i] = (m[i][n - 1] - sum) / m[i][i];
        }

        // input x value
        printf("\nEnter x: ");
        scanf("%f", &p);

        // calculate functional value
        for (i = 0; i < n - 1; i++)
        {
            if (x[i] <= p && p <= x[i + 1])
            {
                a = (s[i + 1] - s[i]) / (6 * h[i]);
                b = s[i] / 2;
                c = (f[i + 1] - f[i]) / h[i] - (2 * h[i] * s[i] + s[i + 1] * h[i]) / 6;
                d = f[i];
                sum = a * pow((p - x[i]), 3) + b * pow((p - x[i]), 2) + c * (p - x[i]) + d;
            }
        }

        // output coefficients and functional value
        printf("\nCoefficients of subintervals are:\n");
        printf("a: %f\n", a);
        printf("b: %f\n", b);
        printf("c: %f\n", c);
        printf("d: %f\n", d);
        printf("\nFunctional value is: %f", sum);

        // prompt user to continue or exit
        printf("\nContinue (y/n)? ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
        {
            printf("Invalid choice. Exiting loop.\n");
            choice = 'n';
        }
    }

    return 0;
}