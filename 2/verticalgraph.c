#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

int i = 0;
int input = 0;
int arr[256] = {0};
int numInputs = 0;
int row = 0;
int col = 0;
int max = 0;


	while(scanf("%d", &input) == 1) {
		arr[i] = input;
		numInputs++;
		i++;
	}




//printf("\n");


	for (int j = 0; j < numInputs; j++) {
		
		if (arr[j] > max) {
			max = arr[j];
		}
	//	printf("max: %d \n", max);
	}
	
	row = max;

	for (int j = row; j > 0; j--) {
		for (int k =0; k < numInputs; k++) {
			if (arr[k] < j) {
				
				printf(" ");
			} 
			if (arr[k] >= j) {
				
				printf("#");
			}
			
		}
		printf("\n");

	}

/*

	for (int j = 0; j < numInputs; j++) {

		printf("%d ", arr[j]);		
	}
	printf("Number of Inputs: %d\n", numInputs);
	printf("Max: %d\n", max);
	printf("Column: %d\n", col);
*/



/*
printf(" array length: %d\n", sizeof(arr)/4);

for (int j = 0; j < numInputs; j++) {
	printf("%d\n", arr[j]);


}
*/
	return 0;
}
