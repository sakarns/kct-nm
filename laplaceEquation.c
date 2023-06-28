#include <stdio.h>
#include <math.h>

#define S 4

typedef float newvar[S + 1][S + 1];

void entrow(int i, newvar u)
{
    // Function to enter the i-th row of the array u
    int j;
    printf("\nEnter the value of u[%d,j], j=1,%d\n", i, S);
    for (j = 1; j <= S; j++)
        scanf("%f", &u[i][j]);
}

void entcol(int j, newvar u)
{
    // Function to enter the j-th column of the array u
    int i;
    printf("\nEnter the value of u[i,%d], i=2,%d\n", j, S - 1);
    for (i = 2; i <= S - 1; i++)
        scanf("%f", &u[i][j]);
}

void oput(newvar u, int wd, int prsn)
{
    // Function to print the array u with given field width and precision
    int i, j;
    for (i = 1; i <= S; i++)
    {
        for (j = 1; j <= S; j++)
            printf("%*.*f ", wd, prsn, u[i][j]); // use field width and precision
        printf("\n");
    }
}

int main()
{
    newvar u;
    float mer, ar, e, t;
    int i, j, itr, maxitr;

    // Initialize array u to all zeros
    for (i = 1; i <= S; i++)
        for (j = 1; j <= S; j++)
            u[i][j] = 0;

    // Enter the boundary conditions
    printf("\nEnter the boundary conditions:\n");
    entrow(1, u);
    entrow(S, u);
    entcol(1, u);
    entcol(S, u);

    // Enter the error tolerance and maximum number of iterations
    printf("\nEnter the allowed error and maximum number of iterations: ");
    scanf("%f %d", &ar, &maxitr);

    // Perform Jacobi iterations
    for (itr = 1; itr <= maxitr; itr++)
    {
        mer = 0;
        for (i = 2; i < S; i++)
        {
            for (j = 2; j < S; j++)
            {
                // Compute the new value of u[i][j] using Jacobi method
                t = (u[i - 1][j] + u[i + 1][j] + u[i][j + 1] + u[i][j - 1]) / 4;
                e = fabs(u[i][j] - t);
                if (e > mer)
                    mer = e;
                u[i][j] = t;
            }
        }
        printf("\nIteration Number %d:\n", itr);
        oput(u, 10, 5);
        if (mer <= ar)
        {
            printf("\nSolution after %d iterations:\n", itr);
            oput(u, 10, 5);
            return 0;
        }
    }
    printf("\nMaximum number of iterations reached.\n");
    printf("Solution after %d iterations:\n", maxitr);
    oput(u, 10, 5);
    return 0;
}