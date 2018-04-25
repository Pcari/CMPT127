#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "intarr.h"

/* LAB 6 TASK 2 */

/*
  Save the entire array ia into a file called 'filename' in a JSON
  text file array file format that can be loaded by
  intarr_load_json(). Returns zero on success, or a non-zero error
  code on failure. Arrays of length 0 should produce an output file
  containing an empty array.
  
  The JSON output should be human-readable.

  Examples:

  The following line is a valid JSON array:
  [ 100, 200, 300 ]
  
  The following lines are a valid JSON array:
  [ 
   100, 
   200, 
   300 
  ]
*/
int intarr_save_json( intarr_t* ia, const char* filename ) {

	if (ia != NULL && filename != NULL) {
		FILE* f = fopen(filename, "w");
		if (f == NULL) {
			return 1;
		}
		fprintf(f, "[");
		for (int i = 0; i < ia->len; i++) { 
			if (i == (ia->len -1)) {
				fprintf(f, " %d", ia->data[i]);
			} else {
				fprintf(f, " %d,", ia->data[i]);
			}
		}
		fprintf(f, " ]");
		fclose(f);
		return 0;
	}
	return 2;
}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save(). The file may contain an array
  of length 0. Returns a pointer to a newly-allocated intarr_t on
  success (even if that array has length 0), or NULL on failure.
*/

intarr_t* intarr_load_json( const char* filename ) {
	if (filename != NULL) {
		FILE* f = fopen(filename, "r");
		if (f == NULL) {
			return NULL;
		}
		//intarr_t* new = malloc(sizeof(intarr_t));
		intarr_t* new;
		new = intarr_create(0);
		if ( new == NULL) {
			return NULL;
		}
		//need to calculate the len
		int len = 0;
		char current;
		char last ='0';
		//int c;
		while (!feof(f)) {
			//c = getchar();
			current = getc(f);
			if(isdigit(current)) {
				if (!isdigit(last)) {
					len++;	
				}	
			}
			last = current;
		}
		//new->len = len;
		// if len is 0
		if (len == 0) {
			
			return new;
		}

		//set to beginning of file
		//fseek(FILE* stream, long offset, int whence)
		//offset-> in bytes
		//whence -> position
		fseek(f, 0, SEEK_SET); 
		//new->data = malloc(len*sizeof(int));

		int data = 0;
		for (int i = 0; i < len; i++) {

			while(fscanf(f, "%d,", &data) != 1) {
				//offset by 1 byte
				//SEEK_CUR current pos
				fseek(f, 1, SEEK_CUR);
			
			}
			intarr_push(new, data);
			//printf("data: %d \n", data);
		}
		fseek(f, 0, SEEK_END);
		fclose(f);
		return new;
	}
	
	return NULL;
}


/*
//intarr load using functions from intarr.c
intarr_t* intarr_load_json( const char* filename ) {
	if (filename == NULL) {
		return NULL;
	}
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}
	//create a new intarr_t with len 0 then start adding data
	intarr_t* new;
	new = intarr_create(0);
	fseek(f, 0, SEEK_SET);
	int data = 0;
	while (!feof(f)) {
		while(fscanf(f, "%d", &data) == 1 ) {
		
		printf("data: %d\n", data);
		intarr_push(new, data);	

		}
		
		fseek(f, 1, SEEK_CUR);

		
	}
	fseek(f, 0, SEEK_END);

	fclose(f);
	return new;





}
*/
/*
int main() {

	intarr_t* test1 = malloc(sizeof(intarr_t));
	test1->len = 5;
	test1->data = malloc(sizeof(int)*test1->len);
	int num = 100;
	for (int i = 0; i < test1->len; i++) {

		test1->data[i] = num;
		num += 100;
	}

	for (int i = 0; i < test1->len; i++) {
		printf("%d ", test1->data[i]);
	}
	printf("\n");

	//int intarr_save_json( intarr_t* ia, const char* filename )
	int save = 0;
	save = intarr_save_json(test1, "filename");

	//intarr_t* intarr_load_json( const char* filename )
	intarr_t* test2;
	test2 = intarr_load_json("filename");

	printf("data length: %d\n", test2->len);

	for (int i = 0; i <test2->len; i++) {
		printf("%d ", test2->data[i]);
	}
	printf("\n");
}
*/