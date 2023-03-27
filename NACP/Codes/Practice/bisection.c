// method of bisection to find the roots of a function in given interval

#include<stdio.h>

int main(){
    float a, b, c, err = 0.0001, fa, fb, fc;  // a = lower limit, b = upper limit, c = mid point, err = error, fa = f(a), fb = f(b), fc = f(c)
    printf("Enter the lower limit: ");
    scanf("%f", &a);  // input lower limit
    printf("Enter the upper limit: ");
    scanf("%f", &b);  // input upper limit
    int c1, mitr = 100;  // c1 = loop variable, mitr = maximum iterations
    for(c1 = 1; c1 <= mitr; c1++){  // loop to find root
        c = (a + b)/2;  // bisection formula
        fa = a*a*a - 8;  // f(a)
        fb = b*b*b - 8;  // f(b)
        fc = c*c*c - 8;  // f(c)
        if(fa*fc < 0){  // condition to check if root is in left half
            b = c;  // update b
        }
        else if(fa*fc > 0){  // condition to check if root is in right half
            a = c;  // update a
        }
        else if(fc == 0){  // condition to check if root is found
            printf("The cube root of 7 is %f", c);  // output root
            break;
        }
        if(fabs(b - a) < err){  // condition to check if root is found
            printf("The cube root of 8 is %f", c);  // output root
            break;
        }
    }
    return 0;
}