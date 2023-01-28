#include "sort.h"

/**
 * bitonic_compare - sorts values in a sub-array, implementing the
 * bitonic sort algorithm
 * @up: sorting direction
 * @array: sub-array to sort
 * @size: size of thesub-array
 * Return: nothing
 */

void bitonic_compare(char up, int *array, size_t size)
{
	size_t i, dist;
	int swap;

	dist = size / 2;
	for (i = 0; i < dist; i++)
	{
		if ((array[i] > array[i + dist]) == up)
		{
			swap = array[i];
			array[i] = array[i + dist];
			array[i + dist] = swap;
		}
	}
}

/**
 * bitonic_merge - merges two sorted sub-arrays
 * @up: direction of sorting
 * @array: sub-array to sort
 * @size: size of the array
 * Return: nothing
 */

void bitonic_merge(char up, int *array, size_t size)
{
	if (size < 2)
		return;
	bitonic_compare(up, array, size);
	bitonic_merge(up, array, size / 2);
	bitonic_merge(up, array + (size / 2), size / 2);
}

/**
 * bit_sort - displays the merging steps
 * @up: sorting direction
 * @array: sub-array to sort
 * @size: size of the sub-array
 * @t_size: size of the original array
 * Return: void
 */

void bit_sort(char up, int *array, size_t size, size_t t_size)
{
	if (size < 2)
		return;
	printf("Merging [%lu/%lu] (%s):\n", size, t_size, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);
	bit_sort(1, array, size / 2, t_size);
	bit_sort(0, array + (size / 2), size / 2, t_size);
	bitonic_merge(up, array, size);
	printf("Result [%lu/%lu] (%s):\n", size, t_size, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);

}

/**
 * bitonic_sort - implements bitonic sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: returns a sorted array in ascending order
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bit_sort(1, array, size, size);
}
