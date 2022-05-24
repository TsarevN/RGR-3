#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int binarySearch(int a, int* mas, int n)
{
	int middle = 0;
	int low = 0;
	int high = n - 1;
	int p = 1;
	while (low <= high)
	{
		middle = (p * high + low) / (p + 1);
		if (a < mas[middle])
			high = middle - 1;
		else if (a > mas[middle])
			low = middle + 1;
		else
			return middle;
	}
	return -1;
}

void hoarasort(int* a, int first, int last)
{

	int i = first, j = last;
	int tmp = 0;
	int x = a[(first + last) / 2];

	do {
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;

		if (i <= j)
		{
			if (i < j)
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
			i++;
			j--;
		}
	} while (i <= j);

	if (i < last)
		hoarasort(a, i, last);
	if (first < j)
		hoarasort(a, first, j);
}

int main()
{
	clock_t start, end, end1, start1;
	int size = 100000000;
	srand(time(0));
	int* array = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 10;
	}

	start = clock();
	hoarasort(array, 0, size - 1);
	end = clock();
	printf("Time sort: %ld %lf\n", end - start, (double)(end - start) / CLOCKS_PER_SEC);
	start1 = clock();
	binarySearch(9, array, size);
	end1 = clock();
	printf("Time search: %ld %lf\n", end1 - start1, (double)(end1 - start1) / CLOCKS_PER_SEC);

	printf("Time sort + search: %ld %lf\n", end1 - start, (double)(end1 - start) / CLOCKS_PER_SEC);
	
	int index = binarySearch(9, array, size);
	printf("index = %d\n", index);
	printf("array[%d] = %d\n", index, array[index]);




	return 0;
}
