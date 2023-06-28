#include <stdio.h>
#include <math.h>

#define f(x) 1 / (x)

int main()
{
    float x0, xn, h, a, sm, sl, t[10][10];
    int p, q, i, j, k;

    printf("Enter lower and upper limit: ");
    scanf("%f%f", &x0, &xn);

    printf("Enter the values of p and q (T(p,q)): ");
    scanf("%d%d", &p, &q);

    h = xn - x0;

    t[0][0] = h / 2 * (f(x0) + f(xn));

    for (i = 1; i <= p; i++)
    {
        sl = pow(2, i - 1);
        sm = 0;

        for (j = 1; j <= sl; j++)
        {
            a = x0 + (2 * j - 1) * h / pow(2, i);
            sm += f(a);
        }

        t[i][0] = t[i - 1][0] / 2 + sm * h / pow(2, i);
    }

    for (k = 1; k <= q; k++)
    {
        for (i = k; i <= p; i++)
        {
            t[i][k] = (pow(4, k) * t[i][k - 1] - t[i - 1][k - 1]) / (pow(4, k) - 1);
        }
    }

    printf("Romberg estimate of integration = %f\n", t[p][q]);

    return 0;
}