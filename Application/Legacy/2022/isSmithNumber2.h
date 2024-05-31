#pragma once

int isSmithNumber()
{
    int inputNumber = 0;
    std::cin >> inputNumber;

    int sum = 0;
    int temp = inputNumber;
    while (temp > 0)
    {
        sum += temp % 10;
        temp = temp / 10;
    }

    int product = 0;
    int a = 2;
    temp = inputNumber;
    while (sum != product && a <= inputNumber)
    {
        bool isPrime = true;
        for (int b = 2; b < a; b += 1)
        {
            if (a % b == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
        {
            while (temp > 1)
            {
                if (temp % a == 0)
                {
                    temp = temp / a;
                    int e = a;
                    while (e > 0)
                    {
                        int value = e % 10;
                        if (value > 1 || a < 10)
                        {
                            product += value;        
                        }

                        e /= 10;    
                    }
                }
                else
                {
                    break;
                }
            }
        }
        a += 1;
    }

    std::cout << sum << '\n';
    std::cout << product << '\n';
    if (sum == product)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
