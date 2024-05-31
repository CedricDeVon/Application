#pragma once

#include <cstdlib>
#include <iostream>

template <typename Type> class ArrayList
{
private:
	unsigned int maximum_size = 0;
	unsigned int current_size = 0;
	Type* items = NULL;

public:
	ArrayList(unsigned int maximum_size)
	{
		if (maximum_size <= 0)
		{
			throw std::exception();
		}

		this->maximum_size = maximum_size;
		this->items = new Type[this->maximum_size];
	}

	int get_maximum_size()
	{
		return this->maximum_size;
	}

	int get_current_size()
	{
		return this->current_size;
	}

	Type* get_items()
	{
		return this->items;
	}

	void insert_item_at_the_first_index(Type value)
	{
		if (this->current_size >= this->maximum_size)
		{
			throw std::exception();
		}

		if (this->current_size > 0)
		{
			for (int current_index = this->current_size - 1; current_index >= 0; current_index -= 1)
			{
				this->items[current_index + 1] = this->items[current_index];
			}
		}

		this->items[0] = value;
		this->current_size += 1;
	}

	void insert_item_at_the_last_index(Type value)
	{
		if (this->current_size >= this->maximum_size)
		{
			throw std::exception();
		}

		this->items[this->current_size] = value;
		this->current_size += 1;
	}

	void insert_item_at_index(Type value, unsigned int target_index)
	{
		// TODO
		if (this->current_size >= this->maximum_size || target_index < 0)
		{
			throw std::exception();
		}

		if (this->current_size > 0)
		{
			for (int current_index = this->current_size - 1; current_index >= target_index; current_index -= 1)
			{
				this->items[current_index + 1] = this->items[current_index];
			}
		}

		this->items[target_index] = value;
		this->current_size += 1;
	}

	void remove_item_at_the_first_index(Type value)
	{
		if (this->current_size <= 0)
		{
			throw std::exception();
		}

		delete this->items[0];
		this->items[0] = NULL;
		for (unsigned int index = 0; index < this->current_size - 1; index += 1)
		{
			this->items[index] = this->items[index + 1];
		}
		this->current_size -= 1;
	}

	void remove_item_at_the_last_index(Type value)
	{
		if (this->current_size <= 0)
		{
			throw std::exception();
		}

		delete this->items[this->current_size];
		this->items[this->current_size] = NULL;
		this->current_size -= 1;
	}

	void remove_item_at_index(Type value, unsigned int target_index)
	{
		if (this->current_size <= 0 || target_index < 0 || target_index >= this->current_size)
		{
			throw std::exception();
		}

		delete this->items[target_index];
		this->items[target_index] = NULL;
		for (unsigned int current_index = target_index; current_index < this->current_size - 1; current_index += 1)
		{
			this->items[current_index] = this->items[current_index + 1];
		}
		this->current_size -= 1;
	}

	bool is_value_found(Type value)
	{
		for (unsigned int index = 0; index < this->current_size; index += 1)
		{
			if (this->items[index] == value)
			{
				return true;
			}
		}

		return false;
	}

	int get_index_of_value(Type value)
	{
		for (unsigned int index = 0; index < this->current_size; index += 1)
		{
			if (this->items[index] == value)
			{
				return index;
			}
		}

		return -1;
	}
};



/*

void push(int value)
{
	this->handleContainerFullError();

	this->items[this->currentNodeCount] = ArrayListItem(value);
	this->currentNodeCount += 1;
}

int pop()
{
	this->handleContainerEmptyError();

	ArrayListItem listItem = this->items[this->currentNodeCount];
	this->items[this->currentNodeCount] = NULL;
	this->currentNodeCount -= 1;
	return listItem.getValue();
}

int indexOfNode(int value)
{
	for (int index = 0; index < this->currentNodeCount; index += 1)
	{
		ArrayListItem listItem = this->items[index];
		if (listItem.getValue() == value)
		{
			return index;
		}
	}

	return -1;
}

int linearSearchIndexOfNodeValue(int value)
{
	for (int index = 0; index < this->currentNodeCount; index += 1)
	{
		ArrayListItem node = this->items[index];
		int nodeValue = node.getValue();
		if (nodeValue == value)
		{
			return index;
		}
	}
	return -1;
}

int binarySearchIndexOfNodeValue(int value)
{
	return this->_binarySearchIndexOfNodeValue(value, this->currentNodeCount);
}

private:
	class ArrayListItem
	{
	public:
		ArrayListItem(int value)
		{
			this->value = value;
		}

		int getValue()
		{
			return this->value;
		}

	private:
		int value;
	};

	int _binarySearchIndexOfNodeValue(int value, int endingIndex, int startingIndex = 0, int middleIndex = 0)
	{
		if (startingIndex < 0 || startingIndex > endingIndex)
		{
			return -1;
		}

		middleIndex = (startingIndex + endingIndex) / 2;
		int arrayListItemValue = this->items[middleIndex].getValue();
		if (arrayListItemValue == value)
		{
			return middleIndex;
		}
		else if (arrayListItemValue > value)
		{
			return this->_binarySearchIndexOfNodeValue(value, middleIndex, startingIndex, middleIndex - 1);
		}
		else if (arrayListItemValue < value)
		{
			return this->_binarySearchIndexOfNodeValue(value, endingIndex, middleIndex, middleIndex + 1);
		}
	}

	int maximumNodeCount;
	int currentNodeCount;
	ArrayListItem* items;

	void handleParameterLessThanOrEqualToZeroError(int maximumNodeCount)
	{
		if (maximumNodeCount <= 0)
		{
			std::cout << "ParameterLessThanOrEqualToZeroError";
			exit(1);
		}
	}

	void handleContainerFullError()
	{
		if (this->currentNodeCount >= this->maximumNodeCount)
		{
			std::cout << "ContainerFullError";
			exit(1);
		}
	}

	void handleContainerEmptyError()
	{
		if (this->currentNodeCount <= 0)
		{
			std::cout << "ContainerEmptyError";
			exit(1);
		}
	}*/

