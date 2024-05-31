
bool isNumberIncreasingDecreasingOrBouncy(unsigned int number)
{
    bool areDigitsIncreasing = true;
    bool areDigitsDecreasing = true;
    unsigned int temporaryNumberA = number / 10;
    unsigned int temporaryNumberB = number;
    while (temporaryNumberA > 0)
    {
        if (temporaryNumberA % 10 > temporaryNumberB % 10)
        {
            areDigitsIncreasing = false;
        }
        if (temporaryNumberA % 10 < temporaryNumberB % 10)
        {
            areDigitsDecreasing = false;
        }
      
        temporaryNumberA /= 10;  
        temporaryNumberB /= 10;  
    }
  
    if (areDigitsIncreasing || areDigitsDecreasing)
    {
        return true;
    }
    else
    {
        return false;
    }
}

unsigned long long total_inc_dec(unsigned int n)
{
    unsigned long long count = 0;
    n = pow(10, n);
    for (unsigned int i = 0; i < n; i += 1)
    {
        if (isNumberIncreasingDecreasingOrBouncy(i))
        {
            count += 1;
        }
    }
    return count;
}
