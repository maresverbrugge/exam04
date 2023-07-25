#include <stdbool.h> // for bool
#include <unistd.h> // for write
#include <stdio.h> // for printf
#include <stdlib.h> // for malloc

// bool matches(char *first, char *second)
// {
// 	if ((first == '<' && second == '>')
// 		|| (first == '{' && second == '}'))
// 		return (true);
// 	return (false);
// }   
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

bool	is_closing(const char *s1, const char *s2)
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

void print_2d_array(char **array, char *str)
{
    int i = 0;
    printf("%s !!!\n", str);
    while (array[i] != NULL)
    {
        printf("[%i] = %s\n", i, array[i]);
        i++;
    }
    printf("\n\n");
}
// bool    is_right_closing(char **blocks, char **matching_blocks)
// {
//     int block_index = 0;
    
//     if (ft_is_pair(blocks[block_index], matching_blocks[block_index]) == false)
//     {
//         printf("its opening\n");
//     }
//     else
//     {
//         printf("its closing\n");
//     }
//     printf("\n");
// }

char **check_closing(char **blocks, char **matching_blocks)
{
    char **closing_blocks = malloc((1024) * sizeof(char *));
    int index = 0;
    int closing_index = 0;
    while(blocks[index])
    {
        // printf("blocks[index] = %s\n", blocks[index]);
        // printf("matching_blocks[index] = %s\n", matching_blocks[index]);
        if (is_closing(blocks[index], matching_blocks[index]) == true)
        {
            // printf("its closing\n");
            closing_blocks[closing_index] = blocks[index];
            closing_index++;
        }
        // printf("\n");
        index++;
    }
    return (closing_blocks);
}

int check_opening(char **blocks, char **matching_blocks, char **opening_blocks)
{
    int index = 0;
    int opening_index = 0;
    while(blocks[index])
    {
        // printf("blocks[index] = %s\n", blocks[index]);
        // printf("matching_blocks[index] = %s\n", matching_blocks[index]);
        if (is_closing(blocks[index], matching_blocks[index]) == false)
        {
            // printf("its opening\n");
            opening_blocks[opening_index] = blocks[index];
            opening_index++;
        }
        // printf("\n");
        index++;
    }
    return (opening_index);
}

bool check_stacks(int size, char **blocks, char **matching_blocks, char **opening_blocks, char **closing_blocks)
{
    int i = 0;
    
    while (i < size)
    {
        printf("HIER!!!\n");
        printf("matching_blocks[i] = %s\n", matching_blocks[i]);
        printf("closing_blocks[i] = %s\n", closing_blocks[i]);
        if (is_same(matching_blocks[i], closing_blocks[i]) == false)
            return (false);
        i++;
    }
    return (true);
}

bool	check_parenthesis(char *str)
{
	int	i = 0;
    int start = 0;
    int end = 0;
    int block_index = 0;
    char **blocks = malloc((1024) * sizeof(char *));
    char *matching_block = malloc(1024 * sizeof (char));
    char **opening_blocks = malloc((1024) * sizeof(char *));
    char **matching_blocks = malloc((1024) * sizeof(char *));
    char **closing_blocks; // = malloc((1024) * sizeof(char *));

	while (str[i])
	{
        if (str[i] == '<') // if opening bracket // && str[i + 1] != '/'
		{
            int j = 0;
            matching_block[j] = str[i];
            start = i;
            j++;
            i++;
            if (str[i] != '/')
            {
                matching_block[j] = '/';
                j++;
            }
            while (str[i] != '>')
            {
                matching_block[j] = str[i];
                j++;
                i++;
            }
            matching_block[j] = str[i];
            matching_block[j + 1] = '\0';
            end = i + 1;
            blocks[block_index] = ft_substr(str, start, end);
            matching_blocks[block_index] = ft_substr(matching_block, 0, j + 1);
            printf("blocks[%d] = %s\n", block_index, blocks[block_index]);
            printf("matching_block[%d] = %s\n\n", block_index, matching_blocks[block_index]);
            block_index++;
        }
		i++;
	}
    printf("\n");
    print_2d_array(blocks, "blocks");
    print_2d_array(matching_blocks, "matching_blocks");
    
    int size = check_opening(blocks, matching_blocks, opening_blocks);
    printf("amount_of_opening_blocks = %d\n", size);
    print_2d_array(opening_blocks, "opening_blocks");

    closing_blocks = check_closing(blocks, matching_blocks);
    print_2d_array(closing_blocks, "closing_blocks");

    if (check_stacks(size, blocks, matching_blocks, opening_blocks, closing_blocks) == true) // validate stacks
	    return (true); //  -> only matching pairs found
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