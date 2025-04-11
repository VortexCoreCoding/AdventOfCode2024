#include "functions.h"

int main() {
	clock_t start, end;
	double cpu_time_used;
	start = clock();
	FILE* infile = fopen("input.txt", "r");
	int total = 0;
	int puz2Total = 0;
	char temp = '\0';
	int num = 0;
	int count;
	int i = 0;
	int arr[8] = { 0 };
	int arr2[8] = { 0 };


	while (!feof(infile)) {
		count = 0;
		resetArr(arr, 8);
		do {
			fscanf(infile, "%d", &num);
			fscanf(infile, "%c", &temp);
			arr[count] = num;
			arr2[count] = num;
			count++;
		} while (temp != '\n');
		if (checkPuzzle(arr, count) == 1) {
			total++;
		}
		if (checkPuzzle2(arr2, count) == 1) {
			puz2Total++;
		}
		i++;
	}
	printf("Part 1: #ofSafeReports = %d\n", total);
	printf("Part 2: #ofSafeReports = %d\n", puz2Total);

	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("Time: %.3lf", cpu_time_used);

	fclose(infile);
	return 0;
}