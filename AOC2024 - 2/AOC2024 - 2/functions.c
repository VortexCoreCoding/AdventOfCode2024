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
	//arr[minIndex] = 10000000;
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

void resetArr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}
}

int checkPuzzle(int arr[], int size) {
	int direction = 0; // if 1 then inc, -1 is dec
	int diff = arr[1] - arr[0];
	if (arr[1] > arr[0]) {
		direction = 1;
	}
	else {
		direction = -1;
	}
	if (abs(diff) > 3 || abs(diff) < 1) {
		return 0;
	}

	// loop checks for all same direction
	for (int i = 2; i < size; i++) {
		if (arr[i] > arr[i - 1]) {
			if (direction == -1) {
				return 0;
			}
		}
		else {
			if (direction == 1) {
				return 0;
			}
		}
		diff = arr[i] - arr[i - 1];
		if (abs(diff) > 3 || abs(diff) < 1) {
			return 0;
		}
	}
	return 1;
}

int checkPuzzle2(int arr[], int size) {
	int direction = 0, problems = 0; // if 1 then inc, -1 is dec
	int diff = abs(arr[1] - arr[0]);
	int i = 2;
	int arr2[8] = { 0 };
	if (arr[1] > arr[0]) {
		direction = 1;
	}
	else {
		direction = -1;
	}

	if (diff > 3 || diff < 1) {
		problems++;
	}

	for (; i < size; i++) {
		if (arr[i] > arr[i - 1]) {
			if (direction == -1) {
				problems++;
			}
		}
		else {
			if (direction == 1) {
				problems++;
			}
		}
		// checks within 1-3
		diff = abs(arr[i] - arr[i - 1]);
		if (diff > 3 || diff < 1) {
			problems++;
		}
	}
	if (problems == 0) {
		return 1;
	}
	else if (problems > 0) {
		for (int i = 0; i < size; i++) {
			shiftCloneArr(arr, arr2, size, i);
			if (checkPuzzle(arr2, size - 1) == 1) {
				return 1;
			}
		}
	}
	return 0;
}

void shiftCloneArr(int arr[], int arr2[], int size, int pos) {
	for (int i = 0; i < size; i++) {
		arr2[i] = arr[i];
	}
	for (int i = pos; i + 1 < size; i++) {
		arr2[i] = arr2[i + 1];
	}
	arr2[size - 1] = 0;
}