#include "CustomType.h"
#include "ListEntry.h"

/*
 * This file has a method for generating new entries in lists.
 */

// This method returns a pointer to a new list entry that can be added to a list or treated as a standalone list of length 1, with a value
ListEntry* getNewEntry(int value){
	struct ListEntry* newEntry = malloc(sizeof(struct ListEntry));

	newEntry->value = value;
	newEntry->priorEntry = newEntry; // the ends of a list always point back to that edge of the list itself, never to null
	newEntry->nextEntry = newEntry; // ie. the pointer to the item "above" the item on the top of the stack, just points circularly to the top of the stack.

	return newEntry;
}