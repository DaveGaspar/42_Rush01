#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}

void my_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int my_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int my_atoi(const char *str)
{
	int i;
	int sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);	
}

void my_putnbr(int nb)
{
	unsigned int nbr;

	if (nb < 0)
	{
		my_putchar('-');
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr / 10 != 0)
		my_putnbr(nbr / 10);
	my_putchar(nbr % 10 + 48);
}