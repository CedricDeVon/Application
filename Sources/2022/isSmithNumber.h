#pragma once

int getDigitSumOfNumber(int number)
{
   int digitSum = 0;
   while (number > 0) 
   {
       int digit = number % 10;
       digitSum += digit;
       number /= 10;
   }
   
   return digitSum;
}

int isSmithNumber(int baseNumber)
{
    int digitSumOfNumber = getDigitSumOfNumber(baseNumber);
    int digitPrimeFactorSumOfNumber = 0;
    for (int possibleFactor = 2; possibleFactor <= baseNumber; possibleFactor += 1)
    {
        while (baseNumber % possibleFactor == 0)
        {
            digitPrimeFactorSumOfNumber += getDigitSumOfNumber(possibleFactor);
            baseNumber /= possibleFactor;
        }
    }
    
    return (digitSumOfNumber == digitPrimeFactorSumOfNumber) ? 1 : 0;
}