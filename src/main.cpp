#include <iostream>
#include <cassert>

#include "matrix.h"

int main() {
	 // бесконечная матрица int заполнена значениями -1 пример ДЗ
	Matrix<int, -1> matrix;
	assert(matrix.size() == 0); // все ячейки свободны
	auto a = matrix[0][0];
	assert(a == -1);
	assert(matrix.size() == 0);
	matrix[100][100] = 314;
	assert(matrix[100][100] == 314);
	assert(matrix.size() == 1);
	// выведется одна строка
	// 100100314
	for (auto c : matrix)
	{
		int x;
		int y;
		int v;
		std::tie(x, y, v) = c;
		std::cout << x << y << v << std::endl;;
	}
	
	int n = 10;
	Matrix<int, 0> matrix_2;
	for (int i = 0; i < n; ++i) {
		matrix_2[i][i] = i;
	}
	for (int i = 0; i < n; ++i) {
		matrix_2[i][(n - 1) - i] = (n - 1) - i;
	}
	for (int i = 1; i < n - 1; ++i) {
		for (int j = 1; j < n - 1; ++j) {
			std::cout << matrix_2[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << "size: " << matrix_2.size() << std::endl;

	for (auto elem : matrix_2) {
		int x,y,value;
		std::tie(x, y, value) = elem;
		std::cout << "matrix[" << x << "][" << y << "] = " << value <<std::endl;
	}

	return 0;
}