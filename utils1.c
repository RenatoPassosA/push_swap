/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassos- <rpassos-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:25:36 by rpassos-          #+#    #+#             */
/*   Updated: 2025/01/08 13:25:37 by rpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (str[counter] != '\0')
		counter++;
	return (counter);
}

long	ft_atol(char *s)
{
	int			minus_sign;
	long int	result;

	minus_sign = 0;
	result = 0;
	while (*s)
	{
		while (*s == 32 || (*s >= 9 && *s <= 13))
			s++;
		if (*s == '+' || *s == '-')
		{
			if (*s == '-')
				minus_sign = 1;
			s++;
		}
		while (*s >= '0' && *s <= '9')
		{
			result = result * 10 + (*s - '0');
			s++;
		}
		if (minus_sign)
			return (result * -1);
		return (result);
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		size;
	int		index;
	int		j;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	index = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)ft_calloc(size, sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (s1[index])
	{
		str[index] = s1[index];
		index++;
	}
	str[index] = ' ';
	j = 0;
	index++;
	while (s2[j])
		str[index++] = s2[j++];
	str[index] = '\0';
	return (str);
}

static void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	a;
	unsigned char	*ptr;
	size_t			index;

	index = 0;
	a = (unsigned char)c;
	ptr = (unsigned char *)s;
	while (index < n)
	{
		ptr[index] = a;
		index++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if ((nmemb * size) % nmemb)
		return (NULL);
	arr = (void *)malloc(nmemb * size);
	if (arr == NULL)
		return (NULL);
	ft_memset(arr, 0, nmemb * size);
	return (arr);
}
