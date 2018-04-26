
/*
#include <stdio.h>
int scrambled(unsigned int a[], unsigned int b[], unsigned int len);

int main() {

	unsigned int arr1[] = {1, 2, 3, 4, 5};
	unsigned int arr2[] = {5, 3, 4, 2, 1};

	unsigned int arr3[] = {2, 1, 3, 4, 5};
	unsigned int arr4[] = {5, 3, 4, 2, 2};

	if (scrambled(arr1, arr2, 5) == 1) {
		printf("b is a scrambled version of a\n");
	} else {
		printf("b has different contents to a\n");
	}
	if (scrambled(arr3, arr4, 5) == 1) {
		printf("b is a scrambled version of a\n");
	} else {
		printf("b has different contents to a\n");
	}


return 0;
}

*/
int scrambled(unsigned int a[], unsigned int b[], unsigned int len) {
	int arr[100] = {  };
	if (len == 0) {
		return 1;
	}
	/*
	for (int i = 0; i < len; i++) {
		int tmp = 0;
		tmp = a[i];
		arr[tmp]++;
	}
	for (int i = 0; i < len; i++) {
		int tmp = 0;
		tmp = b[i];
		arr[tmp]--;
	}
	*/
	for (int i = 0; i < len; i++) {
		int tmp1 = 0, tmp2 = 0;
		tmp1 = a[i];
		tmp2 = b[i];
		arr[tmp1]++;
		arr[tmp2]--;
	}
	for (int i = 0; i < 100; i++) {
		if (arr[i] != 0) {
			return 0;
		}
	}
	return 1;
}