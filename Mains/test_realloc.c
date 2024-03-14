#include "libft.h"

int main()
{
	void *ptr = NULL;
	size_t old_size = 10, new_size = 20;
	void *new_ptr;

	new_ptr = ft_realloc(ptr, old_size, new_size);
	if (new_ptr == NULL)
	{
		ft_printf("Failed to allocate memory  1A\n");
		return 1;
	}
	ft_printf("New pointer: %p\n", new_ptr);

	ptr = malloc(old_size);
	if (ptr == NULL)
	{
		ft_printf("Failed to allocate memory  2A\n");
		return 1;
	}
	new_ptr = ft_realloc(ptr, old_size, new_size);
	if (new_ptr == NULL)
	{
		ft_printf("Failed to reallocate memory  1R\n");
		return 1;
	}
	ft_printf("New pointer: %p\n", new_ptr);

	ptr = malloc(old_size);
	if (ptr == NULL)
	{
		ft_printf("Failed to allocate memory  3A\n");
		return 1;
	}
	// new_size = 0;
	// new_ptr = ft_realloc(ptr, old_size, new_size);
	// if (new_ptr == NULL)
	// {
	// 	ft_printf("Failed to reallocate memory  2R\n");
	// 	return 1;
	// }
	// ft_printf("New pointer: %p\n", new_ptr);

	ptr = malloc(old_size);
	if (ptr == NULL)
	{
		ft_printf("Failed to allocate memory  4A\n");
		return 1;
	}
	new_size = 15;
	new_ptr = ft_realloc(ptr, old_size, new_size);
	if (new_ptr == NULL)
	{
		ft_printf("Failed to reallocate memory  3R\n");
		return 1;
	}
	ft_printf("New pointer: %p\n", new_ptr);

	ptr = malloc(old_size);
	if (ptr == NULL)
	{
		ft_printf("Failed to allocate memory  5A\n");
		return 1;
	}
	new_ptr = ft_realloc(ptr, old_size, 0);
	if (new_ptr == NULL)
	{
		ft_printf("Failed to reallocate memory  4R\n");
		return 1;
	}
	ft_printf("New pointer: %p\n", new_ptr);

	return 0;
}