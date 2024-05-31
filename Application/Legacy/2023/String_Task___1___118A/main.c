#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

bool is_consonant(char c)
{
	return !((c == 'a' || c == 'A') ||
			(c == 'e' || c == 'E') ||
			(c == 'i' || c == 'I') ||
			(c == 'o' || c == 'O') ||
			(c == 'y' || c == 'Y') ||
			(c == 'u' || c == 'U'));
}

bool is_uppercased(char c)
{
	return 'A' <= c && c <= 'Z';
}

int main(void)
{
	char txt[100];
	scanf("%s", txt);
	int txt_s = strlen(txt);
	int m_s = 0;
	for (int i = 0; i < txt_s; i++)
	{
		char c = txt[i];
		if (is_consonant(c))
		{
			m_s += 2;
		}
	}

	int m_i = 0;
	char m[m_s];
	for (int i = 0; i < txt_s && i < m_s; i++)
	{
		char c = txt[i];
		if (is_consonant(c))
		{
			m[m_i++] = '.';
			m[m_i++] = (is_uppercased(c)) ? c + 32 : c;
		}
	}
	for (int i = 0; i < m_s; i++)
	{
		printf("%c", m[i]);
	}

	int exit_code = 0;
	scanf("%d", &exit_code);

	return 0;
}
