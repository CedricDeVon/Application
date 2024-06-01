#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <ctype.h>
#include <limits.h>

void print(int* values, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", values[i]);
    }
    printf("\n");
}

int maxCustomers(int* arrival, int* departure, int n)
{
    if (arrival == NULL || departure == NULL || n < 1)
    {
        return 0;
    }
    
    int time[20];
    for (int i = 0; i < 20; i++)
    {
        time[i] = 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (arrival[i] - 1 <= departure[i])
        {
            for (int j = arrival[i] - 1; j < departure[i]; j++)
            {
                time[j]++;
            }    
        }
        else
        {
            for (int j = 0; j < departure[i]; j++)
            {
                time[j]++;
            }
            for (int j = arrival[i] - 1; j < 20; j++)
            {
                time[j]++;
            }
        }
    }
    
    print(time, 20);

    int max = 0;
    for (int i = 0; i < 20; i++)
    {
        if (time[i] > max)
        {
            max = time[i];
        }
    }

    return max;
}

int main(void)
{
    // int arr[7] = {6, 2, 4, 10, 4, 7, 9};
    // int dep[7] = {13, 7, 15, 17, 10, 11, 17};
    int arr[1] = {15};
    int dep[1] = {5};
    printf("Max number of customers: %d", maxCustomers(arr, dep, 1));
    
    int exit_code = 0;
    scanf("%d", &exit_code);

    return 0;
}

