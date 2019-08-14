#include <unistd.h>

int ismatch(char b, char a)
{
	if (a =='(' && b == ')')
		return (1);
	else if (a == '{' && b =='}')
		return (1);
	else if (a == '[' && b == ']')
		return (1);
	return (0);
}

int brackets(char *str)
{
	int stack[4096];
	int top = 0;

	while (*str)
	{
		if (*str == '(' || *str == '[' || *str == '{')
			stack[++top] = *str;
		else if (*str == ')' || *str == ']' || *str == '}')
			if (!ismatch(*str, stack[top--]))
				return(0);
		str++;
	}
	return(!top);
}
int main(int ac, char **av)
{
	int i = 0;

	if (ac == 1)
		write(1, "\n", 1);
	else
	{
		while(av[++i])
			brackets(av[i]) ? write(1, "OK\n", 3) : write(1, "Error\n", 6);
	}
	return(0);
}
