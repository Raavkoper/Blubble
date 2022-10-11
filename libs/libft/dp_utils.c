/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dp_utils.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/21 22:16:29 by rkoper        #+#    #+#                 */
/*   Updated: 2022/10/11 14:08:48 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	dp_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char	**dp_dup(char **arr, int size)
{
	int		i;
	char	**new_arr;

	i = 0;
	new_arr = ft_calloc(size, sizeof(char *));
	if (!new_arr)
		return (NULL);
	while (arr[i])
	{
		new_arr[i] = ft_strdup(arr[i]);
		i++;
	}
	return (new_arr);
}

void	free_dp(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
