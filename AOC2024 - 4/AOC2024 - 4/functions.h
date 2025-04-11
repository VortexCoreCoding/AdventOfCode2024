#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#endif

int findMin(int arr[], int size);

int countInstances(int arr[], int size, int find);

void resetArr(char arr[], int size);

void print2DArr(char arr[140][140]);

int findXMAS(char arr[140][140]);

int findAllPaths(char arr[140][140], int row, int column);

int findMAS(char arr[140][140]);

int findAllMas(char arr[140][140], int row, int column);