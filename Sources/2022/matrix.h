#pragma once

#include <iostream>
#include <cstdio>

template<typename Type> class Matrix
{
private:
	unsigned int maximum_row_size;
	unsigned int maximum_column_size;
	Type** items = NULL;

public:
	unsigned int get_maximum_row_size()
	{
		return this->maximum_row_size;
	}

	unsigned int get_maximum_column_size()
	{
		return this->maximum_column_size;
	}

	Matrix(unsigned int maximum_row_size, unsigned int maximum_column_size)
	{
		this->maximum_row_size = maximum_row_size;
		this->maximum_column_size = maximum_column_size;
		this->items = new Type * [this->maximum_row_size];
		for (int row_index = 0; row_index < this->maximum_row_size; row_index += 1)
		{
			this->items[row_index] = new Type[this->maximum_column_size];
			for (int column_index = 0; column_index < this->maximum_column_size; column_index += 1)
			{
				this->items[row_index][column_index] = NULL;
			}
		}
	}

	void insert_value_at_coordinates(Type value, unsigned int row_index, unsigned int column_index)
	{
		if ((row_index < 0 || row_index >= this->maximum_row_size) ||
			(column_index < 0 || column_index >= this->maximum_column_size))
		{
			throw std::exception();
		}

		this->items[row_index][column_index] = value;
	}

	void remove_value_at_coordinates(unsigned int row_index, unsigned int column_index)
	{
		if ((row_index < 0 || row_index >= this->maximum_row_size) ||
			(column_index < 0 || column_index >= this->maximum_column_size))
		{
			throw std::exception();
		}

		this->items[row_index][column_index] = NULL;
	}

	void print_top_left_to_bottom_right_diagonal_items()
	{
		if (this->maximum_row_size != this->maximum_column_size)
		{
			throw std::exception();
		}

		std::cout << "[";
		for (int row_index = 0; row_index < this->maximum_row_size; row_index += 1)
		{
			std::cout << this->items[row_index][row_index];
			if (row_index < this->maximum_row_size - 1)
			{
				std::cout << ", ";
			}
		}
		std::cout << "]\n";
	}

	void print_top_right_to_bottom_left_diagonal_items()
	{
		if (this->maximum_row_size != this->maximum_column_size)
		{
			throw std::exception();
		}

		std::cout << "[";
		for (int row_index = 0; row_index < this->maximum_row_size; row_index += 1)
		{
			std::cout << this->items[row_index][this->maximum_column_size - row_index - 1];
			if (row_index < this->maximum_row_size - 1)
			{
				std::cout << ", ";
			}
		}
		std::cout << "]\n";
	}

	void print_all_items()
	{
		std::cout << "Items:" << '\n';
		for (int row_index = 0; row_index < this->maximum_row_size; row_index += 1)
		{
			std::cout << "[";
			for (int column_index = 0; column_index < this->maximum_column_size; column_index += 1)
			{
				std::cout << this->items[row_index][column_index];
				if (column_index < this->maximum_column_size - 1)
				{
					std::cout << ", ";
				}
			}
			std::cout << "]\n";
		}
	}

	bool is_value_found(Type value)
	{
		for (int row_index = 0; row_index < this->maximum_row_size; row_index += 1)
		{
			for (int column_index = 0; column_index < this->maximum_column_size; column_index += 1)
			{
				if (this->items[row_index][column_index] == value)
				{
					return true;
				}
			}
		}

		return false;
	}

	bool is_value_found_at_coordinates(Type value, unsigned int row_index, unsigned int column_index)
	{
		if ((row_index < 0 || row_index >= this->maximum_row_size) ||
			(column_index < 0 || column_index >= this->maximum_column_size))
		{
			throw std::exception();
		}

		if (value == this->items[row_index][column_index])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
