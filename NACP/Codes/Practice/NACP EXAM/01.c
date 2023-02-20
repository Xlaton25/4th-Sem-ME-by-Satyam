// program on newton raphson to find cube root of a number
#include<stdio.h>
#include<math.h>

float ffunc(float x, float y); // function to find f(x)
float fprime(float x); // function to find f'(x)
int main(){
    float n,i,j,k, err = 0.0001, xi = 0.3, m;  // n = number, i,j,k = loop variables, err = error, xi = initial guess, m = root
    printf("Enter the number to find cube root: ");
    scanf("%f", &n);  // input number
    int c, mitr = 100;  // c = loop variable, mitr = maximum iterations
    for(c = 1; c <= mitr; c++){   // loop to find root
        m = xi - (ffunc(xi, n)/fprime(xi));  // newton raphson formula
        if(fabs(m - xi) < err){   // condition to check if root is found
            printf("The cube root of %f is %f", n, m);  // output root
            break;
        }
        xi = m; // update xi
    }
    return 0;
}
float ffunc(float x, float y){  // function to find f(x)
    return (x*x*x - y);
}
float fprime(float x){ // function to find f'(x)
    return (3*x*x);
}

/*
x^3 = 7
f(x) = x^3 - 7
f'(x) = 3x^2
*/