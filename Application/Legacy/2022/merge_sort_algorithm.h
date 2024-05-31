#pragma once
#include <iostream>
#include "sort_algorithm.h"

template <typename Type> class Merge_Sort_Algorithm : public Sort_Algorithm<Type>
{
public:
	void sort_in_ascending_order(Type values[], unsigned int size)
	{
		Merge_Sort_Algorithm<Type>::_sort_in_ascending_order(values, 0, size - 1);
	}

private:
	void _sort_in_ascending_order(Type values[], unsigned int size, unsigned int e)
	{
		if (size >= e)
		{
			return;
		}

		int m = (size + e) / 2;
		Merge_Sort_Algorithm<Type>::_sort_in_ascending_order(values, size, m);
		Merge_Sort_Algorithm<Type>::_sort_in_ascending_order(values, m + 1, e);

		Type* buffer = new Type[e + 1];
		int k = size;
		while (k <= e)
		{
			buffer[k] = values[k];
			k += 1;
		}

		int i = size;
		int j = m + 1;
		k = size;

		while (i <= m && j <= e)
		{
			if (buffer[i] <= buffer[j])
			{
				values[k] = buffer[i];
				i += 1;
			}
			else
			{
				values[k] = buffer[j];
				j += 1;
			}
			k += 1;
		}
		while (i <= m)
		{
			values[k] = buffer[i];
			i += 1;
			k += 1;
		}

		while (j <= e)
		{
			values[k] = buffer[j];
			j += 1;
			k += 1;
		}

		delete[] buffer;
	}
};