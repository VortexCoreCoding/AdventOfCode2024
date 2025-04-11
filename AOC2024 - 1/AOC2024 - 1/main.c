#include "functions.h"

int main() {
	clock_t start, end;
	double cpu_time_used;
	FILE* infile = fopen("input.txt", "r");
	int count = 0;
	int arrL[1000] = { 0 };
	int arrR[1000] = { 0 };
	int temp = 0;
	int numL = 0;
	int numR = 0;

	int totalDist = 0;
	int simScore = 0;

	start = clock();

	while (!feof(infile)) {
		fscanf(infile, "%d", &numL);
		fscanf(infile, "%d", &numR);
		arrL[count] = numL;
		arrR[count] = numR;
		count++;
	}
	count = 0;

	for (int i = 0; i < 1000; i++) {
		numL = arrL[i];
		count = countInstances(arrR, 1000, numL);
		simScore += count * numL;
	}

	for (int i = 0; i < 1000; i++) {
		int numL = findMin(arrL, 1000);
		int numR = findMin(arrR, 1000);
		if (numL == 10000000 || numR == 10000000) {
			break;
		}
		if (numR > numL) {
			totalDist += numR - numL;
		}
		else {
			totalDist += numL - numR;
		}
	}
	printf("Part 1: Total Distance = %d\n", totalDist);
	printf("Part 2: Total Distance = %d\n", simScore);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("Time: %.3lf", cpu_time_used);

	fclose(infile);
	return 0;
}