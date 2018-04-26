
/*
#include <stdio.h>

int identical(int a[], int b[], unsigned int len);



int main() {

int a[] = {10, 15, 20};
int b[] = {10, 15, 20};
int a1[] = {5, 2 , 2, 3, 4, 5, 5};
int b1[] = {5, 2, 2, 3, 4, 5, 5};
int a2[] = {};
int b2[] = {};

int a3[] = {1,1};
int b3[] = {1,2};
int a4[] = {10,15,20};
int b4[] = {10,15,21};

if (identical(a4, b4, 3) == 1) {
	printf("a and b are identical\n");
} else {
	printf("a and b are NOT identical\n");
}

	return 0;
}

*/

int identical(int a[], int b[], unsigned int len) {
	if (len == 0) {
		return 1;
	}
	for (int i = 0; i < len; i++) {
		if (a[i] != b[i]) {
			return 0;
		}

	}
		return 1;
}