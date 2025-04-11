#include "functions.h"

void print2DArr(char arr[130][130]) {
	for (int i = 0; i < 130; i++) {
		for (int j = 0; j < 130; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}

int countInstances(char arr[130][130], char target) {
	int total = 0;
	for (int i = 0; i < 130; i++) {
		for (int j = 0; j < 130; j++) {
			if (arr[i][j] == target || arr[i][j] == '+') {
				total++;
			}
		}
	}
	return total;
}

void copyArr(char dest[130][130], char src[130][130]) {
	for (int i = 0; i < 130; i++) {
		for (int j = 0; j < 130; j++) {
			dest[i][j] = src[i][j];
		}
	}
}

int moveArrayDups(Move* arr, int size, int tPosX, int tPosY, int tDir) {
	for (int i = 0; i < size - 1; i++) {
		if (tPosX == arr->posX && tPosY == arr->posY && tDir == arr->dir) {
			return 1;
		}
		arr++;
	}
	return 0;
}

void printMoveArr(Move* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("Item #%d: %d %d, facing %d\n", i, arr->posX, arr->posY, arr->dir);
		arr++;
	}
}