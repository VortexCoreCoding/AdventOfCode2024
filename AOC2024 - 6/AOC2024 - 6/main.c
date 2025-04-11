#include "functions.h"

int main() {
	clock_t start, end;
	double cpu_time_used;
	start = clock();
	FILE* infile = fopen("input.txt", "r");
	int total = 0, total2 = 0;
	int direction = 0; // 0 = up, 1 = right, 2 = down, 3 = left
	int guardX = -1, guardY = -1;
	int guardX2 = -1, guardY2 = -1;
	int guardX3 = -1, guardY3 = -1;
	char maze[130][130] = { '\0' };
	char temp = '\0';
	int moveSize = 0;
	Move* arr = (Move*)malloc((13000) * sizeof(Move)); // allocate for 130k units of move
	
	// Assign characters into the maze
	for (int i = 0; i < 130; i++) {
		for (int j = 0; j < 130; j++) {
			fscanf(infile, "%c", &maze[i][j]);
			if (maze[i][j] == '^') {
				guardX = i;
				guardY = j;
				guardX2 = i;
				guardY2 = j;
			}
		}
		fscanf(infile, "%c", &temp);
	}

	// P1 loop
	while (direction != -1) {
		if (direction == 0) {
			if (guardX - 1 < 0) {
				maze[guardX][guardY] = 'X';
				direction = -1;
			}
			else if (maze[guardX - 1][guardY] == '#') {
				direction = 1;
			}
			else {
				if (maze[guardX][guardY] != '+') {
					maze[guardX][guardY] = 'X';
				}
				guardX--;
			}
		}
		else if (direction == 1) {
			if (guardY + 1 > 130) {
				maze[guardX][guardY] = 'X';
				direction = -1;
			}
			else if (maze[guardX][guardY + 1] == '#') {
				direction = 2;
			}
			else {
				if (maze[guardX][guardY] != '+') {
					maze[guardX][guardY] = 'X';
				}
				guardY++;
			}
		}
		else if (direction == 2) {
			if (guardX + 1 > 130) {
				maze[guardX][guardY] = 'X';
				direction = -1;
			}
			if (maze[guardX + 1][guardY] == '#') {
				direction = 3;
			}
			else {
				if (maze[guardX][guardY] != '+') {
					maze[guardX][guardY] = 'X';
				}
				guardX++;
			}
		}
		else if (direction == 3) {
			if (guardY - 1 < 0) {
				maze[guardX][guardY] = 'X';
				direction = -1;
			}
			else if (maze[guardX][guardY - 1] == '#') {
				direction = 0;
			}
			else {
				if (maze[guardX][guardY] != '+') {
					maze[guardX][guardY] = 'X';
				}
				guardY--;
			}
		}
	}

	// P2 loop
	for (int i = 0; i < 130; i++) {
		for (int j = 0; j < 130; j++) {
			guardX3 = guardX2;
			guardY3 = guardY2;
			if (maze[i][j] == 'X') {
				maze[i][j] = '#';
				direction = 0;
				moveSize = 0;
				// start of loop
				while (direction != -1) {
					// loops while still on field
					if (direction == 0) {
						// going up
						if (guardX3 - 1 < 0) {
							// if going off field, end
							break;
						}
						else if (maze[guardX3 - 1][guardY3] == '#') {
							// if running into a blocker
							direction = 1;
						}
						else {
							arr += moveSize; // increment the pointed position from 0 to the max (an unfilled slot)
							moveSize++; // increase size of array tracker (starts at 0)
							arr->posX = guardX3; // assign the variable guardX3 to posX
							arr->posY = guardY3; // assign the var guardY3 to posY
							arr->dir = direction; // assign direction to dir
							arr -= (moveSize - 1); // decrement pointer back to what it started as
							if (moveArrayDups(arr, moveSize, guardX3, guardY3, direction) == 1) {
								total2++; 
								break;
							}
							guardX3--;
						}
					}
					else if (direction == 1) {
						if (guardY3 + 1 > 130) {
							break;
						}
						else if (maze[guardX3][guardY3 + 1] == '#') {
							direction = 2;
						}
						else {
							arr += moveSize;
							moveSize++; // increase size of array tracker (starts at 0)
							arr->posX = guardX3; // assign the variable guardX3 to posX
							arr->posY = guardY3; // assign the var guardY3 to posY
							arr->dir = direction; // assign direction to dir
							arr -= (moveSize - 1);
							if (moveArrayDups(arr, moveSize, guardX3, guardY3, direction) == 1) {
								total2++;
								break;
							}
							guardY3++;
						}
					}
					else if (direction == 2) {
						if (guardX3 + 1 > 130) {
							break;
						}
						if (maze[guardX3 + 1][guardY3] == '#') {
							direction = 3;
						}
						else {
							arr += moveSize;
							moveSize++; // increase size of array tracker (starts at 0)
							arr->posX = guardX3; // assign the variable guardX3 to posX
							arr->posY = guardY3; // assign the var guardY3 to posY
							arr->dir = direction; // assign direction to dir
							arr -= (moveSize - 1);
							if (moveArrayDups(arr, moveSize, guardX3, guardY3, direction) == 1) {
								total2++;
								break;
							}
							guardX3++;
						}
					}
					else if (direction == 3) {
						if (guardY3 - 1 < 0) {
							break;
						}
						else if (maze[guardX3][guardY3 - 1] == '#') {
							direction = 0;
						}
						else {
							arr += moveSize;
							moveSize++; // increase size of array tracker (starts at 0)
							arr->posX = guardX3; // assign the variable guardX3 to posX
							arr->posY = guardY3; // assign the var guardY3 to posY
							arr->dir = direction; // assign direction to dir
							arr -= (moveSize - 1);
							if (moveArrayDups(arr, moveSize, guardX3, guardY3, direction) == 1) {
								total2++;
								break;
							}
							guardY3--;
						}
					}
				}
				//end of loop above
				maze[i][j] = 'X';
			}
		}
	}

	total = countInstances(maze, 'X');
	
	printf("\nPart 1: total = %d\n", total);
	printf("\nPart 2: total = %d\n", total2);

	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("Time: %.3lf\n", cpu_time_used);

	fclose(infile);
	return 0;
}