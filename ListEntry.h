#include "CustomType.h"
#pragma once

/*
 * This file contains the definition of our basic data structure for entries in a lis
 */

typedef struct ListEntry {
	int value; // integer value at this point in the list.
	struct ListEntry* priorEntry; // points to the previous item in the list 
	struct ListEntry* nextEntry;  // points to the next item in the list
} ListEntry;

/// @brief returns a pointer to a new ListEntry object with specified integer value
ListEntry* getNewEntry(int value);