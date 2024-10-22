/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:58:35 by ede-cola          #+#    #+#             */
/*   Updated: 2024/08/28 14:09:18 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_pwd(int fd, t_env **env)
{
	char	*pwd;
	t_env	*tmp;
	int		i;

	tmp = *env;
	i = 0;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, "PWD"))
		{
			ft_putendl_fd(tmp->value, fd);
			i++;
			break ;
		}
		tmp = tmp->next;
	}
	if (!i)
	{
		pwd = getcwd(NULL, 0);
		ft_putendl_fd(pwd, fd);
		free(pwd);
	}
	return (0);
}
