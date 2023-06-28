#include <stdio.h>
#include <math.h>

#define EPS 0.000001
#define MAXIT 50

int main()
{
    int n, status, i, j;
    float a[11], root[10], x0, xr;

    void dflat(int n, float a[11], float xr);
    void newton(int n, float a[11], float x0, int *status, float *xr);

    printf("\n");
    printf("\nEvaluation of Multiple Roots\n");
    printf("\n");
    printf("Input degree of polynomial, n: ");
    scanf("%d", &n);
    printf("\nInput polynomial coffecients, a(n+1): ");
    for (i = 1; i <= n + 1; i++)
        scanf("%f", &a[i]);
    printf("\nInput initial guesses of X: ");
    scanf("%f", &x0);
    printf("\n");

    for (i = n; i >= 2; i--)
    {
        newton(n, a, x0, &status, &xr);
        if (status == 2)
        {
            for (j = n; j = i + 1; j--)
                printf("root %d=%f \n", j, root[j]);
            printf("\nNext root does not converge in \n");
            printf("%d iterations\n", MAXIT);
            printf("\n");
            goto end;
        }
        root[i] = xr;
        dflat(n, a, xr);
        x0 = xr;
    }

    root[1] = -a[1] / a[2];
    printf("\nRoots of Polynomials are: \n");
    printf("\n");

    for (i = 1; i <= n; i++)
        printf("Root %d = %f\n", i, root[i]);
    printf("\n");
end:
    printf("END");
    return 0;
}

void newton(int n, float a[11], float x0, int *status, float *xr)
{
    int i, count;
    float fx;
    float fdx;

    count = 1;
begin:
    fx = a[n + 1];
    for (i = n; i >= 1; i--)
        fx = fx * x0 + a[i];

    fdx = a[n + 1] * n;
    for (i = n; i >= 2; i--)
        fdx = fdx * x0 + a[i] * (i - 1);

    *xr = x0 - fx / fdx;

    if (fabs((*xr - x0) / (*xr)) <= EPS)
    {
        *status = 1;
        return;
    }

    if (count < MAXIT)
    {
        x0 = *xr;
        count = count + 1;
        goto begin;
    }
    else
    {
        *status = 2;
        return;
    }
}

void dflat(int n, float a[11], float xr)
{
    float b[11];
    int i;

    b[n + 1] = 0;
    for (i = n; i >= 1; i--)
        b[i] = a[i + 1] + xr * b[i + 1];

    for (i = 1; i <= n + 1; i++)
        a[i] = b[i];
}