#pragma once

#include <iostream>

using namespace std;

void rangeOfPrimeNumbers(unsigned int limit)
{
    for (unsigned int number = 2; number <= limit; number += 1)
    {
        bool isPrimeNumber = true;
        for (unsigned int factor = 2; factor < number && isPrimeNumber; factor += 1)
        {
            if (number % factor == 0)
            {
                isPrimeNumber = false;
            }
        }

        if (isPrimeNumber)
        {
            cout << number << '\n';
        }
    }
}
