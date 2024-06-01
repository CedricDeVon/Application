#pragma once

class Misc
{
public:
	void print_primes(unsigned int last_number)
	{
		for (unsigned int current_number = 2; current_number < last_number; current_number += 1)
		{
			bool is_prime = true;
			for (unsigned int factor = 2; factor < current_number && is_prime; factor += 1)
			{
				if (current_number % factor == 0)
				{
					is_prime = false;
					break;
				}
			}
			if (is_prime)
			{
				std::cout << current_number << '\n';
			}
		}
	}



	void fizz_buzz(unsigned int total_iterations)
	{
		for (int current_iteration = 1; current_iteration <= total_iterations; current_iteration += 1)
		{
			if (current_iteration % 3 == 0 && current_iteration % 5 == 0)
			{
				std::cout << "FizzBuzz";
			}
			else if (current_iteration % 3 == 0)
			{
				std::cout << "Fizz";
			}
			else if (current_iteration % 5 == 0)
			{
				std::cout << "Buzz";
			}
			else
			{
				std::cout << current_iteration;
			}
			std::cout << '\n';
		}
	}

	int* get_digit_sum(int number)
	{
		int* digit_sum = new int(0);
		while (number > 0)
		{
			*digit_sum += number % 10;
			number /= 10;
		}
		return digit_sum;
	}

	void bubble_sort_ascending(int numbers[], unsigned int size)
	{
		for (int index_i = 0; index_i < size; index_i += 1)
		{
			for (int index_j = index_i + 1; index_j < size; index_j += 1)
			{
				int number_i = numbers[index_i];
				int number_j = numbers[index_j];
				if (number_i > number_j)
				{
					numbers[index_i] = number_j;
					numbers[index_j] = number_i;
				}
			}
		}
	}

	bool is_number_found_via_binary_search(int target_value, int numbers[], int size)
	{
		return this->_is_number_found_via_binary_search(target_value, numbers, size, 0, 0, size);

	}
private:
	bool _is_number_found_via_binary_search(int target_value, int numbers[], int size, int start, int middle, int end)
	{
		if (start < 0 || start > end)
		{
			return false;
		}

		middle = (start + end) / 2;
		int current_number = numbers[middle];
		if (target_value == current_number)
		{
			return true;
		}
		else if (target_value > current_number)
		{
			return this->_is_number_found_via_binary_search(target_value, numbers, size, middle, middle + 1, size);
		}
		else if (target_value < current_number)
		{
			return this->_is_number_found_via_binary_search(target_value, numbers, size, 0, middle - 1, middle);
		}
	}


};
