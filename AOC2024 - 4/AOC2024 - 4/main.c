#include "functions.h"

int main() {
	clock_t start, end;
	double cpu_time_used;
	start = clock();
	FILE* infile = fopen("input.txt", "r");
	char puzzle[140][140] = { '\0' };
	int total = 0;
	int total2 = 0;
	char temp = '\0';
	int count = 0;

	while (!feof(infile) && count < 140) {
		for (int i = 0; i < 140; i++) {
			fscanf(infile, "%c", &temp);
			puzzle[count][i] = temp;
		}
		fscanf(infile, "%c", &temp);
		count++;
	}

	total += findXMAS(puzzle);
	total2 += findMAS(puzzle);

	printf("Part 1: total = %d\n", total);
	printf("Part 2: total = %d\n", total2);

	
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("Time: %.3lf", cpu_time_used);

	fclose(infile);
	return 0;
}