#include "push_swap.h"

int     ft_atoi(const char *str)
{
        int     a;
        int     simb;
        int     result;

        a = 0;
        result = 0;
        simb = 1;
        while (str[a] == 32 || (str[a] <= 13 && str[a] >= 9))
                a++;
        if (str[a] == '-')
        {
                simb *= -1;
                a++;
        }
        else if (str[a] == '+')
                a++;
        while ((str[a] >= '0' && str[a] <= '9'))
        {
                result = result * 10 + (str[a] - '0');
                a++;
        }
        return (result * simb);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	int	a;
	int	count;

	a = 0;
	count = 0;
	if (!str)
	{
		count += ft_putstr("(null)");
		return (count);
	}
	while (str[a])
	{
		count += ft_putchar(str[a]);
		a++;
	}
	return (count);
}

int	ft_conv(char *str, int i, va_list args)
{
	int	count;

	count = 0;
	if (str[i] == 's')
		count += ft_putstr(va_arg(args, const char *));
	return (count);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	while (i >= 0)
	{
		if (str[i] == (char )c)
			return ((char *)&str[i]);
		i--;
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start (args, str);
	if (str == NULL || str[0] == '\0')
	{
		va_end (args);
		return (0);
	}
	while (str[i] != '\0')
	{
		if (str[i] == '%' && ft_strchr("csdiupxX%", str[i + 1]) != NULL)
		{
			count += ft_conv((char *)str, i + 1, args);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end (args);
	return (count);
}