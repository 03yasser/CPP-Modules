#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <typename array, typename func>
void	iter(array *arr, size_t len, func f)
{
	if (arr == NULL || len == 0 || f == NULL)
		return;
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

#endif