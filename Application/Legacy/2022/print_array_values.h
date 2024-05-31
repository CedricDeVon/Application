#pragma once
#include <iostream>

template <typename Type>
class Print_Array_Values
{
public:
	static void execute(Type values[], unsigned int size)
	{
		if (size <= 0)
		{
			throw std::exception();
		}

		std::cout << "[";
		for (int index = 0; index < size; index += 1)
		{
			std::cout << values[index];
			if (index < size - 1)
			{
				std::cout << ", ";
			}
		}
		std::cout << "]" << '\n';
	}
};
