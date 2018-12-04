#include "ListEntry.h"
#include "List.h"
#include "Tests.c"

/*
 * This is the main method. All it does is call tests.
 */

int main(void) {

	//push and pop tests on a stack
	runTest("Basic push and pop", simplePushPop);
	runTest("Multiple stack simple push/pop", multistackSimplePushPop);
	runTest("Multiple items pushed and then all popped linearly", linearPushPop);
	runTest("Multiple values pushed and popped a few times to test ordering", complexPushPop);

	//enqueue and dequeue tests on a queue
	runTest("Basic queue and dequeue", simpleQueueDequeue);
	runTest("Multiple queue simple queueing and dequeueing", multiqueueSimpleQueueDequeue);
	runTest("Linear queue and dequeue of multiple items", linearQueueDequeue);
	runTest("Multiple values queued and dequeued in various order to test ordering", complexQueueDequeue);
}
