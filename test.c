/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:00:37 by droly             #+#    #+#             */
/*   Updated: 2017/05/31 16:41:17 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;
int i = 0;

void	ft_putnbr(int n)
{
	long	num;

	num = (long)n;
	if (num < 0)
	{
		num = num * -1;
		ft_putchar('-');
	}
	if (num >= 10)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
		ft_putchar(num + '0');
}

void *fct(void *str) {

	while (i != 25)
	{
		pthread_mutex_trylock(&g_mutex);
//		puts("trylock");
		i++;
//		*((int*)str) += 1;
		puts((char*)str);
//		printf("%d\n", i);
		ft_putnbr(i);
		write(1, "\n", 1);
//		printf("%d\n", *((int*)str));
//		sleep(1);
		pthread_mutex_unlock(&g_mutex);
	}
	return NULL;
}

void *fct2() {
	int time;

	time = TIMEOUT;
	while (pthread_mutex_trylock(&g_mutex) != 0)
		puts("trylock");

	printf("wlo\n");
	sleep(1);
	pthread_mutex_unlock(&g_mutex);

	return NULL;
}


int	main(void)
{
   pthread_t th1;
   pthread_t th2;

   pthread_create(&th1, NULL, fct, "c");
//   pthread_detach(th1);
   pthread_create(&th2, NULL, fct, "t");
   pthread_join(th1, NULL);
   pthread_join(th2, NULL);
  return (0);
}

