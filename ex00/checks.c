int check_double(int matrix[4][4], int pos, int num)
{
	int i;

	i = -1;
	while (++i < pos / 4)
		if (matrix[i][pos % 4] == num)
			return (1);
	i = -1;
	while (++i < pos % 4)
		if (matrix[pos / 4][i] == num)
			return (1);
	return (0);
}

int col_up(int matrix[4][4], int pos, int entry[16])
{
	int i;
	int max;
	int count;

	i = 0;
	max = 0;
	count = 0;
	if (pos / 4 == 3)
	{
		while (i < 4)
		{
			if (matrix[i][pos % 4] > max)
			{
				max = matrix[i][pos % 4];
				count++;
			}
			i++;
		}
		if (entry[pos % 4] != count)
			return (1);
	}
	return (0);
}

int col_down(int matrix[4][4], int pos, int entry[16])
{
	int i;
	int max;
	int count;

	i = 3;
	max = 0;
	count = 0;
	if (pos / 4 == 3)
	{
		while (i >= 0)
		{
			if (matrix[i][pos % 4] > max)
			{
				max = matrix[i][pos % 4];
				count++;
			}
			i--;
		}
		if (entry[4 + pos % 4] != count)
			return (1);
	}
	return (0);
}

int row_left(int matrix[4][4], int pos, int entry[16])
{
	int i;
	int max;
	int count;

	i = 0;
	max = 0;
	count = 0;
	if (pos % 4 == 3)
	{
		while (i < 4)
		{
			if (matrix[pos / 4][i] > max)
			{
				max = matrix[pos / 4][i];
				count++;
			}
			i++;
		}
		if (entry[8 + pos / 4] != count)
			return (1);
	}
	return (0);
}

int row_right(int matrix[4][4], int pos, int entry[16])
{
	int i;
	int max_size;
	int count;

	i = 3;
	max_size = 0;
	count = 0;
	if (pos % 4 == 3)
	{
		while (i >= 0)
		{
			if (matrix[pos / 4][i] > max_size)
			{
				max_size = matrix[pos / 4][i];
				count++;
			}
			i--;
		}
		if (entry[12 + pos / 4] != count)
			return (1);
	}
	return (0);
}

int check(int matrix[4][4], int pos, int entry[16])
{
	if (row_left(matrix, pos, entry) == 1)
		return (1);
	if (row_right(matrix, pos, entry) == 1)
		return (1);
	if (col_down(matrix, pos, entry) == 1)
		return (1);
	if (col_up(matrix, pos, entry) == 1)
		return (1);
	return (0);
}