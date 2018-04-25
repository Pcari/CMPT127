/*
#include <stdio.h>

void reverse(int arr[], unsigned int len);

int main() {

	int a[] = {11, 12, 13};
	int b[] = {1, 2, 3, 4, 5, 6, 7};
	int c[] = {};
	int d[] = {1, 2};
	unsigned int len = 2;

	reverse(d, len);

	for (int i = 0; i < len; i++) {
		printf("%d ", d[i]);
	}
	printf("\n");

	return 0;
}
*/
void reverse(int arr[], unsigned int len) {

	for (int i = 0, j = len-1; i < len/2; i++, j--) {
		int tmp = 0;
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;

	}
}