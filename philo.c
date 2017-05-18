/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 11:45:25 by droly             #+#    #+#             */
/*   Updated: 2017/05/18 15:31:36 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>


pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;

/*void *fct(void * arg) {

	while (pthread_mutex_trylock(&g_mutex) != 0)
		puts("trylock");

//	pthread_mutex_lock(&g_mutex);

	for (int i = 0; i < 10; i++)
		puts(arg);
	pthread_mutex_unlock(&g_mutex);

	return NULL;
}

int	main(void)
{
	pthread_t th1;
	pthread_t th2;

	pthread_create(&th1, NULL, fct, "coucou");
	pthread_detach(th1);
	pthread_create(&th2, NULL, fct, "toto");
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	return (0);
}

t_list	*fill_list(t_list *list)
{
	static int i = 1;
	static int b = 0;

	list->phil = i;
	list->health = MAX_LIFE;
	if ((list->right = malloc(sizeof(t_bag))) == NULL)
		return (NULL);
	if ((list->left = malloc(sizeof(t_bag))) == NULL)
		return (NULL);
	if (b == 0)
		list->left->id = 7;
	else
		list->left->id = b;
	b++;
	list->right->id = b;
	list->left->isfree = 1;
	list->right->isfree = 1;
	list->hleft = 0;
	list->hright = 0;
	list->state = SLEEP;
	i++;
	return (list);
}

void	start_algo(t_list *list)
{
//	pthread_t th1;
//	pthread_t th2;
	int			time;

	list->state = 0;
	time = TIMEOUT;
	printf("time %d\n", time);
	while (time > 0)
	{
		pthread_create(&th1, NULL, fct);
//		pthread_detach(th1);
		sleep(1);
		time--;
		printf("time %d\n", time);
	}
}

int main (void)
{
	t_list	*list;
	t_list	*tmp;
	int		i;

	i = 0;
	if ((list = malloc(sizeof(t_list))) == NULL)
		return (0);
	tmp = list;
	list = fill_list(list);
	while (i < 7)
	{
		if ((list->next = malloc(sizeof(t_list))) == NULL)
			return (0);
		list = list->next;
		list = fill_list(list);
		i++;
	}
	list = tmp;
	i = 0;
	while (i++ < 7)
	{
		printf("_________\n");
		printf("phil n : %d\n", list->phil);
		printf("health : %lu\n", list->health);
		printf("hright : %d\n", list->hright);
		printf("hleft : %d\n", list->hleft);
		printf("left id : %d\n", list->left->id);
		printf("left isfree : %d\n", list->left->isfree);
		printf("right id : %d\n", list->right->id);
		printf("right isfree : %d\n", list->right->isfree);
		printf("right state : %d\n", list->state);
		printf("_________\n");
		list = list->next;
	}
	i = 0;
	start_algo(list);
	return (0);
}
