#include "functions.h"

int main() {
	clock_t start, end;
	double cpu_time_used;
	start = clock();
	FILE* infile = fopen("input.txt", "r");
	char temp = '\0';
	int num = 0;
	char mulArr[13] = { '\0' };
	mulArr[12] = '\0';
	int count = 1;
	int num1 = 0;
	int num2 = 0;
	int total = 0;
	int total2 = 0;
	int active = 1;
	
	while (!feof(infile)) {
		fscanf(infile, "%c", &temp);
		if (temp == 'm') {
			num = findMul(infile, &num1, &num2);
			if (num == 1) {
				total += num1 * num2;
				if (active == 1) {
					total2 += num1 * num2;
				}
			}
		}
		if (temp == 'd') {
			active = findActive(infile, active);
		}
	}

	printf("Part 1: total = %d\n", total);
	printf("Part 2: total = %d\n", total2);

	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("Time: %.3lf", cpu_time_used);

	fclose(infile);
	return 0;
}