#include <iostream>
#include <vector>
#include "./programTerminationHandler.h"

using namespace std;

unsigned long long int primeNumbers[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541,
547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659,
661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809,
811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941,
947, 953, 967, 971, 977, 983, 991, 997};

int primeCount(unsigned long long int number) {
	std::cout << number << '\n';
    if (number == 1)
    {
        return 0;
    }
    
    int count = 0;
    int index = 0;
    unsigned long long int product = 1;
    while (product * primeNumbers[index] <= number)
    {
    	
        product *= primeNumbers[index];
        count += 1;
        index += 1;
    }

    return count;
}

int main()
{
	std::cout << primeCount(999999999999969970);
	programTerminationHandler();
	
	return 0;
}

// void recursiveIteration(std::vector<int>);
// void recursiveIteration(std::vector<int>, int);

// void recursiveIteration(std::vector<int> numbers)
// {
// 	recursiveIteration(numbers, 0);
// }

// void recursiveIteration(std::vector<int> numbers, int currentIndex)
// {
// 	if (currentIndex >= numbers.size()) { return; }

// 	std::cout << numbers[currentIndex] << " ";
// 	recursiveIteration(numbers, currentIndex + 1);
// }

int binarySearch(int[], int, int);
int binarySearch(int[], int, int, int, int, int);

int binarySearch(int numbers[], int size, int targetNumber)
{
	return binarySearch(numbers, size, targetNumber, 0, size / 2, size);
}

int binarySearch(int numbers[], int size, int targetNumber, int startingIndex, int middleIndex, int endingIndex)
{
	int currentNumber = numbers[middleIndex];
	if ((middleIndex <= 0 && targetNumber != currentNumber) ||
		(middleIndex >= size - 1 && targetNumber != currentNumber))
	{
		return -1;
	}
	else if (targetNumber > currentNumber)
	{
		return binarySearch(numbers, size, targetNumber, middleIndex, (endingIndex + middleIndex) / 2, endingIndex);
	}
	else if (targetNumber < currentNumber)
	{
		return binarySearch(numbers, size, targetNumber, startingIndex, (middleIndex + startingIndex) / 2, middleIndex);	
	}
	else
	{
		return middleIndex; 	
	}
}

