#include "philo.h"

int	parsing(int argc, char **argv, t_data *data)
{
	if (input_validation(argc, **argv, data) == 1)
		return (1);
	if (input_assignment(argc, **argv, data) == 1)
		return (1);
	return (0);
}

int	input_validation(int argc, char **argv, t_data *data)
{
	long	val;

	if (argc != 5 && argc != 6)
		return (err_invalid);
	val = ft_strtol(argv[1]);
	if (val == -1 || val > 200)
		return (err_msg("\nInvalid philo count."));
	val = ft_strtol(argv[2]);
	if (val == -1)
		return (err_msg("\nInvalid time to die."));
	val = ft_strtol(argv[3]);
	if (val == -1)
		return (err_msg("\nInvalid time to eat."));
	val = ft_strtol(argv[4]);
	if (val == -1)
		return (err_msg("\nInvalid time to sleep."));
	if (argc == 6)
	{
		val = ft_strtol(argv[5]);
		if (val == -1)
			return (err_msg("\nInvalid meal count."));
	}
	return (0);
}

int	input_assignment(int argc, char **argv, t_data *data)
{
	long	val;

	val = ft_strtol(argv[1]);
	data->philos_num = (int)val;
	val = ft_strtol(argv[2]);
	data->time_to_die = val;
	val = ft_strtol(argv[3]);
	data->time_to_eat = val;
	val = ft_strtol(argv[4]);
	data->time_to_sleep = val;
	data->meals_to_eat = -1;
	if (argc == 6)
	{
		val = ft_strtol(argv[5]);
		data->meals_to_eat = (int)val;
	}
	return (0);
}

long	ft_strtol(const char *str)
{
	long	res;
	int		i;

	res = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+')
		i++;
	if (!str[i])
		return (-1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		if (res > (LONG_MAX - (str[i] - '0')) / 10)
			return (-1);
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if (res < 1)
		return (-1);
	return (res);
}
