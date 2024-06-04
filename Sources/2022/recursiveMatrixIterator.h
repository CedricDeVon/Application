#pragma once

template <typename Type> void recursiveMatrixIterator(std::vector<std::vector<Type>> items);
template <typename Type> void recursiveMatrixIterator(std::vector<std::vector<Type>> items, unsigned int rowIndex, unsigned int columnIndex);

template <typename Type> void recursiveMatrixIterator(std::vector<std::vector<Type>> items)
{
	recursiveMatrixIterator(items, 0, 0);
}

template <typename Type> void recursiveMatrixIterator(std::vector<std::vector<Type>> items, unsigned int rowIndex, unsigned int columnIndex)
{
	if (rowIndex >= items.size())
	{
		return;
	}

	std::cout << items[rowIndex][columnIndex] << " ";
	if (columnIndex >= items[rowIndex].size() - 1)
	{
		std::cout << '\n';
		recursiveMatrixIterator(items, rowIndex + 1, 0);
	}
	else
	{
		recursiveMatrixIterator(items, rowIndex, columnIndex + 1);
	}
}


