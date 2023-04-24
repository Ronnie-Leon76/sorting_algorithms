#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order using Quicksort
 * @array: array of integers
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_rec(array, 0, size - 1, size);
}
/**
 * quick_sort_rec - sorts an array of integers in ascending order
 * @array: array of integers
 * @low: low index
 * @high: high index
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quick_sort_rec(array, low, pivot - 1, size);
		quick_sort_rec(array, pivot + 1, high, size);
	}
}

/**
 * partition - sorts an array of integers in ascending order
 * @array: array of integers
 * @low: low index
 * @high: high index
 * @size: size of the array
 *
 * Return: void
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	if (i + 1 != high)
		print_array(array, size);
	return (i + 1);
}
