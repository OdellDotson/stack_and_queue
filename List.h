#include "CustomType.h"
#pragma once

// This keeps track of the head and tail of a list, and is our general stack/queue struct.
typedef struct List {
    struct ListEntry* head;
    struct ListEntry* tail;
} List;

/// @brief pushes integer to the top of the list
bool push(int value, List* list);

/// @brief pops integer value from the top of the stack, ie. using FILO logic
int pop(List* stack);

/// @brief enqueues an object to the top of the list
bool enqueue(int value, List* stack);

/// @brief dequeues an object from the front of the queue, ie. using FIFO logic
int dequeue(List* stack);
