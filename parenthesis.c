#include <stdbool.h> // for bool
#include <unistd.h> // for write

bool matches(char first, char second)
{
	if ((first == '(' && second == ')')
		|| (first == '[' && second == ']')
		|| (first == '{' && second == '}'))
		return (true);
	return (false);
}

bool	check_parenthesis(char *str)
{
	int	i;
	int	stack_size;
	int	stack[1024];

	i = 0;
	stack_size = 0;
	while (str[i])
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') // if opening bracket
		{
            stack_size++; // increment stack size
			stack[stack_size] = str[i]; // push opening bracket to stack
		}
		if (str[i] == ')' || str[i] == ']' || str[i] == '}') // if closing bracket
		{
			if (matches(stack[stack_size], str[i]) == false) // check if closing bracket matches opening bracket
				return (false);
			stack_size--; // if so: fake pop opening bracket from stack
		}
		i++;
	}
    if (stack_size == 0) // validate stack is empty -> only matching pairs found
	    return (true);
    return (false);
}

int main(int argc, char **argv)
{
	
	int i;
	
	i = 1;
	if (argc == 1)
		return (write(1, "\n", 1));
	while (i < argc)
	{
		if (check_parenthesis(argv[i]))
			write(1, "OK\n", 3);
		else
			write(1, "Error\n", 6);
		i++;
	}
	return (0);
}
