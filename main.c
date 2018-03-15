/*
 ============================================================================
 Name        : SegmentTree.c
 Author      : DFS
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int getMid(int a, int b){
	return (a + (b - a) / 2);
}

int constructStUtil(int *in, int* outputArray, int start, int end, int currentIndex){
	if (start == end){
		outputArray[currentIndex] = in[start];
		printf("Index order %d\n", start);
		printf("Current index order %d\n", currentIndex);
		return in[start];
	}

	int mid = getMid (start, end);

	outputArray[currentIndex] = constructStUtil(in, outputArray, start, mid, 2 * currentIndex + 1)
		+ constructStUtil(in, outputArray, mid+1, end, 2 * currentIndex + 2);

	printf("Current index order %d\n", currentIndex);

	return outputArray[currentIndex];
}

int * constructST(int* inputArray, int* outputArray, int length){
	constructStUtil(inputArray, outputArray, 0, length - 1, 0);

	return outputArray;
}

int getSumUtil (int *segmentArray, int ss, int se, int qs, int qe, int index){
	if (qs >= ss && qe <= se){
		return segmentArray[index];
	}

	if (se < qs || ss > qe){
		return 0;
	}

	int mid = getMid(ss, se);

	return getSumUtil(segmentArray, ss, mid, qs, qe, 2*index+1)
			+ getSumUtil(segmentArray, mid+1, se, qs, qe, 2*index+2);
}

int getSum (int *segmentArray, int qs, int qe, int length){
	if (qs < 0 || qe > length-1 || qs > qe){
		return 0;
	}

	return getSumUtil(segmentArray, 0, length-1, qs, qe, 0);
}


int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	int array[] = { 1, 2, 3, 4, 5 };

	int sizeOfArray = sizeof (array) / sizeof(array[0]);

	int *segmentArray = (int *) malloc (sizeof (int *) * (2 * sizeOfArray - 1));

	constructST(array, segmentArray, sizeOfArray);

	for (int i = 0; i < 2 * sizeOfArray - 1; i++){
		printf("%d\n",segmentArray[i]);
	}

	// Find sum after the value is updated
	printf("Updated sum of values in given range = %d\n",
	             getSum(segmentArray, sizeOfArray, 1, 3));

	return 0;
}
