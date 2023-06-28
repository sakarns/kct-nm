#include <stdio.h>
#include <conio.h>
#include <math.h>

/* Define function to take equation input from user */
void input_equations(float A[][10], float B[], int n)
{
   printf("Enter the coefficients of the equations:\n");

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         scanf("%f", &A[i][j]);
      }
   }

   printf("Enter the constants:\n");

   for (int i = 0; i < n; i++)
   {
      scanf("%f", &B[i]);
   }
}

/* Main function */
int main()
{
   float A[10][10], B[10], X[10];
   int n, count = 1;
   float x0 = 0, y0 = 0, z0 = 0, x1, y1, z1, e1, e2, e3, e;

   printf("Enter the number of equations (max 10):\n");
   scanf("%d", &n);

   input_equations(A, B, n);

   printf("Enter tolerable error:\n");
   scanf("%f", &e);

   printf("\nCount\tx\ty\tz\n");
   do
   {
      /* Calculation */
      x1 = (B[0] - A[0][1] * y0 - A[0][2] * z0) / A[0][0];
      y1 = (B[1] - A[1][0] * x0 - A[1][2] * z0) / A[1][1];
      z1 = (B[2] - A[2][0] * x0 - A[2][1] * y0) / A[2][2];
      printf("%d\t%0.4f\t%0.4f\t%0.4f\n", count, x1, y1, z1);

      /* Error */
      e1 = fabs(x0 - x1);
      e2 = fabs(y0 - y1);
      e3 = fabs(z0 - z1);

      count++;

      /* Set value for next iteration */
      x0 = x1;
      y0 = y1;
      z0 = z1;
   } while (e1 > e && e2 > e && e3 > e);

   printf("\nSolution: x=%0.3f, y=%0.3f and z = %0.3f\n", x1, y1, z1);

   return 0;
}