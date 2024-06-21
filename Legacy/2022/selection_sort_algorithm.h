#pragma once
#include <iostream>
#include "sort_algorithm.h"

template <typename Type> class Selection_Sort_Algorithm : public Sort_Algorithm<Type>
{
public:
	void sort_in_ascending_order(Type values[], unsigned int size)
	{
		if (size <= 0)
		{
			exit(1);
		}

		int index_i = 0;
		while (index_i < size)
		{
			int index_j = index_i;
			int index_k = index_i;
			while (index_j < size)
			{
				if (values[index_j] < values[index_k])
				{
					index_k = index_j;
				}
				index_j += 1;
			}

			Type temporary_value_i = values[index_i];
			values[index_i] = values[index_k];
			values[index_k] = temporary_value_i;
			index_i += 1;
		}
	}

	void sort_in_descending_order(Type values[], unsigned int size)
	{
		if (size <= 0)
		{
			exit(1);
		}

		int index_i = 0;
		while (index_i < size)
		{
			int index_j = index_i;
			int index_k = index_i;
			while (index_j < size)
			{
				if (values[index_j] > values[index_k])
				{
					index_k = index_j;
				}
				index_j += 1;
			}

			Type temporary = values[index_i];
			values[index_i] = values[index_k];
			values[index_k] = temporary;
			index_i += 1;
		}
	}
};
