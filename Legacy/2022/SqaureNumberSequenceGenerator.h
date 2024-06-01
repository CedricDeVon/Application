#pragma once

#include <iostream>

using namespace std;

class SqaureNumberSequenceGenerator
{
public:
	static void execute(int limit)
	{
		cout << "[";
		for (int base = 1; base <= limit; base += 1)
		{
			cout << base * base;
			if (base <= limit - 1)
			{
				cout << ", ";
			}
		}
		cout << "]";
		cout << endl;
	}
};

