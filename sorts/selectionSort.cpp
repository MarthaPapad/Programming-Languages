#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(float arr[], int size){
	int i, j;
	float temp;
	
	for(i=0; i<size; i++){
		int min = i;
		for(j=i+1; j<size; j++){
			if (arr[j]<arr[min]) min = j;
		}
		temp = arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
	}
}

int main(){
	int i, a, b, N, HI, LO;
	time_t t;
	float x;
	
	/* Intializes random number generator */
    srand((unsigned) time(&t));
	
	printf("Please enter first interval edge: ");
	scanf("%d", &a);
	
	printf("Please enter secord interval edge: ");
	scanf("%d", &b);
	
	printf("Please enter number of random numbers: ");
	scanf("%d", &N);
	
	if (a>b)
	{
		HI = a;
		LO = b;
	} else{
		HI = b;
		LO = a;
	}
	
	float array[N];
	
	printf("Unsorted array: \n");
	for ( i=0 ; i<N ; ++i)
	{
		x = LO + (float)(rand())/((float)(RAND_MAX/(HI-LO)));
		array[i] = x;
		printf("%f\n", x);
	}
	
	selectionSort(array, N);
	printf("Sorted array: \n");
	for ( i=0 ; i<N ; ++i)
	{
		printf("%f\n", array[i]);
	}
}
