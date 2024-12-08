#include <stdlib.h>

void my_putstr(char *str);
int my_atoi(char *str);
int my_strlen(char *str);
int solve(int matrix[4][4], int input[16], int pos);
void display_solution(int matrix[4][4]);

int *get_numbers(char *str)
{
	int i;
	int j;
	int *arr;

	if (!(arr = malloc(sizeof(int) * 16)))
		return (0);
	i = -1;
	j = 0;
	while (str[++i] != '\0')
		if (str[i] >= '0' && str[i] <= '9')
		{
			arr[j] = my_atoi(str + i);
			if (arr[j] < 1 || arr[j] > 4)
				return (0);
			j++;
		}	
	return (arr);
}

int main(int argc, char **argv)
{
	if (argc != 2 || my_strlen(argv[1]) != 31)
	{
		my_putstr("Error\n");
		return (0);
	}

	int matrix[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	};
	int *input;

	input = get_numbers(argv[1]);
	if (input == 0)
	{
		my_putstr("Error\n");
		return (0);
	}
	if (solve(matrix, input, 0) == 1)
		display_solution(matrix);
	else
		my_putstr("Error\n");
	return (0);
}
