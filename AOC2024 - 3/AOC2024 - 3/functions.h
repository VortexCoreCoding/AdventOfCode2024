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

void printArr(char arr[], int size);

int findMul(FILE* infile, int* pnum1, int* pnum2);

int findActive(FILE* infile, int state);