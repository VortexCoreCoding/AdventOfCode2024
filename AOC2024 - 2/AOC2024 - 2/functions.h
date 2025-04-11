#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#endif

int findMin(int arr[], int size);

int countInstances(int arr[], int size, int find);

int checkPuzzle(int arr[], int size);

int checkPuzzle2(int arr[], int size);

void resetArr(int arr[], int size);

void shiftCloneArr(int arr[], int arr2[], int size, int pos);