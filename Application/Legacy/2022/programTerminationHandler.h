#pragma once

#include <iostream>
#include <string>

using namespace std;

void programTerminationHandler()
{
	string input = "";
	cout << "\nEnter any key to terminate the program..." << '\n';
	cin >> input;
}


// void dispFibsReciprocalInRange(int s, int e)
// {

// }

// double fibsReciprocalSumInRange(int s, int e)
// {

// }




// #include <iostream>
// #include "./programTerminationHandler.h"

// using namespace std;

// int binarySearch(int[], int, int);
// int binarySearch(int[], int, int, int, int, int);

// int main()
// {
// 	int sizeOfNumbers = 10;
// 	int numbers[sizeOfNumbers] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
// 	int targetNumber = 4;
// 	int indexOfTargetNumber = binarySearch(numbers, sizeOfNumbers, targetNumber);
// 	cout << indexOfTargetNumber;
// 	programTerminationHandler();
// 	return 0;
// }

// int binarySearch(int numbers[], int size,
// 				int targetNumber, int startingIndex,
// 				int middleIndex, int endingIndex)
// {
// 	if (middleIndex < 0 || middleIndex > size)
// 	{
// 		return -1;
// 	}

// 	int currentNumber = numbers[middleIndex];
// 	if (targetNumber == currentNumber)
// 	{
// 		return middleIndex;
// 	}
// 	else if (targetNumber > currentNumber)
// 	{
// 		return binarySearch(numbers, size, targetNumber, middleIndex, (endingIndex - middleIndex) / 2, endingIndex);
// 	}

// 	return binarySearch(numbers, size, targetNumber, startingIndex, (endingIndex + startingIndex) / 2, middleIndex);
// }

// int binarySearch(int numbers[], int size, int targetNumber)
// {
// 	return binarySearch(numbers, size, targetNumber, 0, size / 2, size);
// }


// string encrypt(string text, string cypherKey)
// {
// 	string cypher = "";
// 	int base = 1;
// 	for (int i = 0; i < text.size() + cypherKey.size(); i += 1)
// 	{
// 		int aBase = (int) text[i % text.size()];
// 		int bBase = (int) cypherKey[i % cypherKey.size()];
// 		base += aBase + bBase;
// 		int answer = (base + (aBase * bBase)) % 123;
// 		if (answer < 48)
// 		{
// 			answer += 48;
// 		}
// 		if (i >= text.size())
// 		{
// 			cypher += " ";
// 		}
// 		else
// 		{
// 			cypher += answer;	
// 		}
		
// 	}
// 	return cypher;
// 	// int countB = 1;
// 	// for (int i = 0; i < text.size() * cypherKey.size(); i += 1)
// 	// {


// 	// 	text[i % text.size()] = (char) answer;
// 	// }

// 	// return text;
// }

