#include "CustomType.h"
#include "List.h"
#include "ListEntry.h"

/*
 * This file contains methods for FIFO and FILO adding and removing from a list
 */

// Removes an item using FIFO or FILO logic, depending on FIFO boolean flag, and returns that value.
// This method is a helper method for popping and queueing, and should not see use outside of this file.
int _removeEntry(List* list, bool FirstInFirstOut){
	if(list->head == NULL && list->tail == NULL){ // If the list index pointers are null, ie. you trying to remove from empty list
		printf("ERROR: ATTEMPTING TO REMOVE FROM EMPTY LIST, RETURNING 0\r\n"); // Not really sure what we'd want to do here, probably raise an exception if we had an exception framework at hand
		return 0;
	}

	int removedValue = list->head->value; // the value from the removed node. Default to head, as that is the val returned in the first two conditions on the next block

	if(list->tail == list->head){ // If head ptr == tail ptr, we're removing the only value from list
		list->head = NULL; // reset head and tail to null, as the list is now empty 
		list->tail = NULL;
	}
	else if(FirstInFirstOut){ //neither empty list nor 1-value list, if FIFO remove from head
		free(list->head); // free the mem for the removed node
		list->head = list->head->nextEntry; // update head ptr of list
		list->head->priorEntry = list->head; // wrap priorEntry ptr back to self in head of list to avoid a null pointer
	}
	else{ // if FILO, remove from tail
		removedValue = list->tail->value; // grab value from head if FIFO of list
		free(list->tail); // free the mem for the removed node
		list->tail = list->tail->priorEntry; // update tail ptr of list
		list->tail->nextEntry = list->tail; // wrap nextEntry pointer back to self for last entry in list so we avoid a null pointer
	}

	return removedValue;
}


// Adds a value to the list for FILO logic
bool push(int value, List* stack){
	ListEntry* newEntry = getNewEntry(value);

	if(stack->head == NULL && stack->tail == NULL){ // If there are no entries yet, ie empty list
		stack->head = newEntry; // set entry to be new head of list
		stack->tail = newEntry; // set entry to be new tail of list
	}
	else{ // if there are already values in the list
		newEntry->priorEntry = stack->tail; // Set new entry's prior list entry to be prior end of list		
		stack->tail->nextEntry = newEntry; // Point current tail's nextEntry pointer to newEntry, appending to list
		stack->tail = newEntry; // update list's tail pointer to new tail of list
	}

	return true;
}


// Adds a value to the list for FIFO logic
bool enqueue(int value, List* queue){
	return push(value, queue);
}


// removes a value using FILO logic 
int pop(List* stack){
	return _removeEntry(stack, false);
}


//removes a value using FIFO logic
int dequeue(List* queue){
	return _removeEntry(queue, true);
}
