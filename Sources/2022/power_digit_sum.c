#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// TODO: Copy the code from hackerman.com

int powerDigitSum(int n, int e);
int digitSum(unsigned long int x);

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int base = 0, exponent = 0;
    scanf("%d", &base);
    printf("Base: %d", base);

    scanf("%d", &exponent);
    printf("\nExponent: %d", exponent);

    if (base <= 0 || exponent <= 0)
    {
        exit(1);
    }
    else
    {
        printf("\nPower Digit Sum of %d ^ %d: %d", base, exponent, powerDigitSum(base, exponent));
    }

    return 0;
}

int powerDigitSum(int n, int e)
{
    unsigned long int MAX = pow(2, 32) - 1;
    unsigned long int power = pow(n, e);
    if (power - 1 >= MAX)
    {
        printf("\nLimit Exceeded!");
    }

    int digit_sum = digitSum(power);
    return digit_sum;
}

int digitSum(unsigned long int x)
{
    int sum = 0;
    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    }

    return sum;
}