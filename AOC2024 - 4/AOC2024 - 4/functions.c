#include "functions.h"

int countInstances(int arr[], int size, int find) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] == find) {
			count++;
		}
	}
	return count;
}

void resetArr(char arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = '\0';
	}
}

void print2DArr(char arr[140][140]) {
	for (int i = 0; i < 140; i++) {
		for (int j = 0; j < 140; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}

int findXMAS(char arr[140][140]) {
	int total = 0;
	for (int i = 0; i < 140; i++) {
		for (int j = 0; j < 140; j++) {
			if (arr[i][j] == 'X') {
				total += findAllPaths(arr, i, j);
			}
		}
	}
	return total;
}

int findAllPaths(char arr[140][140], int row, int column) {
	int instances = 0;
	// check horizontal
	if (row <= 136 && arr[row + 1][column] == 'M') {
		if (arr[row + 2][column] == 'A' && arr[row + 3][column] == 'S') {
			instances++;
		}
	}
	if (row >= 3 && arr[row - 1][column] == 'M') {
		if (arr[row - 2][column] == 'A' && arr[row - 3][column] == 'S') {
			instances++;
		}
	}
	// check vertical
	if (column <= 136 && arr[row][column + 1] == 'M') {
		if (arr[row][column + 2] == 'A' && arr[row][column + 3] == 'S') {
			instances++;
		}
	}
	if (column >= 3 && arr[row][column - 1] == 'M') {
		if (arr[row][column - 2] == 'A' && arr[row][column - 3] == 'S') {
			instances++;
		}
	}
	// check diagonal
	if (row <= 136 && column <= 136 && arr[row + 1][column + 1] == 'M') {
		if (arr[row + 2][column + 2] == 'A' && arr[row + 3][column + 3] == 'S') {
			instances++;
		}
	}
	if (row >= 3 && column <= 136 && arr[row - 1][column + 1] == 'M') {
		if (arr[row - 2][column + 2] == 'A' && arr[row - 3][column + 3] == 'S') {
			instances++;
		}
	}
	if (row >= 3 && column >= 3 && arr[row - 1][column - 1] == 'M') {
		if (arr[row - 2][column - 2] == 'A' && arr[row - 3][column - 3] == 'S') {
			instances++;
		}
	}
	if (row <= 136 && column >= 3 && arr[row + 1][column - 1] == 'M') {
		if (arr[row + 2][column - 2] == 'A' && arr[row + 3][column - 3] == 'S') {
			instances++;
		}
	}
	return instances;
}

int findMAS(char arr[140][140]) {
	int total = 0;
	for (int i = 1; i < 139; i++) {
		for (int j = 1; j < 139; j++) {
			if (arr[i][j] == 'A') {
				total += findAllMas(arr, i, j);
			}
		}
	}
	return total;
}

int findAllMas(char arr[140][140], int row, int column) {
	char topL = arr[row - 1][column + 1];
	char topR = arr[row + 1][column + 1];
	char botL = arr[row - 1][column - 1];
	char botR = arr[row + 1][column - 1];

	if (topL == 'M') { // top left is m
		if (topR == 'M') { // top right is m
			if (botL == 'S' && botR == 'S') { // bottom left and bottom right must be s
				return 1;
			}
		}
		else if (botL == 'M') { // bottom left is m
			if (topR == 'S' && botR == 'S') { // top right and bottom tight must be s
				return 1;
			}
		}
	}
	else if (topR == 'M') { // top right is m, top left not m
		if (botR == 'M') { // bottom right is m
			if (topL == 'S' && botL == 'S') { // top left and bottom left must be s
				return 1;
			}
		}
	}
	else if (botL == 'M' && botR == 'M') { // top two cannot be m at this point
		if (topL == 'S' && topR == 'S') { // top two must be s
			return 1;
		}
	}
	return 0;
}