#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(float arr[], int size){
	int i, j;
	float temp;
	
	for(i=size-1; i>=0; i--){
		for(j=1; j<=i; j++){
			if (arr[j-1]>arr[j]){
				temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
			
		}
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
	
	bubbleSort(array, N);
	printf("Sorted array: \n");
	for ( i=0 ; i<N ; ++i)
	{
		printf("%f\n", array[i]);
	}
}
