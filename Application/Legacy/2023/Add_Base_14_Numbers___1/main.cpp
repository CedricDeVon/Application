#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

void program_termination()
{
	int exit_code;
	std::cin >> exit_code;
}

bool is_character_between_0_to_9(char v)
{
	return ('0' - 1) < v && v < ('9' + 1);
}

bool is_character_between_A_to_D(char v)
{
	return ('A' - 1) < v && v < ('D' + 1);
}

int convert_base14_char_to_base10_int(char v)
{
	if (is_character_between_0_to_9(v))
	{
		return v - '0';
	}
	else if (is_character_between_A_to_D(v))
	{
		return v - 'A' + 10;
	}
	return 0;
}

bool is_valid_base14_value(std::string v)
{
	for (unsigned long long int i = 0; i < v.size(); i++)
	{
		char c = v[i];
		if (!(is_character_between_0_to_9(c) || is_character_between_A_to_D(c)))
		{
			return false;
		}
	}

	return true;
}

unsigned long long int convert_base14_to_base_10(std::string& v)
{
	unsigned long long int o = 0;
	for (unsigned long long int i = 0; i < v.size(); i++)
	{
		o += (convert_base14_char_to_base10_int(v[i]) * pow(14, v.size() - i - 1));
	}
	return o;
}

int main(void)
{
	std::string f;
	std::cin >> f;

	std::string s;
	std::cin >> s;

	if (!is_valid_base14_value(f) || !is_valid_base14_value(s))
	{
		std::cout << "ERROR" << "\n";
	}
	else
	{
		std::cout << convert_base14_to_base_10(f) + convert_base14_to_base_10(s) << "\n";
	}

	program_termination();
	return 0;
}