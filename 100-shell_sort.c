#include "sort.h"

/**
 * get_max_gap - a function that gets the a largest Knuth
 * Sequence gap for this size
 * @size: the size of the array
 *
 * Return: the gap size
 */
size_t get_max_gap(size_t size)
{
size_t n;

n = 1;
while (n < size)
n = n * 3 + 1;
return ((n - 1) / 3);
}

/**
 * shell_sort - a function that sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 *
 * @array: the array to be sorted
 *
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
size_t gap, i, j;
int temp;

if (!array || !size)
return;


for (gap = get_max_gap(size); gap; gap = (gap - 1) / 3)
{
for (i = gap; i < size; i++)
{
temp = array[i];
for (j = i; j > gap - 1 && array[j - gap] > temp; j -= gap)
{
array[j] = array[j - gap];
}
array[j] = temp;
}
print_array(array, size);
}
}
