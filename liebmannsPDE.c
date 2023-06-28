#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NX 10 // number of grid points in x-direction
#define NY 10 // number of grid points in y-direction
#define L 1.0 // length of the domain in x-direction
#define H 1.0 // length of the domain in y-direction
#define DX (L/(NX-1)) // grid spacing in x-direction
#define DY (H/(NY-1)) // grid spacing in y-direction
#define OMEGA 1.9 // relaxation parameter

#define MAX_ITER 10000 // maximum number of iterations
#define TOL 1e-6 // tolerance for convergence

double f(double x, double y) {
    // define the right-hand side function
    return 0.0;
}

int main() {
    double u[NX][NY]; // solution array
    double u_old[NX][NY]; // previous solution array
    double error = 0.0; // error in the solution
    int iter = 0; // iteration counter
    int i, j;

    // initialize the solution and previous solution arrays
    for (i = 0; i < NX; i++) {
        for (j = 0; j < NY; j++) {
            u[i][j] = 0.0;
            u_old[i][j] = 0.0;
        }
    }

    // set the boundary conditions (Dirichlet)
    for (i = 0; i < NX; i++) {
        u[i][0] = 0.0;
        u[i][NY-1] = 0.0;
    }
    for (j = 0; j < NY; j++) {
        u[0][j] = 0.0;
        u[NX-1][j] = 0.0;
    }

    // perform the iteration
    while (iter < MAX_ITER) {
        // copy the solution array to the previous solution array
        for (i = 0; i < NX; i++) {
            for (j = 0; j < NY; j++) {
                u_old[i][j] = u[i][j];
            }
        }

        // update the solution array
        for (i = 1; i < NX-1; i++) {
            for (j = 1; j < NY-1; j++) {
                u[i][j] = (1.0 - OMEGA) * u_old[i][j] + (OMEGA/4.0) * (u_old[i+1][j] + u_old[i-1][j] + u_old[i][j+1] + u_old[i][j-1]);
            }
        }

        // compute the error in the solution
        error = 0.0;
        for (i = 1; i < NX-1; i++) {
            for (j = 1; j < NY-1; j++) {
                error += fabs(u[i][j] - u_old[i][j]);
            }
        }

        // check for convergence
        if (error < TOL) {
            break;
        }

        iter++;
    }

    // print the solution array
    for (j = NY-1; j >= 0; j--) {
        for (i = 0; i < NX; i++) {
            printf("%8.4f ", u[i][j]);
        }
        printf("\n");
    }

    return 0;
}