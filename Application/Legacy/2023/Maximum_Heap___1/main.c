#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <ctype.h>
#include <limits.h>

#include "solution.h"

double calculate_duration_in_seconds(clock_t start, clock_t end)
{
	return (end - start) / CLOCKS_PER_SEC;
}

long long int generate_random_positive_number(long long int limit)
{
	return rand() % (abs(limit) + 1);
}

long long int generate_random_negative_number(long long int limit)
{
	return -(generate_random_positive_number(limit));
}

long long int generate_random_number(long long int limit)
{
	return (rand() % 2 == 1) ?
		generate_random_positive_number(limit) :
		generate_random_negative_number(limit);
}

float generate_random_positive_float_number(float limit)
{
	return ((float) rand() / (float)(RAND_MAX)) * abs(limit);
}

float generate_random_negative_float_number(float limit)
{
	return -(generate_random_positive_float_number(limit));
}

float generate_random_float_number(float limit)
{
	return (rand() % 2 == 1) ?
		generate_random_positive_float_number(limit) :
		generate_random_negative_float_number(limit);
}

int main(void)
{
	srand((unsigned int) time(NULL));
	int size = 100000;
	MaximumHeap heap = MaximumHeap_allocate(size);
	for (unsigned int i = 0; i < size - 1; i++)
	{
		long long int number = generate_random_number(100);
		MaximumHeap_insert(heap, number);
		// printf("%lld : ", number);
	}
	MaximumHeap_insert(heap, 123456);
	printf("%lld : \n", MaximumHeap_get_maximum(heap));
	MaximumHeap_display(heap);

	heap = MaximumHeap_deallocate(heap);

	// MaximumHeap heap = MaximumHeap_allocate(100000);
	// for (long long int i = 0; i < heap->maximum_size; i++)
	// {
	// 	MaximumHeap_insert(heap, generate_random_float_number(10));
	// }

	// clock_t start = clock();
	// MaximumHeap_deallocate(heap);
	// clock_t end = clock();

	// for (long long int i = 0; i < heap->maximum_size; i++)
	// {
	// 	printf("%lf\n", heap->items[i]);
	// }
	// printf("Duration: %lf seconds \n", calculate_duration_in_seconds(start, end));

	// clock_t start = clock();
	// Sleep(1250);
	// clock_t end = clock();
	// printf("%lf \n", (double)(end - start) / CLOCKS_PER_SEC);

	// MaximumHeap_deallocate(heap);

	// long long int limit = 10;
	// for (int i = 0; i < 1000; i++)
	// {
	// 	printf("%ld \n", generate_random_number(limit));
	// }

	// srand((unsigned int) time(NULL));

	// float limit = 100;
	// for (int i = 0; i < 100; i++)
	// {
	// 	printf("%f \n", generate_random_float_number(limit));
	// }

	// printf("char \n");
	// printf("%d \n", sizeof(char));
	// printf("%d ... %d \n\n", CHAR_MIN, CHAR_MAX);

	// printf("unsigned char \n");
	// printf("%d \n", sizeof(unsigned char));
	// printf("%d ... %d \n\n", 0, UCHAR_MAX);

	// printf("short \n");
	// printf("%d \n", sizeof(short));
	// printf("%d ... %d \n\n", SHRT_MIN, SHRT_MAX);

	// printf("unsigned short \n");
	// printf("%d \n", sizeof(unsigned short));
	// printf("%d ... %d \n\n", 0, USHRT_MAX);

	// printf("int \n");
	// printf("%d \n", sizeof(int));
	// printf("%d ... %d \n\n", INT_MIN, INT_MAX);

	// printf("unsigned int \n");
	// printf("%d \n", sizeof(unsigned int));
	// printf("%d ... %u \n\n", 0, UINT_MAX);

	// printf("long int \n");
	// printf("%d \n", sizeof(long int));
	// printf("%ld ... %ld \n\n", LONG_MIN, LONG_MAX);

	// printf("unsigned long int \n");
	// printf("%d \n", sizeof(unsigned long int));
	// printf("%d ... %lu \n\n", 0, ULONG_MAX);

	// printf("long long int \n");
	// printf("%d \n", sizeof(long long int));
	// printf("%lld ... %lld \n\n", LLONG_MIN, LLONG_MAX);

	// printf("unsigned long long int \n");
	// printf("%d \n", sizeof(unsigned long long int));
	// printf("%d ... %llu \n\n", 0, ULLONG_MAX);

	// printf("float \n");
	// printf("%d \n\n", sizeof(float));

	// printf("double \n");
	// printf("%d \n\n", sizeof(double));

	// printf("long double \n");
	// printf("%d \n\n", sizeof(long double));

	// long double v = 1.123;
	// printf("%Lf \n", (long double) v);

	int exit_code = 0;
	scanf("%d", &exit_code);

	return 0;
}

