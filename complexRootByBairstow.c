#include <stdio.h>
#include <math.h>

int main()
{
    int i, d;
    float p, q, dp = 0, dq = 0, dn, a[10], b[10], c[10];
    printf("Enter the degree of polynomial: ");
    scanf("%d", &d);
    printf("\nEnter the coefficient of polynomial:\n");
    for (i = 0; i <= d; i++)
    {
        printf("a(%d): ", i);
        scanf("%f", &a[i]);
    }

    printf("\nEnter initial gueses for p: ");
    scanf("%f", &p);
    printf("\nEnter the initial gueses for q: ");
    scanf("%f", &q);

    do
    {
        c[0] = b[0] = a[0];
        b[1] = a[1] - p * b[0];
        c[1] = b[1] - p * c[0];
        for (i = 2; i < d; i++)
        {
            b[i] = a[i] - p * b[i - 1] - p * b[i - 2];
            c[i] = b[i] - p * c[i - 1] - p * c[i - 2];
        }
        dn = c[d - 2] * c[d - 2] - c[d - 3 * d - 1] - b[d - 1];
        dp = (b[d - 1] * c[d - 2] - b[d] * c[d - 3]) / dn;
        dq = (b[d] * c[d - 2] - b[d - 1] * (c[d - 1] + b[d - 1])) / dn;
        p = p + dp;
        q = q + dq;
    } while (dp > 0.01 || dp > 0.01);

    printf("\nThe complex roots of the equation: x^2+(%f)x+(%f)", p, q);
    return 0;
}