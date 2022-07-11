#include<iostream>

int check();
int** createMatr(int n, bool input = true);
int numberOfMax(int** matr, int n);
int** matrixMultiplication(int** matr1, int** matr2, int n);
void printResult(int** matr1, int** matr2, int** result, int n);

int main()
{
	setlocale(0, "rus");

	int n = 0;
	std::cout << "Ввведите размерность квадратной матрицы\n";
	while (!n) {
		n = check();
	}

	int** matr1 = createMatr(n), ** matr2 = createMatr(n), ** matr3 = createMatr(n), ** result = createMatr(n, false);


	if (numberOfMax(matr1, n) > 1 && numberOfMax(matr2, n) > 1)
	{
		result = matrixMultiplication(matr1, matr2, n);
		printResult(matr1, matr2, result, n);
	}
	else
		if (numberOfMax(matr1, n) > 1 && numberOfMax(matr3, n) > 1)
		{
			result = matrixMultiplication(matr1, matr3, n);
			printResult(matr1, matr3, result, n);
		}
		else
			if (numberOfMax(matr2, n) > 1 && numberOfMax(matr3, n) > 1)
			{
				result = matrixMultiplication(matr2, matr3, n);
				printResult(matr2, matr3, result, n);
			}
			else
				std::cout << "Нет таких матриц\n";

	return 0;
}

int check()
{
	int x;
	std::cin >> x;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Нужно ввести число\n";
		std::cin >> x;
	}
	return x;
}

int** createMatr(int n, bool input)
{
	int** matr = new int* [n];
	for (int i = 0; i < n; i++)
		*(matr + i) = new int[n];
	if (input)
	{
		std::cout << "Заполните матрицу\n";
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				std::cin >> *(*(matr + i) + j);
	}

	return matr;
}

int numberOfMax(int** matr, int n)
{
	int max = **matr;
	int countMax = 0;

	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			if (*(*(matr + i) + j) == max)
				countMax++;

			if (*(*(matr + i) + j) > max)
			{
				max = *(*(matr + i) + j);
				countMax = 1;
			}
		}

	return countMax;
}

int** matrixMultiplication(int** matr1, int** matr2, int n)
{
	int** matr3 = createMatr(n, false);

	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			*(*(matr3 + i) + j) = 0;
			for (int k = 0; k < n; k++)
				(*(*(matr3 + i) + j)) += (*(*(matr1 + i) + k)) * (*(*(matr2 + k) + j));

		}

	return matr3;
}

void printResult(int** matr1, int** matr2, int** result, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < n; j++)
		{
			std::cout << *(*(matr1 + i) + j) << " ";
			if (j == n - 1)
			{
				if (i == 0)
					std::cout << " * ";
				else
					std::cout << "   ";

				for (int k = 0; k < n; k++)
					std::cout << *(*(matr2 + i) + k) << " ";

				if (i == 0)
					std::cout << " = ";
				else
					std::cout << "   ";

				for (int k = 0; k < n; k++)
					std::cout << *(*(result + i) + k) << " ";

			}

		}
	}
}