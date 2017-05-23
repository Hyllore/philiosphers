/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 11:45:25 by droly             #+#    #+#             */
/*   Updated: 2017/05/23 17:01:18 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>


pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;
void *fct() {
	while (pthread_mutex_trylock(&g_mutex) != 0)
		puts("trylock");


	pthread_mutex_unlock(&g_mutex);

	return NULL;
}

void *fct2() {
	int time;

	time = TIMEOUT;
	while (pthread_mutex_trylock(&g_mutex) != 0)
		puts("trylock");

	printf("wlo\n");

	pthread_mutex_unlock(&g_mutex);

	return NULL;
}

/*
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
   */
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
	list->timeleft = 0;
	list->state = 0;
	i++;
	return (list);
}

void	quit()
{
	printf("finished one died");
	exit(0);
	//liberer ressources'
}

t_list	*loose_life(t_list *list)
{
	int i;
	t_list *tmp;

	tmp = list;
	i = 0;
	while (i < 7)
	{
		list->health--;
		if (list->health == 0)
			quit();
		list = list->next;
		i++;
	}
	list = tmp;
	return (list);
}



void	display_state(t_list *list)
{
	t_list *tmp;
	int i;

	i = 0;
	tmp = list;
	while (i < 7)
	{
		printf("Le philosophe %d ", list->phil);
		if (list->state == 0)
			printf("se repose, ");
		if (list->state == 1)
			printf("mange, ");
		if (list->state == 2)
			printf("pense, ");
		if (list->state == 3)
			printf("attend, ");
		printf("vie restante : %lu\n", list->health);
		i++;
		list = list->next;
	}
	list = tmp;
}


t_list	*think(t_list *list)
{
	if (list->right->isfree == 1)
	{
		list->right->isfree = 0;
		list->hright = 1;
	}
	if (list->left->isfree == 1)
	{
		list->left->isfree = 0;
		list->hleft = 1;
	}
	list->state = 2;
	list->timeleft = THINK;
	return (list);
}

t_list	*eat(t_list *list)
{
	list->right->isfree = 0;
	list->left->isfree = 0;
	list->hleft = 1;
	list->hright = 1;
	list->state = 1;
	list->timeleft = EAT;
	list->health = MAX_LIFE;
	return (list);
}


t_list	*sleepi(t_list *list)
{
	list->state = 0;
	list->right->isfree = 1;
	list->left->isfree = 1;
	list->hleft = 0;
	list->hright = 0;
	list->timeleft = SLEEP;

	return (list);
}


void	start_algo(t_list *list)
{
	pthread_t th[7];
	//	pthread_t th2;
	//	time_t t = time(0);
	//	time_t t2 = t;
	int tmp = 0;

	//	list->state = 0;
	pthread_create(th, NULL, fct, NULL);
	pthread_detach(th[0]);
	//	pthread_create(&th2, NULL, fct2, NULL);
	//	pthread_detach(th2);
	//	while ((int)(t2 - t) < TIMEOUT)
	//	{
	//		t2 = time(0);
	//		if (tmp != (int)(t2 - t))
	//		{
	//			tmp = (int)(t2 - t);
	//			printf("time : %d\n", (int)(t2 - t));
	//		}
	//		printf("t - t2 : %d > %d ?\n", (int)(t2 - t), TIMEOUT);
	//		pthread_join(th1, NULL);
	//		pthread_join(th2, NULL);
	//		printf("hey\n");
	//	}
	while (tmp < TIMEOUT)
	{
		sleep(1);
		tmp++;
		printf("time : %d\n", tmp);
		list = loose_life(list);
		if (list->timeleft != 0)
			list->timeleft--;
		if ((list->state == 0 || list->state == 1) && list->timeleft == 0)
		{
			if (list->right->isfree == 1 && list->left->isfree == 1)
				list = eat(list);
			else if (list->right->isfree == 1 || list->left->isfree == 1)
				list = think(list);
			else
				list->state = 3;
		}
		if ((list->state == 1 || list->state == 3) && list->timeleft == 0)
			list = sleepi(list);
		display_state(list);
	}
	printf("Now, it is time... To DAAAAAAAANCE ! ! !");
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
		list = tmp;
	i = 0;
	start_algo(list);
	return (0);
}
