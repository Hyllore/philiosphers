/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 11:04:30 by droly             #+#    #+#             */
/*   Updated: 2017/05/23 15:14:07 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHIL_H
# define PHIL_H

# define MAX_LIFE 15
# define EAT_T 3
# define REST_T 4
# define THINK_T 2
# define TIMEOUT 20
# define SLEEP 2
# define EAT 2
# define THINK 3

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

typedef struct		s_bag
{
	int				id;
	int				isfree;
}					t_bag;

typedef struct		s_list
{
	int				phil;
	size_t			health;
	t_bag			*right;
	t_bag			*left;
	int				hright;
	int				hleft;
	int				state;
	int				timeleft;
	struct s_list	*next;
}					t_list;

void	ft_putchar(char c);
void	ft_putstr(char *str);

#endif
