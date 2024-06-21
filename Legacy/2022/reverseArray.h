#pragma once

template <typename Type> void reverseArray(Type items[], unsigned int size)
{
	unsigned int middleIndex = size / 2;
	if (size % 2 == 0)
	{
		middleIndex -= 1;	
	}
	
	for (int currentIndex = 0; currentIndex <= middleIndex; currentIndex += 1)
	{
		Type leftItem = items[currentIndex];
		Type rightItem = items[size - 1 - currentIndex];
		items[currentIndex] = rightItem;
		items[size - 1 - currentIndex] = leftItem;
	}
}

