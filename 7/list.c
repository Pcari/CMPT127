#include <stdio.h>
#include <stdlib.h>
#include "list.h"


// returns a pointer to a new header for an empty list, or NULL if
// memory allocation fails.
list_t* list_create( void ) {
	list_t * list = malloc(sizeof(list_t));
	if (list != NULL) {
		list->head = NULL;
		list->tail = NULL;
	}
	return list;
}

// frees all the memory used by the list
void list_destroy( list_t* list ) {
	element_t* curr = list->head;
	element_t* next;
	while (curr != NULL) {
		next = curr->next;
		
		free(curr);
		curr = next;
	}
	free(list);	
}

// returns a pointer to a new list element containing integer i and
// next-pointer set to NULL, or NULL if memory allocation fails.
element_t* element_create( int i ) {
	element_t* ele = malloc(sizeof(element_t));
	if (ele == NULL) {
		return NULL;
	}
	ele->val = i;
	ele->next = NULL;
	return ele;
	
}

// Appends a new element containing integer i to the end of the
// list. Returns 0 on success, else 1.
int list_append( list_t* list, int i ) {
	element_t* ele = element_create(i);
	if (ele == NULL) {
		return 1;
	}
	if (list->head == NULL) {
		//empty list
		list->head = ele;
		list->tail = ele;
	} else {
		list->tail->next = ele;
		list->tail = ele;
	}
	return 0;

}

// Prepends a new element containing integer i to the head of the
// list. Returns 0 on success, else 1.
int list_prepend( list_t* list, int i ) {
	element_t* ele = element_create(i);
	if (ele == NULL) {
		return 1;
	}
	if (list->head == NULL) {
		//empty list
		list->head = ele;
		list->tail = ele;
	}
	else {
		ele->next = list->head;
		list->head = ele;
	}

	return 0;
}

// Returns a pointer to the ith list element, where the list head is
// 0, head->next is 1, etc., or NULL if i is out of range (i.e. larger
// than (number of list elements -1 ))
element_t* list_index( list_t* list, unsigned int i ) {

	element_t* curr = list->head;
	int count = 0;
	while (curr != NULL) {
		if (count == i) {
			return curr;
		}
		count++;
		curr = curr->next;
	}
	return NULL;
	/*
	if (list->head == NULL) {
		return NULL;
	}
	element_t* curr = list->head;
	if (curr == NULL) {
		return NULL;
	}
	int len = 0;
	while (curr != NULL) {
		curr = curr->next;
		len++;
	}
	if (i < 0 && i > len) {
		return NULL;
	}
	else {
		curr = list->head;
		int count = 0;
		while (count < i) {
			count++;
			curr = curr->next;
		}
	}
	return curr;
	*/

/*
	element_t* ele = list->head;
	unsigned int now = 0;
	while (now < i) {
		
		now++;
		ele = ele->next;
	}
	return ele;
	*/
	
}

// Prints a list in human-readable form from the first to last
// elements, between curly braces.
void list_print( list_t* list ) {
	printf( "{");
	for (element_t* ele = list->head; ele; ele = ele->next) {
		printf(" %d", ele->val);
	}
	printf(" }\n");
}