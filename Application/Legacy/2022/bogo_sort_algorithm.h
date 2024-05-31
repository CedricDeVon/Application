#pragma once
#include <iostream>
#include <cstdlib>
#include "sort_algorithm.h"

template <typename Type> class Bogo_Sort_Algorithm : public Sort_Algorithm<Type>
{
public:
	void sort_in_ascending_order(Type values[], unsigned int size)
	{
		srand((unsigned)time(NULL));
		int isFullySorted = 0;
		while (!isFullySorted)
		{
			for (int i = 0; i < size; i += 1)
			{
				int j = rand() % size;
				int temp = values[i];
				values[i] = values[j];
				values[j] = temp;
			}

			int isSorted = 1;
			for (int i = 1; i < size && isSorted; i += 1)
			{
				if (values[i - 1] > values[i])
				{
					isSorted = 0;
				}
			}

			if (isSorted)
			{
				isFullySorted = 1;
			}
		}
	}

	void sort_in_descending_order(Type values[], unsigned int size)
	{
		srand((unsigned)time(NULL));
		int isFullySorted = 0;
		while (!isFullySorted)
		{
			for (int i = 0; i < size; i += 1)
			{
				int j = rand() % size;
				int temp = values[i];
				values[i] = values[j];
				values[j] = temp;
			}

			int isSorted = 1;
			for (int i = 1; i < size && isSorted; i += 1)
			{
				if (values[i - 1] < values[i])
				{
					isSorted = 0;
				}
			}

			if (isSorted)
			{
				isFullySorted = 1;
			}
		}
	}
};
