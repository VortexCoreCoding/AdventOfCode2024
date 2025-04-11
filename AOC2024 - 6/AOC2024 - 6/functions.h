#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#endif

typedef struct move {
	int posX;
	int posY;
	int dir;
}Move;

void print2DArr(char arr[130][130]);

int countInstances(char arr[130][130], char target);

void copyArr(char dest[130][130], char src[130][130]);

int moveArrayDups(Move* arr, int size, int tPosX, int tPosY, int tDir);

void printMoveArr(Move* arr, int size);