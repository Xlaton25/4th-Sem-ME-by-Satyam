#include <stdio.h>
#include <stdlib.h>
#define MAX 100
// function prototypes
double sum(double x[], int n);
double sumxy(double x[], double y[], int n);
double sumxsq(double x[], int n);
double sumysq(double y[], int n);
double avg(double arr[], int n);
int main()
{
    int n, i;
    double x[MAX], y[MAX], m, b;
    // get number of data points
    printf("Enter number of data points: ");
    scanf("%d", &n);
    // get data points
    for (i = 0; i < n; i++)
    {
        printf("Enter x[%d] and y[%d]: ", i, i);
        scanf("%lf %lf", &x[i], &y[i]);
    }
    // calculate slope and y-intercept
    m = (n * sumxy(x, y, n) - sum(x, n) * sum(y, n)) / (n * sumxsq(x, n) - sum(x, n) * sum(x, n));
    b = avg(y, n) - m * avg(x, n);
    // print results
    printf("\nThe line of best fit is y = %.4lfx + %.4lf\n", m, b);
    return 0;
}
// calculate the sum of an array
double sum(double arr[], int n)
{
    int i;
    double sum = 0.0;
    for (i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}
// calculate the sum of the product of two arrays
double sumxy(double x[], double y[], int n)
{
    int i;
    double sum = 0.0;
    for (i = 0; i < n; i++)
    {
        sum += x[i] * y[i];
    }
    return sum;
}
// calculate the sum of the squares of an array
double sumxsq(double arr[], int n)
{
    int i;
    double sum = 0.0;
    for (i = 0; i < n; i++)
    {
        sum += arr[i] * arr[i];
    }
    return sum;
}
// calculate the average of an array
double avg(double arr[], int n)
{
    return sum(arr, n) / n;
}