// Win32Project1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"


int getMid(int a, int b){
	return (a + (b - a) / 2);
}

int constructStUtil(int *in, int* outputArray, int start, int end, int currentIndex){
	if (start == end){
		outputArray[currentIndex] = in[start];
		return in[start];
	}

	int mid = getMid (start, end);

	outputArray[currentIndex] = constructStUtil(in, outputArray, start, mid, 2 * currentIndex + 1)
		+ constructStUtil(in, outputArray, mid+1, end, 2 * currentIndex + 2);
}

int * constructST(int* inputArray, int* outputArray, int length){
	int mid = getMid(0, length);

	constructStUtil(inputArray, outputArray, 0, length - 1, 0);

	return outputArray;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int array[] = { 1, 2, 3, 4, 5 };

	int sizeOfArray = sizeof (array) / sizeof(array[0]);
	
	int *segmentArray = new int[2 * sizeOfArray + 1];

	constructST(array, segmentArray, sizeOfArray);

	for (int i = 0; i < 2 * sizeOfArray + 1; i++){
		printf("%d\n", segmentArray[i]);
	}

	return 0;
}

