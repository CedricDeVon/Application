#pragma once
#include <iostream>
#include "sort_algorithm.h"

template <typename Type> class Insertion_Sort_Algorithm : public Sort_Algorithm<Type>
{
public:
	void sort_in_ascending_order(Type values[], unsigned int size)
	{
		if (size <= 0)
		{
			exit(1);
		}

		int index_i = 1;
		while (index_i < size)
		{
			int key = values[index_i];
			int index_j = index_i - 1;
			while (index_j >= 0 && values[index_j] > key)
			{
				values[index_j + 1] = values[index_j];
				index_j -= 1;
			}
			values[index_j + 1] = key;
			index_i += 1;
		}
	}

	void sort_in_descending_order(Type values[], unsigned int size)
	{
		if (size <= 0)
		{
			exit(1);
		}

		int index_i = 1;
		while (index_i < size)
		{
			int key = values[index_i];
			int index_j = index_i - 1;
			while (index_j >= 0 && values[index_j] < key)
			{
				values[index_j + 1] = values[index_j];
				index_j -= 1;
			}

			values[index_j + 1] = key;
			index_i += 1;
		}
	}
};
