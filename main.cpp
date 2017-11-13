#include <iostream> 
#include <iomanip>
#include <sstream>
#include <string>

int ** ul(int rows, int col)
{
	int m = col;
	int n = rows;
	int** matr = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matr[i] = new int[m];
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			matr[i][j] = 0;

	int i = 0, j = 0, k = 0, p = 1;

	while (i < n*m)
	{
		k++;

		for (j = k - 1; j <= m - k; j++)
		{
			if (i >= m*n) break;
			matr[k - 1][j] = p;
			p++;
			i++;

		}

		for (j = k; j <= n - k; j++)
		{
			if (i >= m*n) break;
			matr[j][m - k] = p++;
			i++;
		}

		for (j = m - k - 1; j >= k - 1; j--)
		{
			if (i >= m*n) break;
			matr[n - k][j] = p++;
			i++;
		}

		for (j = n - k - 1; j >= k; j--)
		{
			if (i >= m*n) break;
			matr[j][k - 1] = p++;
			i++;
		}
	}
	return matr;
}
void show(int** matr, int m, int n)
{
	for (int l = 0; l < m; l++)
	{
		for (int k = 0; k < n; k++)
		{
			std::cout << std::setw(10) << matr[l][k];
		};
		std::cout << std::endl;
	}

}

bool read_size(unsigned int & result_rows, unsigned int & result_columns)
{
	std::string line;
	std::getline(std::cin, line);
	std::istringstream stream(line);

	unsigned int rows = 0;
	unsigned int collumns = 0;
	char comma;

	if (stream >> rows &&
		stream >> comma && comma == ',' &&
		stream >> collumns &&
		stream.eof()) {

		result_rows = rows;
		result_columns = collumns;

		return true;
	}

	return false;
}

void destroy(int ** matr, unsigned int rows)
{
	for (unsigned int i = 0; i < rows; i++)
	{
		delete[] matr[i];
	}
	delete[] matr;
}

int main()
{
	unsigned int rows = 0;
	unsigned int collumns = 0;
	if (read_size(rows, collumns)) {
		int** matr = ul(rows, collumns);
		show(matr, rows, collumns);
		destroy(matr, rows);
	}
	else {
		std::cerr << "An error has occyred while reading input data\n";
	}
	return 0;
}

