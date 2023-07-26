#include <stdbool.h> // for bool
#include <unistd.h> // for write
#include <stdlib.h> // for malloc
#include <stdio.h> // for printf

char	*ft_substr(char *s, int start, int end)
{
	char    *str;
	int     i;

	if (!s)
		return (NULL);
	str = malloc((end - start + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < (end - start))
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char *make_match(char *opening)
{
	char *match = malloc((1024) * sizeof(char));
	int i = 0;

	match[i] = '<';
	i++;
	match[i] = '/';
	i++;
	while (opening[i] != '>')
	{
		match[i] = opening[i + 1];
		i++;
	}
	match[i] = opening[i];
	match[i + 1] = '\0';
	printf("opening in makematch = %s\n", opening);
	printf("match in makematch = %s\n\n", match);
	return (match);
}

bool	is_same(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (false);
		i++;
	}
	return (true);
}

bool matches(char *opening, char *closing)
{
	char *match = NULL;

	printf("opening in matches = %s\n", opening);
	printf("closing in matches = %s\n", closing);
	match = make_match(opening);
	if (is_same(closing, match) == true)
		return (true);
	return (false);
}

bool	check_parenthesis(char *str)
{
	int	i = 0;
    int start = 0;
    int end = 0;
    char **opening_blocks = malloc((1024) * sizeof(char *));
	int	stack_size = 0;

	while (str[i])
	{
		if (str[i] == '<' && str[i + 1] != '/') // if opening bracket
		{
            start = i;
            i++;
            while (str[i] != '>')
            {
                i++;
            }
            end = i + 1; // + 1?
            stack_size++; // increment stack size
			opening_blocks[stack_size] = ft_substr(str, start, end); // push opening bracket to stack
		}
		if (str[i] == '<'  && str[i + 1] == '/') // if closing bracket
		{
			start = i;
            i++;
            while (str[i] != '>')
            {
                i++;
            }
            end = i + 1; // + 1?
			if (matches(opening_blocks[stack_size], ft_substr(str, start, end)) == false) // check if closing bracket matches opening bracket
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