#include <stdlib.h>

const char g_base[] = "0123456789ABCDEF";

int		ft_strlen(char *src)
{
	int	i;
	
	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrev(char *src)
{
	int		length;
	int		i;
	char	temp;

	length = ft_strlen(src);
	i = -1;
	while (++i < length / 2)
	{
		temp = src[i];
		src[i] = src[length - i - 1];
		src[length - i - 1] = temp;
	}
	return (src);
}

char	*ft_itoa_recursive(int value, int base, int count, char *result)
{
	int sign;

	sign = 1;
	if (value < 0 && base == 10)
		sign = -1;
	if ((value < base && base != 10) || (base == 10 && value > -10 && value < 10))
	{
		if (base == 10 && value < 0)
			count++;
		result = malloc(sizeof(char) * (count + 2));
		result[count + 1] = '\0';
		if (sign == -1)
		{
			result[count] = '-';
			count--;
		}
	}
	else
		result = ft_itoa_recursive(value / base, base, count + 1, result);
	result[count] = g_base[sign * (value % base)];
	return (result);
}

char	*ft_itoa_base(int value, int base)
{
	char	*result;

	if (base < 2 || base > 16 || (value < 0 && base != 10))
		return (NULL);
	result = NULL;
	result = ft_itoa_recursive(value, base, 0, result);
	return (ft_strrev(result));
}
#include <stdio.h>
int		main(int argc, char *argv[])
{
	if (argc == 3)
		printf("%s\n", ft_itoa_base(atoi(argv[1]), atoi(argv[2])));
	return (0);
}
