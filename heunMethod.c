#include <conio.h>
#include <stdio.h>
#define f(x, y) 2 * y / x
int main()
{
    float x, y, h, xn, l;

    printf("Enter value for x and y\n");
    scanf("%f %f", &x, &y);
    printf("Enter value for h: ");
    scanf("%f", &h);
    printf("Enter final value of x: ");
    scanf("%f", &xn);
    while (x + h <= xn)
    {
        l = (h / 2) * (f(x, y) + f(x + h, y + h * f(x, y)));
        y = y + l;
        x = x + h;

        printf("y = %f\tx = %f\n", y, x);
    }
    return 0;
}
