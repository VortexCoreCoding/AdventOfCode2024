#include "functions.h"

int findMin(int arr[], int size) {
	int min = arr[0];
	int minIndex = 0;
	for (int i = 1; i < size; i++) {
		if (arr[i] < min) {
			min = arr[i];
			minIndex = i;
		}
	}
	arr[minIndex] = 10000000;
	return min;
}

int countInstances(int arr[], int size, int find) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] == find) {
			count++;
		}
	}
	return count;
}