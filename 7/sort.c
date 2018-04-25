#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list.h"


void appendElement(list_t* list, element_t* ele) {
	if (ele != NULL) {
		ele->next = NULL;
	}
	if (list->head == NULL) {
		//assert(list->head == NULL);
		//empty
		list->head = ele;
		list->tail = ele;
	} else {
		//not empty
		list->tail->next = ele;
		list->tail = ele;
	}
}

void catenate(list_t* list1, list_t* list2) {
	if (list2->head == NULL) {
		//nothing to attach
		assert(list2->tail == NULL);
	}
	else if (list1->head == NULL) {
		assert(list1->tail == NULL);
		//first list is empty
		//*list1 = *list2;
		list1->head = list2->head;
		list1->tail = list2->tail;

	} else {
		list1->tail->next = list2->head;
		list1->tail = list2->tail;
	}
	free(list2);
}



void list_sort( list_t* list ) {
	//base
	if (list->head == list->tail) {
		return;
	}
	int pivot = list->head->val;
	element_t* ele_pivot = list->head;
	list->head = list->head->next;

	//printf("pivot: %d\n", pivot);

	list_t* low = list_create();
	list_t* high = list_create();

	element_t* curr = list->head;
	element_t* next;

	//printf("before while loop\n");

	while (curr != NULL) { 
		next = curr->next; //before losing curr
		curr->next = NULL; //for seg fault
		if (curr->val < pivot) {
			appendElement(low, curr);
		} else {
			// equal to or greater than pivot
			appendElement(high, curr);
		}
		curr = next;

	/*	
	printf("low:\n");
	list_print(low);
	printf("high:\n");
	list_print(high);
	*/
	}
	/*
	printf("after while loop, before recursive\n");
	printf("low:\n");
	list_print(low);
	printf("high:\n");
	list_print(high);
	*/

	// will put sorted list on original list
	list->head = NULL;
	list->tail = NULL;

	list_sort(low);
	list_sort(high);

	/*
	printf("after all recursives\n");
	printf("low:\n");
	list_print(low);
	printf("high:\n");
	list_print(high);
	*/

	//printf("pivotnode: %d\n", ele_pivot->val);

	//printf("test1: \n");
	catenate(list, low);

	//list_print(list);

	//printf("test2: \n");
	appendElement(list, ele_pivot);

	//list_print(list);

	//printf("test3: \n");
	catenate(list, high);

	//list_print(list);

/*
	while (curr != NULL) {
		next = curr->next;
		curr->next = NULL; // moving node so pointer should reset
		if (curr->val < pivot) {
			//curr->next = NULL;
			if (low->head == NULL) {
				low->head = curr;
				low->tail = curr; 
			} else {
				low->tail->next = curr;
				low->tail = curr;
			}
		}
		else {
			//curr->next = NULL;
			if (high->head == NULL) {
				high->head = curr;
				high->tail = curr;
			} else {
				high->tail->next = curr;
				high->tail = curr;
			}
		}
		curr = next;
	}
	
	printf("low:\n");
	list_print(low);
	printf("high:\n");
	list_print(high);


	//
	printf("after while loop, before recursive\n");

	list->head = NULL;
	list->tail = NULL;

	list_sort(low);
	list_sort(high);

	printf("after all recursives\n");


	
	list->head = low->head;
	list->tail = low->tail;
	


	printf("after *head = *low\n");

	list_print(low);
	list_print(high);
	printf("pivot node: %d\n", ele_pivot->val);

	list->head = low->head;
	list->tail->next = ele_pivot;
	list->tail = ele_pivot;

	printf("after adding pivot node\n");

	list->tail->next = high->head;
	list->tail = high->tail;
	*/

}

/*
int main() {
	list_t* list = list_create();

	list_append(list, 5);
	list_append(list, 10);
	list_append(list, 3);
	list_append(list, 7);
	list_append(list, 0);
	list_append(list, 2);
	list_append(list, 8);


	printf("main test: \n");
	list_print(list);

	list_sort(list);
	list_print(list);


}
*/