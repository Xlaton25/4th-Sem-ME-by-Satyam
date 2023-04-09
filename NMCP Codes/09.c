// Find the real root of the equations x^2 + 4 * sin x = 0 using Newton-Raphson method. Write its computer programme in 'C' language

// #include <stdio.h>
// #include <math.h>

// double f(double x) {
//     return x*x + 4*sin(x);
// }

// double fprime(double x) {
//     return 2*x + 4*cos(x);
// }

// int main() {
//     double x0 = 2;
//     double x1, fx0, fx1, dfx0;
//     int max_iter = 1000;
//     double tol = 1e-6;

//     for (int i = 0; i < max_iter; i++) {
//         fx0 = f(x0);
//         dfx0 = fprime(x0);

//         x1 = x0 - fx0/dfx0;
//         fx1 = f(x1);

//         if (fabs(x1 - x0) < tol || fabs(fx1) < tol) {
//             break;
//         }

//         x0 = x1;
//     }

//     printf("The real root of the equation x^2 + 4*sin(x) = 0 is: %.6lf\n", x1);

//     return 0;
// }

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

/* Defining equation to be solved.
   Change this equation to solve another problem. */
#define    f(x)    x*x + 4*sin(x)

/* Defining derivative of g(x).
   As you change f(x), change this function also. */
#define   g(x)   2*x + 4*cos(x)

void main()
{
	 float x0, x1, f0, f1, g0, e=0.001;
	 int step = 1, N=100;
	//  clrscr();
     /* Inputs */
	 printf("\nEnter initial guess:\n");
	 scanf("%f", &x0);
	//  printf("Enter tolerable error:\n");
	//  scanf("%f", &e);
	//  printf("Enter maximum iteration:\n");
	//  scanf("%d", &N);
	 /* Implementing Newton Raphson Method */
	 printf("\nStep\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
	 do
	 {
		  g0 = g(x0);
		  f0 = f(x0);
		  if(g0 == 0.0)
		  {
			   printf("Mathematical Error.");
			   exit(0);
		  }

		
		  x1 = x0 - f0/g0;

		
		  printf("%d\t\t%f\t%f\t%f\t%f\n",step,x0,f0,x1,f1);
		  x0 = x1;
		  
		  step = step+1;
		
		  if(step > N)
		  {
			   printf("Not Convergent.");
			   exit(0);
		  }
		  
		  f1 = f(x1);
		  
	 }while(fabs(f1)>e);
	
	 printf("\nRoot is: %f", x1);
	//  getch();
}