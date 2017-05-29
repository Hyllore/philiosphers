/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 11:04:30 by droly             #+#    #+#             */
/*   Updated: 2017/05/29 17:35:30 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHIL_H
# define PHIL_H

# define MAX_LIFE 15
# define EAT_T 2
# define REST_T 2
# define THINK_T 3
# define TIMEOUT 100
# define SLEEP 0
# define EAT 1
# define THINK 2
# define WAIT 3

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
