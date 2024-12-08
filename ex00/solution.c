void my_putnbr(int nb);
void my_putchar(char c);
int check_double(int matrix[4][4], int pos, int num);
int check(int matrix[4][4], int pos, int input[16]);

int solve(int matrix[4][4], int input[16], int pos)
{
	int size;

	if (pos == 16)
		return (1);
	size = 0;
	while (++size <= 4)
	{
		//checking if the number I want to place is correct
		if (check_double(matrix, pos, size) == 0)
		{
			matrix[pos / 4][pos % 4] = size;
			//checking if the matrix is correct with the new number
			if (check(matrix, pos, input) == 0)
			{
				//checking for next possibility
				if (solve(matrix, input, pos + 1) == 1)
					return (1);
			}
			else
				matrix[pos / 4][pos % 4] = 0;
		}
	}
	//did not find any solutions
	return (0);
}

void display_solution(int matrix[4][4])
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			my_putnbr(matrix[i][j]);
			my_putchar(' ');
		}
		my_putchar('\n');
	}
}