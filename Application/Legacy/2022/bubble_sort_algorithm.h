#pragma once
#include <iostream>
#include "sort_algorithm.h"

template <typename Type> class Bubble_Sort_Algorithm : public Sort_Algorithm<Type>
{
public:
	void sort_in_ascending_order(Type values[], unsigned int size)
	{
		if (size <= 0)
		{
			throw std::exception();
		}

		for (int index_i = 0; index_i < size; index_i += 1)
		{
			for (int index_j = index_i + 1; index_j < size; index_j += 1)
			{
				int value_i = values[index_i];
				int value_j = values[index_j];
				if (value_i > value_j)
				{
					values[index_i] = value_j;
					values[index_j] = value_i;
				}
			}
		}
	}

	void sort_in_descending_order(Type values[], unsigned int size)
	{
		if (size <= 0)
		{
			throw std::exception();
		}

		for (int index_i = 0; index_i < size; index_i += 1)
		{
			for (int index_j = index_i + 1; index_j < size; index_j += 1)
			{
				int value_i = values[index_i];
				int value_j = values[index_j];
				if (value_i < value_j)
				{
					values[index_i] = value_j;
					values[index_j] = value_i;
				}
			}
		}
	}
};
