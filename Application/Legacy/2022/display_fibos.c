#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
returns the 1 if x is a Fibonacci sequence, 0 if otherwise. E.g. 5 returns 1, 28 returns 0
*/
int isFib(int x);

/*
Display the content of array a with a size of s
*/
void printArray(int a[], int s);

/*
Counts the number of Fibonacci sequence in array a with array size s using the isFib (int x) function.
*/
int fibCtr(int a[], int s);

int handle_size_input();
void handle_array_item_inputs(int a[], int s);
void print_fibs_in_array(int a[], int s);

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int s = handle_size_input();
    int a[s];
    handle_array_item_inputs(a, s);
    printArray(a, s);
    print_fibs_in_array(a, s);

    return 0;
}

int isFib(int x)
{
    int a = 0;
    int b = 1;
    int c = 0;
    while (a <= x)
    {
        if (a == x)
        {
            return 1;
        }

        a = b;
        b += c;
        c = a;
    }

    return 0;
}

void printArray(int a[], int s)
{
    printf("Array Content: ");
    for (int i = 0; i < s; i += 1)
    {
        printf("%d", a[i]);
        if (i <= s - 2)
        {
            printf(",");
        }
    }
    printf("\n");
}

int fibCtr(int a[], int s)
{
    int count = 0;
    for (int i = 0; i < s; i += 1)
    {
        if (isFib(a[i]))
        {
            count += 1;
        }
    }
    return count;
}

int handle_size_input()
{
    int size = 0;
    int is_valid = 0;
    while (!is_valid)
    {
        scanf("%d", &size);
        if (size >= 0)
        {
            is_valid = 1;
        }
        else
        {
            printf("Please enter a number greater than zero! \n");
            size = 0;
        }
    }
    return size;
}

void handle_array_item_inputs(int a[], int s)
{
    int i = 0;
    while (i < s)
    {
        int n = 0;
        scanf("%d", &n);
        if (n >= 0)
        {
            a[i] = n;
            i += 1;
        }
        else
        {
            printf("Please enter a number greater than or equal to zero! \n");
        }
    }
}

void print_fibs_in_array(int a[], int s)
{
    printf("Fibs in array: %d", fibCtr(a, s));
}