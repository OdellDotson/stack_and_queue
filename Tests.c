#include "List.h"

/*
 *This file contains a method for running tests with some formatting, and then a bunch of unit tests for the rest of the code.
*/


// Runs a test, prints easier to read output. One of the first things I wrote for this project, so that I could use TDD to develop.
void runTest(char* testName, bool (*test)() ){
	bool passed = test();
	printf("%s %s test is %s \r\n", 
		((passed == true) ? "   " : "!!!"), // visual identifier for failing tests
		testName,
		((passed == true) ? "passing! Good work!" : " failing! More work to do!"));
}


// Tests a simple push and pop from a stack
bool simplePushPop(){
	List stack = {NULL, NULL};

	push(1, &stack);
	if(pop(&stack)!=1){ return false; }

	return true;
}


// tests a simple queue and dequeue from a queue
bool simpleQueueDequeue(){
	List queue = {NULL, NULL};

	enqueue(1, &queue);
	if(dequeue(&queue)!=1){ return false; }

	return true;
}


//tests pushing and popping with multiple lists - was a sanity check test for a bug
bool multistackSimplePushPop(){
	List stack = {NULL, NULL};
	List stack2 = {NULL, NULL};

	push(1, &stack);
	push(10, &stack2);

	if(pop(&stack)!=1){ return false; }
	push(2, &stack);
	if(pop(&stack)!=2){ return false; }
	if(pop(&stack2)!=10){ return false; }

	return true;
}


//tests queueing and dequeueing with multiple lists - was a sanity check test for a bug
bool multiqueueSimpleQueueDequeue(){
	List queue = {NULL, NULL};
	List queue2 = {NULL, NULL};

	enqueue(1, &queue);
	enqueue(10, &queue2);

	if(dequeue(&queue)!=1){ return false; }

	enqueue(2, &queue);

	if(dequeue(&queue)!=2){ return false; }
	if(dequeue(&queue2)!=10){ return false; }

	return true;
}


//tests pushing a series of numbers and then popping them all, then pushing them all and popping them all again.
bool linearPushPop(){
	List stack = {NULL, NULL};

	push(5, &stack);
	push(10, &stack);
	push(15, &stack);
	push(20, &stack);

	if(pop(&stack)!=20){ return false; }
	if(pop(&stack)!=15){ return false; }
	if(pop(&stack)!=10){ return false; }
	if(pop(&stack)!=5){ return false; }

	push(5, &stack);
	push(10, &stack);
	push(15, &stack);
	push(20, &stack);

	if(pop(&stack)!=20){ return false; }
	if(pop(&stack)!=15){ return false; }
	if(pop(&stack)!=10){ return false; }
	if(pop(&stack)!=5){ return false; }

	return true;
}


//tests queueing a series of numbers, dequeueing them all, and repeating the process.
bool linearQueueDequeue(){
	List queue = {NULL, NULL};

	enqueue(1, &queue);
	enqueue(2, &queue);
	enqueue(3, &queue);
	enqueue(4, &queue);
	enqueue(5, &queue);

	if(dequeue(&queue)!=1){ return false; }
	if(dequeue(&queue)!=2){ return false; }
	if(dequeue(&queue)!=3){ return false; }
	if(dequeue(&queue)!=4){ return false; }
	if(dequeue(&queue)!=5){ return false; }

	enqueue(1, &queue);
	enqueue(2, &queue);
	enqueue(3, &queue);
	enqueue(4, &queue);
	enqueue(5, &queue);

	if(dequeue(&queue)!=1){ return false; }
	if(dequeue(&queue)!=2){ return false; }
	if(dequeue(&queue)!=3){ return false; }
	if(dequeue(&queue)!=4){ return false; }
	if(dequeue(&queue)!=5){ return false; }

	return true;
}


//tests pushing and popping and then pushing and popping more to ensure functionality of pushing after popping 
bool complexPushPop(){
	List stack = {NULL, NULL};

	push(5, &stack);
	push(10, &stack);
	push(15, &stack);
	push(20, &stack);

	if(pop(&stack)!=20){ return false; }
	if(pop(&stack)!=15){ return false; }

	push(999, &stack);
	push(9999, &stack);

	if(pop(&stack)!=9999){return false;}
	if(pop(&stack)!=999){return false;}
	if(pop(&stack)!=10){return false;}
	if(pop(&stack)!=5){return false;}

	return true;
}


//tests enqueueing and dequeueing and then enqueueing and dequeueing more to ensure functionality of enqueueing after dequeueing 
bool complexQueueDequeue(){
	List queue = {NULL, NULL};

	enqueue(1, &queue);
	enqueue(2, &queue);
	enqueue(3, &queue);

	if(dequeue(&queue)!=1){ return false; }
	if(dequeue(&queue)!=2){ return false; }
	if(dequeue(&queue)!=3){ return false; }

	enqueue(4, &queue);
	enqueue(5, &queue);
	enqueue(6, &queue);

	if(dequeue(&queue)!=4){ return false; }
	if(dequeue(&queue)!=5){ return false; }

	enqueue(7, &queue);

	if(dequeue(&queue)!=6){ return false; }
	if(dequeue(&queue)!=7){ return false; }

	return true;
}
