#include <stdio.h>
#include <math.h>

void GaussLegendre(float, float, int);

float f(float x) { return exp(x * x); }

float g(float a, float b, float z)
{
    float x = (b - a) / 2 * z + (b + a) / 2;
    return exp(x * x);
}

int main()
{
    float a, b;
    int n;
    char ch;
    printf("Enter a and b: ");
    scanf("%f%f", &a, &b);

    do
    {
        printf("Enter 2 for 2-point formula: \n");
        printf("Enter 3 for 3-point formula: \n");
        printf("Enter 4 for 4-point formula: \n");
        scanf("%d", &n);
        switch (n)
        {
        case 2:
            printf("Using 2-point Formula::\n");
            GaussLegendre(a, b, n);
            break;
        case 3:
            printf("Using 3-point Formula::\n");
            GaussLegendre(a, b, n);
            break;
        case 4:
            printf("Using 4-point Formula::\n");
            GaussLegendre(a, b, n);
            break;
        default:
            printf("INVALID\n");
        }
        printf("\nDo you want to calculate again? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
    return 0;
}

void GaussLegendre(float a, float b, int n)
{
    float I;
    if (n == 2)
    {
        I = 1 * g(a, b, -1 / sqrt(3)) + 1 * g(a, b, 1 / sqrt(3));
        I = I * (b - a) / 2;
        printf("I=%f", I);
    }
    if (n == 3)
    {
        I = 5.0 / 9.0 * g(a, b, -sqrt(3.0 / 5.0)) + 8.0 / 9.0 * g(a, b, 0) + 5.0 / 9.0 * g(a, b, sqrt(3.0 / 5.0));
        I = I * (b - a) / 2;
        printf("I=%f", I);
    }
    if (n == 4)
    {
        I = 0.34785 * g(a, b, -0.86114) + 0.65215 * g(a, b, -0.33998) + 0.65215 * g(a, b, 0.33998) + 0.34785 * g(a, b, 0.86114);
        I = I * (b - a) / 2;
        printf("I=%f", I);
    }
}