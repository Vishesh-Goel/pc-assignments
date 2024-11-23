#include <stdio.h>
#include <math.h>

double function(double x){
    return x*x-4;
}

double derivative(double x){
    return 2*x;
}

double getInitialGuess(){
    double guess;
    printf("enter initial guess: ");
    scanf("%lf", &guess);
    return guess;
}

int getMaxIterations(){
    int max;
    printf("enter maximum number of iterations: ");
    scanf("%d", &max);
    return max;
}

double getTolerance(){
    double tol;
    printf("enter the tolerance for convergence: ");
    scanf("%lf", &tol);
    return tol;
}

int main() {
    double x = getInitialGuess();
    int maxIterations = getMaxIterations();
    double tolerance = getTolerance();
    int iteration = 0;

    printf("\nNewton-Raphson Method:\n");
    printf("Initial guess: %f\n", x);
    printf("Maximum Iterations: %d\n", maxIterations);
    printf("Tolerance: %f\n\n", tolerance);

    while (iteration < maxIterations){
        double f = function(x);
        double fPrime = derivative(x);
        if (fabs(fPrime) < 1e-9){  //avoiding division by 0
            printf("derivative is too small");
            return -1;
        }
        double x2 = x-f / fPrime;
        printf("iteration %d: x = %f, f(x) = %f\n", iteration+1, x2, function(x2));

        //Check for convergence
        if (fabs(x2-x) < tolerance){
            printf("\nRoot found at x = %f after %d iterations\n", x2, iteration+1);
            return 0;
        }
        x = x2;
        iteration++;
    }
    printf("\nMethod did not converge after %d iterations.", maxIterations);
    return 0;
}