#pragma once

template <typename Type> void printArrayItems(Type items[], unsigned int size)
{
	for (unsigned int currentIndex = 0; currentIndex < size; currentIndex += 1)
	{
		std::cout << items[currentIndex] << " ";
	}
}

