#pragma once

#include <iostream>

using namespace std;

class NumberSequences
{
public:
	static void displaySquaredNumberSequence(int limit)
	{
		NumberSequences::displayBeginningCharacters();
		for (int index = 1; index <= limit; index += 1)
		{
			cout << index * index;
			NumberSequences::displayValueSeparatorCharacters(index, limit);
		}
		NumberSequences::displayEndingCharacters();
	}

	static void displayCubedNumberSequence(int limit)
	{
		NumberSequences::displayBeginningCharacters();
		for (int index = 1; index <= limit; index += 1)
		{
			cout << index * index * index;
			NumberSequences::displayValueSeparatorCharacters(index, limit);
		}
		NumberSequences::displayEndingCharacters();
	}

	static void displayTrigonometricNumberSequence(int limit)
	{
		NumberSequences::displayBeginningCharacters();
		for (int index = 1; index <= limit; index += 1)
		{
			cout << ((index * index) + index) / 2;
			NumberSequences::displayValueSeparatorCharacters(index, limit);
		}
		NumberSequences::displayEndingCharacters();
	}

private:
	static void displayBeginningCharacters()
	{
		cout << "[";
	}

	static void displayValueSeparatorCharacters(int index, int limit)
	{
		if (index <= limit - 1)
		{
			cout << ", ";
		}
	}

	static void displayEndingCharacters()
	{
		cout << "]";
		cout << endl;
	}
};
