 #include <stdio.h>
 #include <stdlib.h>
 int ft_isdigit(char c)
{
	return(c >= '0' && c <= '9');
}

int isop(char c)
{
	return (c == '-' || c == '+'  || c == '%' || c =='/'  || c == '*');
}

int doop(int num, char operand, int num1)
{
	if (operand == '*')
		return(num * num1);
	else if (operand == '/')
		return(num / num1);
	else if (operand == '%')
		return(num % num1);
	else if (operand == '+')
		return(num + num1);
	else if (operand == '-')
		return(num - num1);
	return (0);
}

int main(int ac, char **argv)
{
	char		*str;
	int			a[10];
	int			i = -1;


	if (ac != 2)
	{
		printf("Error\n");
		return (0);
	}
	str = argv[1];
	while (*str)
	{
		if (ft_isdigit(*str) || (*str == '-' && ft_isdigit(*(str+1))))
		{
			a[++i] = atoi(&(*str));
			while (ft_isdigit(*str) || *str == '-')
				str++;
		}
		if (isop(*str))
		{
			if ((*str == '/' || *str == '%') && a[i] == 0)
			{
				printf("Error\n");
				return (0);
			}
			a[i-1] = doop(a[i - 1], *str, a[i]);
			i--;
		}
		str++;
	}
	if (i != 0)
		printf("Error\n");
	else
		printf("%d\n", a[i]);
	return (0);
}
