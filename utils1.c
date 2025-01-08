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

static char	*concat(char *final, char *str, int index)
{
	int	strindex;

	strindex = 0;
	while (str[strindex] != '\0')
	{
		final[index] = str[strindex];
		index++;
		strindex++;
	}
	final[index] = ' ';
	return (final);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		size;
	int		index;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	index = 0;
	size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = (char *)malloc(size * sizeof(char) + 1);
	if (!str)
		return (NULL);
	str = concat(str, (char *)s1, index);
	index = ft_strlen(str);
	str = concat(str, (char *)s2, index);
	index = index + ft_strlen((char *)s2);
	str[index++] = '\0';
	return (str);
}
