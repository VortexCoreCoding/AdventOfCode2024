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

void resetArr(char arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = '\0';
	}
}

void printArr(char arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%c", arr[i]);
	}
}

int findMul(FILE* infile, int* pnum1, int* pnum2) {
	char temp = '\0';
	int num1 = 0;
	int num2 = 0;
	int correct = 1;
	while (1) {
		fscanf(infile, "%c", &temp);
		if (temp == 'm') {
			return -1;
		}
		else if (correct == 1 && temp == 'u') {
			correct++;
		}
		else if (correct == 2 && temp == 'l') {
			correct++;
		}
		else if (correct == 3 && temp == '(') {
			//expects numbers to follow, correct currently equals 3
			while (1) {
				fscanf(infile, "%c", &temp);

				// if temp is a digit
				if (correct == 3 && temp >= 48 && temp <= 57) {
					correct++;
					num1 = temp - 48;
				}
				else if (correct == 4 && temp >= 48 && temp <= 57) {
					correct++;
					num1 *= 10;
					num1 += temp - 48;
				}
				else if (correct == 5 && temp >= 48 && temp <= 57) {
					correct++;
					num1 *= 10;
					num1 += temp - 48;
				}
				else if (correct > 3 && temp == ',') {
					break;
				}
				else if (temp == 'm') {
					return -1;
				}
				else {
					return 0;
				}
			}
			break;
		}
		else {
			return 0;
		}
	}
	// If the code ever reaches here that means that it is correct through the first number's completion
	correct = 1;
	while (1) {
		fscanf(infile, "%c", &temp);

		// if temp is a digit
		if (correct == 1 && temp >= 48 && temp <= 57) {
			correct++;
			num2 = temp - 48;
		}
		else if (correct == 2 && temp >= 48 && temp <= 57) {
			correct++;
			num2 *= 10;
			num2 += temp - 48;
		}
		else if (correct == 3 && temp >= 48 && temp <= 57) {
			correct++;
			num2 *= 10;
			num2 += temp - 48;
		}
		else if (correct > 1 && temp == ')') {
			*pnum1 = num1;
			*pnum2 = num2;
			return 1;
		}
		else if (temp == 'm') {
			return -1;
		}
		else {
			return 0;
		}
	}
}

int findActive(FILE* infile, int state) {
	char temp = '\0';
	int correct = 1;
	while (1) {
		fscanf(infile, "%c", &temp);
		if (correct == 1 && temp == 'o') {
			correct++;
		}
		else if (correct == 2 && temp == '(') {
			correct++;
			fscanf(infile, "%c", &temp);
			if (correct == 3 && temp == ')') {
				return 1;
			}
			else {
				return state;
			}
		}
		else if (correct == 2 && temp == 'n') {
			while (1) {
				fscanf(infile, "%c", &temp);
				if (correct == 2 && temp == '\'') {
					correct++;
				}
				else if (correct == 3 && temp == 't') {
					correct++;
				}
				else if (correct == 4 && temp == '(') {
					correct++;
				}
				else if (correct == 5 && temp == ')') {
					return 0;
				}
				else {
					return state;
				}
			}
		}
		else {
			return state;
		}
	}

}