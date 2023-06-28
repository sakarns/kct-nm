#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define f(t, x, y) (y)
#define g(t, x, y) (-sin(x))

int main() {
    double x, y, t, h, kn1, kn2, kn3, kn4, gn1, gn2, gn3, gn4;
    int i, n;

    printf("Enter Initial Condition\n");
    printf("x0 = ");
    scanf("%lf", &x);
    printf("y0 = ");
    scanf("%lf", &y);
    printf("Enter calculation point t = ");
    scanf("%lf", &t);
    printf("Enter number of steps n = ");
    scanf("%d", &n);

    /* Calculating step size (h) */
    h = (t - 0) / n;

    printf("\nt\tx\ty\n");
    for (i = 0; i < n; i++) {
        printf("%0.4f\t%0.4f\t%0.4f\n", t, x, y);
        kn1 = f(t, x, y);
        gn1 = g(t, x, y);
        kn2 = f(t + h/2, x + (h/2)*kn1, y + (h/2)*gn1);
        gn2 = g(t + h/2, x + (h/2)*kn1, y + (h/2)*gn1);
        kn3 = f(t + h/2, x + (h/2)*kn2, y + (h/2)*gn2);
        gn3 = g(t + h/2, x + (h/2)*kn2, y + (h/2)*gn2);
        kn4 = f(t + h, x + h*kn3, y + h*gn3);
        gn4 = g(t + h, x + h*kn3, y + h*gn3);
        x += (h/6)*(kn1 + 2*kn2 + 2*kn3 + kn4);
        y += (h/6)*(gn1 + 2*gn2 + 2*gn3 + gn4);
        t += h;
    }

    /* Displaying result */
    printf("\nValue of y at t = %0.2f is %0.3f", t-h, y);
    printf("\n");

    return 0;
}