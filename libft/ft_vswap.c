#include "libft.h"

void ft_vswap(void * a, void * b, size_t width)
{
  void *temp;
    temp = malloc(width);
    ft_memcpy(temp, b, width);
    ft_memcpy(b, a, width);
    ft_memcpy(a, temp, width);
    free(temp);
}
