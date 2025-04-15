#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(float arr[], int left, int mid, int right){
	int i, j ,k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	
	//Temp arrays
	float L[n1], R[n2];
	
	//Copy data to temp arrays
	for (i=0; i<n1; i++){
		L[i] = arr[left+i];
	}
	for (j=0;j<n2; j++){
		R[j] = arr[mid+1+j];
	}
	
	//Merge the temp arrays back into arr[left,.., right]
	i=0; j=0; // Initial index of first ánd second subarray
	k = left; // Initial index of merged subarray
	
	while(i<n1 && j<n2){
		if (L[i]<R[j]){
			arr[k]=L[i];
			i++;
		}else{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	
	//For remaining elements of L[]
	while (i<n1){
		arr[k]=L[i];
		i++;
		k++;
	}
	
	//For remaining elements of R[]
	while (j<n2){
		arr[k]=R[j];
		j++;
		k++;
	}
}

void mergeSort(float arr[], int left, int right){
	if(left<right){
		int mid = left + (right - left)/2;
		
		//sort first half
		mergeSort(arr, left, mid);
		//sort second half
		mergeSort(arr, mid+1, right);
		
		//merge the sorted halves
		merge(arr, left, mid, right);
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
	
	int instart = 0;
	int inend = N-1;
	
	mergeSort(array, instart, inend);
	
	printf("Sorted array: \n");
	for ( i=0 ; i<N ; ++i)
	{
		printf("%f\n", array[i]);
	}
	
	return 0;
}
