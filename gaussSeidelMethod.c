#include <stdio.h>
#include <math.h>

/* Main function */
int main()
{
   int n;
   float e, x0[10], x1[10], a[10][10], b[10], e_arr[10], tmp;
   int count = 1;

   printf("Enter the number of equations: ");
   scanf("%d", &n);

   printf("Enter the coefficients of the equations:\n");
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         printf("a[%d][%d]: ", i, j);
         scanf("%f", &a[i][j]);
      }
      printf("b[%d]: ", i);
      scanf("%f", &b[i]);
   }

   printf("Enter tolerable error: ");
   scanf("%f", &e);

   printf("\nCount");
   for (int i = 0; i < n; i++)
   {
      printf("\tx%d", i);
      x0[i] = 0;
   }
   printf("\n");

   do
   {
      printf("%d", count);
      for (int i = 0; i < n; i++)
      {
         x1[i] = b[i];
         for (int j = 0; j < n; j++)
         {
            if (j != i)
            {
               x1[i] -= a[i][j] * x0[j];
            }
         }
         x1[i] /= a[i][i];
         printf("\t%0.4f", x1[i]);
      }
      printf("\n");

      for (int i = 0; i < n; i++)
      {
         e_arr[i] = fabs(x0[i] - x1[i]);
      }

      tmp = e_arr[0];
      for (int i = 1; i < n; i++)
      {
         if (e_arr[i] > tmp)
         {
            tmp = e_arr[i];
         }
      }

      count++;

      for (int i = 0; i < n; i++)
      {
         x0[i] = x1[i];
      }
   } while (tmp > e);

   printf("\nSolution: ");
   for (int i = 0; i < n; i++)
   {
      printf("x%d = %0.3f ", i, x1[i]);
   }
   printf("\n");

   return 0;
}